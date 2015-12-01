/********
* ec2c version 0.67
* c file generated for node : Planificateur 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
#define _Planificateur_EC2C_SRC_FILE
#include "Planificateur.h"
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _Obstacle;
   _real _Cg;
   _real _soeuil_obstacle;
   _real _soeuil_noir;
   _real _soeuil_blanc;
   //OUTPUTS
   _boolean _etat;
   //REGISTERS
   _boolean M32;
   _boolean M32_nil;
   _boolean M27;
   _boolean M27_nil;
   _boolean M21;
   _boolean M21_nil;
   _boolean M13;
   _boolean M13_nil;
   _boolean M10;
} Planificateur_ctx;

// Single Static Context
static Planificateur_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Planificateur_I_Obstacle(_real V){
   ctx._Obstacle = V;
}
void Planificateur_I_Cg(_real V){
   ctx._Cg = V;
}
void Planificateur_I_soeuil_obstacle(_real V){
   ctx._soeuil_obstacle = V;
}
void Planificateur_I_soeuil_noir(_real V){
   ctx._soeuil_noir = V;
}
void Planificateur_I_soeuil_blanc(_real V){
   ctx._soeuil_blanc = V;
}
extern void Planificateur_O_etat(_boolean);
#ifdef CKCHECK
extern void Planificateur_BOT_etat();
#endif
/*--------
Internal reset input procedure
--------*/
static void Planificateur_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Planificateur_reset(){
   ctx.M32_nil = _true;
   ctx.M27_nil = _true;
   ctx.M21_nil = _true;
   ctx.M13_nil = _true;
   ctx.M10 = _true;
   Planificateur_reset_input();
}
/*--------
Step procedure
--------*/
void Planificateur_step(){
//LOCAL VARIABLES
   _boolean L9;
   _boolean L14;
   _boolean L8;
   _boolean L20;
   _boolean L22;
   _boolean L19;
   _boolean L26;
   _boolean L25;
   _boolean L28;
   _boolean L24;
   _boolean L23;
   _boolean L18;
   _boolean L17;
   _boolean L16;
   _boolean L15;
   _boolean L7;
   _boolean L6;
   _boolean L31;
   _boolean L30;
   _boolean L35;
   _boolean L34;
   _boolean L33;
   _boolean L29;
   _boolean L5;
   _boolean T32;
   _boolean T27;
   _boolean T21;
   _boolean T13;
//CODE
   if (ctx.M10) {
      L9 = _false;
   } else {
      L9 = ctx.M13;
   }
   L14 = (ctx._Cg >= ctx._soeuil_blanc);
   L8 = (L9 || L14);
   if (ctx.M10) {
      L20 = _false;
   } else {
      L20 = ctx.M21;
   }
   L22 = (ctx._Cg <= ctx._soeuil_noir);
   L19 = (L20 || L22);
   if (ctx.M10) {
      L26 = _false;
   } else {
      L26 = ctx.M27;
   }
   L25 = (! L26);
   L28 = (ctx._Obstacle >= ctx._soeuil_obstacle);
   L24 = (L25 && L28);
   L23 = (! L24);
   L18 = (L19 && L23);
   L17 = (! L18);
   L16 = (L17 || L24);
   L15 = (! L16);
   L7 = (L8 && L15);
   L6 = (! L7);
   if (ctx.M10) {
      L31 = _false;
   } else {
      L31 = ctx.M32;
   }
   L30 = (L31 || L28);
   L35 = (! L9);
   L34 = (L35 && L7);
   L33 = (! L34);
   L29 = (L30 && L33);
   L5 = (L6 && L29);
   Planificateur_O_etat(L5);
   T32 = L29;
   T27 = L28;
   T21 = L18;
   T13 = L7;
   ctx.M32 = T32;
   ctx.M32_nil = _false;
   ctx.M27 = T27;
   ctx.M27_nil = _false;
   ctx.M21 = T21;
   ctx.M21_nil = _false;
   ctx.M13 = T13;
   ctx.M13_nil = _false;
   ctx.M10 = ctx.M10 && !(_true);
}
