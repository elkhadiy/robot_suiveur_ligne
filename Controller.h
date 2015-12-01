/********
* ec2c version 0.67
* context   method = HEAP
* ext call  method = PROCEDURES
* c header file generated for node : Controller 
* to be used with : Controller.c 
********/
#ifndef _Controller_EC2C_H_FILE
#define _Controller_EC2C_H_FILE
/* This program needs external declarations */
#include "Controller_ext.h"
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
//MODULE: Controller 7 2
//IN: _real Cg
//IN: _real Cd
//IN: _real obstacle
//IN: _real vitesse_rotation
//IN: _real soeuil_obstacle
//IN: _real soeuil_noir
//IN: _real soeuil_blanc
//OUT: _real u_d
//OUT: _real u_g
#ifndef _Controller_EC2C_SRC_FILE
/*--------Context type -------------*/
struct Controller_ctx;
/*-------- Input procedures -------------*/
extern void Controller_I_Cg(struct Controller_ctx* ctx, _real);
extern void Controller_I_Cd(struct Controller_ctx* ctx, _real);
extern void Controller_I_obstacle(struct Controller_ctx* ctx, _real);
extern void Controller_I_vitesse_rotation(struct Controller_ctx* ctx, _real);
extern void Controller_I_soeuil_obstacle(struct Controller_ctx* ctx, _real);
extern void Controller_I_soeuil_noir(struct Controller_ctx* ctx, _real);
extern void Controller_I_soeuil_blanc(struct Controller_ctx* ctx, _real);
/*-------- Reset procedure -----------*/
extern void Controller_reset(struct Controller_ctx* ctx);
/*--------Context copy -------------*/
extern void Controller_copy_ctx(struct Controller_ctx* dest, struct 
Controller_ctx* src);
/*--------Context allocation --------*/
extern struct Controller_ctx* Controller_new_ctx(void* client_data);
/*-------- Step procedure -----------*/
extern void Controller_step(struct Controller_ctx* ctx);
#endif
#endif
