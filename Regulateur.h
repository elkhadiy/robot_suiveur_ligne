/********
* ec2c version 0.67
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : Regulateur 
* to be used with : Regulateur.c 
********/
#ifndef _Regulateur_EC2C_H_FILE
#define _Regulateur_EC2C_H_FILE
/* This program needs external declarations */
#include "Regulateur_ext.h"
/*-------- Predefined types ---------*/
#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif
/*--------- Pragmas ----------------*/
//MODULE: Regulateur 4 2
//IN: _boolean etat
//IN: _real vitesse_rotation
//IN: _real Cg
//IN: _real Cd
//OUT: _real u_d
//OUT: _real u_g
#ifndef _Regulateur_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void Regulateur_I_etat(_boolean);
extern void Regulateur_I_vitesse_rotation(_real);
extern void Regulateur_I_Cg(_real);
extern void Regulateur_I_Cd(_real);
/*-------- Reset procedure -----------*/
extern void Regulateur_reset();
/*--------Context init = context reset --------*/
#define Regulateur_init Regulateur_reset
/*-------- Step procedure -----------*/
extern void Regulateur_step();
#endif
#endif
