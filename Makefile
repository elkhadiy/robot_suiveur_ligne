
##---------------------------------
## Un exemple d'appli exploitant
## les briques de nxtOSEK
##
## Ce makefile est � patcher pour
## une appli particuli�re.
## Il inclue un makefile g�n�rique
## qu'on ne doit normalement pas toucher.
##---------------------------------
## Nom pour l'appli, � d�finir
TARGET=Robot

## Le(s) r�pertoires o� se trouvent les
## fichiers c utilisateurs
USR_PATH=.

## Renseigner ici des options de links si besoin
USR_LIBS=

##--------------------------------------------
## Les fichiers config pour osek :
##
##     kernel_cfg.c  et   kernel_id.h
##
##    Dans le "vrai" nxtOSEK, ces fichiers sont
## sont obtenus par compilation d'une description
## dans le langage "oil"
##    Ici, ils sont donn�s directement, et sont
## valables pour des applications avec 2 t�ches :
## - 1 rapide prioritaire
## - 1 lente
##    Les periodes sont en dur
##  dans kernel_cfg.c -> c'est pas tres beau

## ---------------------------------
## Le(s) fichiers utilisateur
## ---------------------------------
USR_CFILES=\
   Regulateur.c \
   Planificateur.c \
   robot_glue.c \

## --------------------------------
## Le makefile generique pour OSEK
## (la varibale MDL2LUS2OSEK doit etre definie)
## --------------------------------
include $(MDL2LUS2OSEK)/generic.mak


## On met � la fin les r�gles pour les USR_CFILES


## Compilation Lustre->C
Regulateur.c: Regulateur.lus
	lus2c Regulateur.lus Regulateur -ctx-static

Regulateur.lus: ExRobotAndEnvironmentController.mdl
	mdl2lus ExRobotAndEnvironmentController.mdl -system Regulateur

Planificateur.c: Planificateur.lus
	lus2c Planificateur.lus Planificateur -ctx-static

Planificateur.lus: ExRobotAndEnvironmentController.mdl
	mdl2lus ExRobotAndEnvironmentController.mdl -system Planificateur


clear: clean
	rm -f *.xml Regulateur.lus Regulateur.c Regulateur.h Planificateur.lus Planificateur.c Planificateur.h *.ec *.mws
