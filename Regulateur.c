/********
* ec2c version 0.67
* c file generated for node : Regulateur 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _Regulateur_EC2C_SRC_FILE
#include "Regulateur.h"
/*--------
 * the following ``constants'' must be defined:
extern _real pi;
extern _real kp_teta;
extern _real ki_teta;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
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

// Single Static Context
static Regulateur_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Regulateur_I_etat(_boolean V){
   ctx._etat = V;
}
void Regulateur_I_vitesse_rotation(_real V){
   ctx._vitesse_rotation = V;
}
void Regulateur_I_Cg(_real V){
   ctx._Cg = V;
}
void Regulateur_I_Cd(_real V){
   ctx._Cd = V;
}
extern void Regulateur_O_u_d(_real);
extern void Regulateur_O_u_g(_real);
#ifdef CKCHECK
extern void Regulateur_BOT_u_d();
extern void Regulateur_BOT_u_g();
#endif
/*--------
Internal reset input procedure
--------*/
static void Regulateur_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Regulateur_reset(){
   ctx.M25_nil = _true;
   ctx.M22 = _true;
   Regulateur_reset_input();
}
/*--------
Step procedure
--------*/
void Regulateur_step(){
//LOCAL VARIABLES
   _real L6;
   _real L17;
   _real L20;
   _real L16;
   _real L14;
   _real L21;
   _real L13;
   _real L11;
   _real L26;
   _real L10;
   _real L33;
   _boolean L32;
   _real L34;
   _real L31;
   _real L30;
   _real L37;
   _real L35;
   _real L29;
   _real L28;
   _real L9;
   _real L5;
   _real L4;
   _real L41;
   _real L40;
   _real L44;
   _real L43;
   _real L42;
   _real L39;
   _real T25;
//CODE
   L6 = (1.000000 / 2.000000);
   L17 = (pi / 200.000000);
   L20 = (ctx._Cd - ctx._Cg);
   L16 = (L17 * L20);
   L14 = (0.002000 * L16);
   if (ctx.M22) {
      L21 = 0.000000;
   } else {
      L21 = ctx.M25;
   }
   L13 = (L14 + L21);
   L11 = (ki_teta * L13);
   L26 = (kp_teta * L16);
   L10 = (L11 + L26);
   L33 = (2.000000 * L10);
   L32 = (L33 < 0.000000);
   L34 = (- L33);
   if (L32) {
      L31 = L34;
   } else {
      L31 = L33;
   }
   L30 = (- L31);
   L37 = (ctx._Cd + ctx._Cg);
   L35 = (0.005000 * L37);
   L29 = (L30 + L35);
   L28 = (2.000000 * L29);
   L9 = (L10 + L28);
   L5 = (L6 * L9);
   if (ctx._etat) {
      L4 = ctx._vitesse_rotation;
   } else {
      L4 = L5;
   }
   Regulateur_O_u_d(L4);
   L41 = (- 1.000000);
   L40 = (L41 * ctx._vitesse_rotation);
   L44 = (- L10);
   L43 = (L44 + L28);
   L42 = (L6 * L43);
   if (ctx._etat) {
      L39 = L40;
   } else {
      L39 = L42;
   }
   Regulateur_O_u_g(L39);
   T25 = L13;
   ctx.M25 = T25;
   ctx.M25_nil = _false;
   ctx.M22 = ctx.M22 && !(_true);
}
