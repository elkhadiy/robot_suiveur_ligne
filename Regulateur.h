/********
* ec2c version 0.67
* context   method = GLOBAL
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
/*--------
Internal structure for the call
--------*/
typedef struct  {
   void* client_data;
   //INPUTS
   _boolean _etat;
   _real _vitesse_rotation;
   _real _Cg;
   _real _Cd;
   //OUTPUTS
   _real _u_d;
   _real _u_g;
   //REGISTERS
   _real M25;
   _boolean M25_nil;
   _boolean M22;
} Regulateur_ctx;
#ifndef _Regulateur_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void Regulateur_I_etat(Regulateur_ctx* ctx, _boolean);
extern void Regulateur_I_vitesse_rotation(Regulateur_ctx* ctx, _real);
extern void Regulateur_I_Cg(Regulateur_ctx* ctx, _real);
extern void Regulateur_I_Cd(Regulateur_ctx* ctx, _real);
/*-------- Reset procedure -----------*/
extern void Regulateur_reset(Regulateur_ctx* ctx);
/*--------Context init --------*/
extern void Regulateur_init(Regulateur_ctx* ctx, void* cdata);
/*-------- Step procedure -----------*/
extern void Regulateur_step(Regulateur_ctx* ctx);
#endif
#endif
