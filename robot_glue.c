
/*

Exemple de code glue pour deux tâches périodiques HARMONIQUES
AVEC COMMUNICATION

- une supposée rapide et frequente et qui doit s'appeler HighTask
  qui fait tourner un noeud lustre "high"
- une supposée lente et moins fréquente et qui doit s'appeler LowTask
  qui fait tourner un noeud lustre "low"
- les périodes doivent être spécifiés dans kernel_cfg.h avec les macros :
     HIGH_PERIOD
     LOW_PERIOD
  qui doivent être harmoniques : LOW_PERIOD = n * HIGH_PERIOD
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
DeclareTask(HighTask);
DeclareTask(LowTask);

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
      ICI : on peut mettre du code qui sera appelÃ© automatiquement
            Ã  l'initialisation de la brique
      (ne rien mettre si pas nÃ©cessaire)
   */
}

void ecrobot_device_terminate() {
   /*
      ICI : on peut mettre du code qui sera appelÃ© automatiquement
            Ã  la l'extinction de la brique
      (ne rien mettre si pas nÃ©cessaire)
   */
}

/**** CODE GLUE, A MODIFIER/ADAPTER */
/*

REMARQUE :

On utilise l'option "-ctx-static", donc pas de parametres aux "methodes" Lustre

*/


/*------------------------------
	Déclarations
--------------------------------
  On met typiquement ici les déclarations
de variables partagées, de fonctions
accessoires etc.
------------------------------*/

int soeuil_obstacle = 15;
_boolean etat; // Communication entre Planificateur et Regulateur

#define CG_PORT NXT_PORT_S4
#define CD_PORT NXT_PORT_S1
#define OBSTACLE_PORT NXT_PORT_S3

#define C_in_min 0
#define C_in_max 1023
#define C_out_min 0
#define C_out_max 100

int soeuil_noir = 50, soeuil_blanc = 50,
	Cg_black, Cg_white,
	Cd_black, Cd_white;

#define VITESSE_DEMI_TOUR 0.5
void show_var(char* what, int line, int var);
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//Le ratio des periodes :
//(le compilateur se charge du calcul statiquement)
#define PRATIO ((int)(REGULATEUR_PERIOD/PLANIFICATEUR_PERIOD))

/*------------------------------
	Initialisations
--------------------------------
  On doit se débrouiller pour que NOS initialisations
soient effectuées. Comme on ne veut PAS TOUCHER
une seule ligne au code OSEK, on utilise un kernel_cfg.c
modifié, où une nouvelle fonction, "usr_init()", est
appelée à l'initialisation du système.
Cette fonction doit être définie ici.
------------------------------*/



void usr_init(void) {
	Planificateur_init();
	Regulateur_init();
	etat = 0;
	// TODO: Calibrage
	display_goto_xy(0,0);
	display_string("---Calibrage---");
	ecrobot_set_light_sensor_active(CG_PORT);
	ecrobot_set_light_sensor_active(CD_PORT);
	ecrobot_init_sonar_sensor(OBSTACLE_PORT);

	int cd_val, cg_val;

	while (!ecrobot_is_ENTER_button_pressed()) {
		display_goto_xy(0,1);
		display_string("White threshold");
		cg_val = ecrobot_get_light_sensor(CG_PORT);
		show_var("CG = ", 2, cg_val);
		cd_val = ecrobot_get_light_sensor(CD_PORT);
		show_var("CD = ", 3, cd_val);
	}

	while(ecrobot_is_ENTER_button_pressed()) {
		display_goto_xy(0,4);
		display_string("Waiting for button release");
	}

	Cd_white = cd_val;
	Cg_white = cg_val;

	while (!ecrobot_is_ENTER_button_pressed()) {
		display_goto_xy(0,4);
		display_string("Black threshold");
		cg_val = ecrobot_get_light_sensor(CG_PORT);
		show_var("CG = ", 5, cg_val);
		cd_val = ecrobot_get_light_sensor(CD_PORT);
		show_var("CD = ", 6, cd_val);
	}
	

	while(ecrobot_is_ENTER_button_pressed()) {
		display_goto_xy(0,7);
		display_string("release btn");
	}

	Cd_black = cd_val;
	Cg_black = cg_val;

	display_clear(1);
	display_goto_xy(0,4);
	display_string("DONE!");

	systick_wait_ms(1500);

	display_clear(1);

}

/* Procédure de sortie */
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
	show_var("etat", 3, val);
	etat = val;
}

#define DIV 2
#define MAX_POW 100

void Regulateur_O_u_d(_real val){
	int pow = (val*100/DIV);
	if (pow < -MAX_POW) pow = -MAX_POW;
	if (pow > MAX_POW) pow = MAX_POW;
	show_var("u_d", 4, pow);
	ecrobot_set_motor_speed(NXT_PORT_A, pow);
}

void Regulateur_O_u_g(_real val){
	int pow = (val*100/DIV);
	if (pow < -MAX_POW) pow = -MAX_POW;
	if (pow > MAX_POW) pow = MAX_POW;
	show_var("u_g", 5, pow);
	ecrobot_set_motor_speed(NXT_PORT_B, pow);
}

/*------------------------------
  Definitions des taches 
--------------------------------
Elles doivent :
- être déclarées par la macro TASK
- le code doit se terminer par la macro TerminateTask()
------------------------------*/


TASK(LowTask) {
	/* Positionnement des entrées */
	_real Cg = 100 - map(ecrobot_get_light_sensor(CG_PORT), Cg_white, Cg_black, C_out_min, C_out_max);
	if (Cg > 100) Cg = 100;
	if (Cg < 0) Cg = 0;
	_real obstacle =  ecrobot_get_sonar_sensor(OBSTACLE_PORT); 
	show_var("obs = ", 6, obstacle);

	Planificateur_I_Obstacle ( 50 - obstacle );
	Planificateur_I_Cg ( Cg );
	Planificateur_I_soeuil_obstacle( 50 - soeuil_obstacle );
	Planificateur_I_soeuil_noir( soeuil_noir );
	Planificateur_I_soeuil_blanc( soeuil_blanc );

	/* Appel du step */
	Planificateur_step();

	/* OSEK : FINALISATION TASK, NE PAS TOUCHER */
	TerminateTask();
}
	
	

TASK(HighTask) {
	/* Positionnement des entrées */
	_real Cg = 100 - map(ecrobot_get_light_sensor(CG_PORT), Cg_white, Cg_black, C_out_min, C_out_max);
	if (Cg > 100) Cg = 100;
	if (Cg < 0) Cg = 0;
	_real Cd = 100 - map(ecrobot_get_light_sensor(CD_PORT), Cd_white, Cd_black, C_out_min, C_out_max);
	if (Cd > 100) Cd = 100;
	if (Cd < 0) Cd = 0;
	show_var("Cg = ", 1, Cg);
	show_var("Cd = ", 2, Cd);
	Regulateur_I_etat(etat);
	Regulateur_I_vitesse_rotation(VITESSE_DEMI_TOUR);
	Regulateur_I_Cg( Cg );
	Regulateur_I_Cd( Cd );

	/* Appel du step */
	Regulateur_step();

	/* OSEK : FINALISATION TASK, NE PAS TOUCHER */
	TerminateTask();
}

