/********
* ec2c version 0.67
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : Planificateur 
* to be used with : Planificateur.c 
********/
#ifndef _Planificateur_EC2C_H_FILE
#define _Planificateur_EC2C_H_FILE
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
//MODULE: Planificateur 5 1
//IN: _real Obstacle
//IN: _real Cg
//IN: _real soeuil_obstacle
//IN: _real soeuil_noir
//IN: _real soeuil_blanc
//OUT: _boolean etat
#ifndef _Planificateur_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void Planificateur_I_Obstacle(_real);
extern void Planificateur_I_Cg(_real);
extern void Planificateur_I_soeuil_obstacle(_real);
extern void Planificateur_I_soeuil_noir(_real);
extern void Planificateur_I_soeuil_blanc(_real);
/*-------- Reset procedure -----------*/
extern void Planificateur_reset();
/*--------Context init = context reset --------*/
#define Planificateur_init Planificateur_reset
/*-------- Step procedure -----------*/
extern void Planificateur_step();
#endif
#endif
