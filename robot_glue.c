
/*

Exemple de code glue pour deux t�ches p�riodiques HARMONIQUES
AVEC COMMUNICATION

- une suppos�e rapide et frequente et qui doit s'appeler HighTask
  qui fait tourner un noeud lustre "high"
- une suppos�e lente et moins fr�quente et qui doit s'appeler LowTask
  qui fait tourner un noeud lustre "low"
- les p�riodes doivent �tre sp�cifi�s dans kernel_cfg.h avec les macros :
     HIGH_PERIOD
     LOW_PERIOD
  qui doivent �tre harmoniques : LOW_PERIOD = n * HIGH_PERIOD
*/

#include "kernel.h"
#include "periodes.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

/**** CODE GLUE, A MODIFIER/ADAPTER */
/* Ici : inclusion du header Lustre */
#include <string.h>  /* a cause du strlen plus bas */
#include "Regulateur.h"
#include "Planificateur.h"
#include "Planificateur_ext.h"

/***** OSEK : NE PAS MODIFIER */
DeclareCounter(SysTimerCnt);
DeclareResource(lcd);
DeclareTask(RegulateurTask);
DeclareTask(PlanificateurTask);

/* LEJOS OSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void)
{
	StatusType ercd; /* Increment OSEK Alarm System Timer Count */
	ercd = SignalCounter( SysTimerCnt );
	if( ercd != E_OK ){
		ShutdownOS( ercd );
	}
}
/******* FIN OSEK */

/* Initialisation et finalisations OSEK */
void ecrobot_device_initialize() {
   /*
      ICI : on peut mettre du code qui sera appelé automatiquement
            à l'initialisation de la brique
      (ne rien mettre si pas nécessaire)
   */
}

void ecrobot_device_terminate() {
   /*
      ICI : on peut mettre du code qui sera appelé automatiquement
            à la l'extinction de la brique
      (ne rien mettre si pas nécessaire)
   */
}

/**** CODE GLUE, A MODIFIER/ADAPTER */
/*

REMARQUE :

On utilise l'option "-ctx-static", donc pas de parametres aux "methodes" Lustre

*/


/*------------------------------
	D�clarations
--------------------------------
  On met typiquement ici les d�clarations
de variables partag�es, de fonctions
accessoires etc.
------------------------------*/

/*
	Pour g�rer les communications :
*/

/*
_integer H2L;       // buffer High -> Low
_integer L2H[2];    // double-buffer Low -> High
_integer L2Hindex;  // 0 ou 1 : indique dans quelle
                    // case du double-buffer Low doit �crire

_integer Hcpt;      // compte les "instants" High
*/
_boolean etat; // Communication entre Planificateur et Regulateur


//Le ratio des periodes :
//(le compilateur se charge du calcul statiquement)
#define PRATIO ((int)(REGULATEUR_PERIOD/PLANIFICATEUR_PERIOD))

/*------------------------------
	Initialisations
--------------------------------
  On doit se d�brouiller pour que NOS initialisations
soient effectu�es. Comme on ne veut PAS TOUCHER
une seule ligne au code OSEK, on utilise un kernel_cfg.c
modifi�, o� une nouvelle fonction, "usr_init()", est
appel�e � l'initialisation du syst�me.
Cette fonction doit �tre d�finie ici.
------------------------------*/

void usr_init(void) {
	Planificateur_init();
	Regulateur_init();
	etat = 0;
	// TODO: Calibrage

	//Index de la case o� L ecrira la premiere fois
	//L2Hindex = 0;
	//Il faut initialiser le registre o� H lira la premiere fois
	//c'est-a-dire celui ou L n'ecrit pas !
	//L2H[1] = 0;
}

/* Proc�dure de sortie */
/**
 * Affiche a l'ecran "what var"
 */
void show_var(char* what, int line, int var) {
   GetResource(lcd);
   display_goto_xy(0, line);
   display_string(what);
   display_goto_xy(strlen(what)+1, line);
   display_int(var, 5);
   display_update();
   ReleaseResource(lcd);
}


void Planificateur_O_etat(_integer val){
	show_var("etat", 1, val);
	etat = val;
}

void Regulateur_O_u_d(_integer val){
	show_var("u_d", 4, val);
}

void Regulateur_O_u_g(_integer val){
	//Communication L -> H
	//�crit dans la case du buffer d�sign�e par L2Hindex :
	//L2H[L2Hindex] = val;
	show_var("u_g", 5, val);
}

/*------------------------------
  Definitions des taches 
--------------------------------
Elles doivent :
- �tre d�clar�es par la macro TASK
- le code doit se terminer par la macro TerminateTask()
------------------------------*/


TASK(PlanificateurTask) {
	/* Positionnement des entr�es */
	Planificateur_I_Obstacle ( ecrobot_get_touch_sensor(NXT_PORT_S1) );
	Planificateur_I_Cg ( ecrobot_get_touch_sensor(NXT_PORT_S1) );
	Planificateur_I_soeuil_obstacle( ecrobot_get_touch_sensor(NXT_PORT_S1) );
	Planificateur_I_soeuil_noir( ecrobot_get_touch_sensor(NXT_PORT_S1) );
	Planificateur_I_soeuil_blanc( ecrobot_get_touch_sensor(NXT_PORT_S1) );

	/* Appel du step */
	Planificateur_step();

	/* O� on en est avec la tache Low ? */
	if (Hcpt  == 0) {
		/*
			Low va d�marer un cycle juste apres High ...
		   on "swape"  le double buffer
		*/
		L2Hindex = !L2Hindex;
	}
	/* et on fait avancer le compteur ... */
	Hcpt = (Hcpt+1) % PRATIO;
	
	/* OSEK : FINALISATION TASK, NE PAS TOUCHER */
	TerminateTask();
}
	
	

TASK(RegulateurTask) {

	/* Positionnement des entr�es */
	low_I_e( ecrobot_get_touch_sensor(NXT_PORT_S2) );

	// Com H -> L, on lit toujours la valeur courante de H2L
	low_I_h2l(H2L);

	/* Appel du step */
	low_step();

	/* OSEK : FINALISATION TASK, NE PAS TOUCHER */
	TerminateTask();
}

