/********
* ec2c version 0.67
* c file generated for node : Controller 
* context   method = HEAP
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#include <stdlib.h>
#include <string.h>
#define _Controller_EC2C_SRC_FILE
#include "Controller.h"
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
   void* client_data;
   //INPUTS
   _real _Cg;
   _real _Cd;
   _real _obstacle;
   _real _vitesse_rotation;
   _real _soeuil_obstacle;
   _real _soeuil_noir;
   _real _soeuil_blanc;
   //OUTPUTS
   _real _u_d;
   _real _u_g;
   //REGISTERS
   _real M57;
   _boolean M57_nil;
   _boolean M35;
   _boolean M35_nil;
   _boolean M30;
   _boolean M30_nil;
   _boolean M24;
   _boolean M24_nil;
   _boolean M16;
   _boolean M16_nil;
   _boolean M13;
} Controller_ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Controller_I_Cg(Controller_ctx* ctx, _real V){
   ctx->_Cg = V;
}
void Controller_I_Cd(Controller_ctx* ctx, _real V){
   ctx->_Cd = V;
}
void Controller_I_obstacle(Controller_ctx* ctx, _real V){
   ctx->_obstacle = V;
}
void Controller_I_vitesse_rotation(Controller_ctx* ctx, _real V){
   ctx->_vitesse_rotation = V;
}
void Controller_I_soeuil_obstacle(Controller_ctx* ctx, _real V){
   ctx->_soeuil_obstacle = V;
}
void Controller_I_soeuil_noir(Controller_ctx* ctx, _real V){
   ctx->_soeuil_noir = V;
}
void Controller_I_soeuil_blanc(Controller_ctx* ctx, _real V){
   ctx->_soeuil_blanc = V;
}
extern void Controller_O_u_d(void* cdata, _real);
extern void Controller_O_u_g(void* cdata, _real);
#ifdef CKCHECK
extern void Controller_BOT_u_d(void* cdata);
extern void Controller_BOT_u_g(void* cdata);
#endif
/*--------
Internal reset input procedure
--------*/
static void Controller_reset_input(Controller_ctx* ctx){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Controller_reset(Controller_ctx* ctx){
   ctx->M57_nil = _true;
   ctx->M35_nil = _true;
   ctx->M30_nil = _true;
   ctx->M24_nil = _true;
   ctx->M16_nil = _true;
   ctx->M13 = _true;
   Controller_reset_input(ctx);
}
/*--------
Copy the value of an internal structure
--------*/
void Controller_copy_ctx(Controller_ctx* dest, Controller_ctx* src){
   memcpy((void*)dest, (void*)src, sizeof(Controller_ctx));
}
/*--------
Dynamic allocation of an internal structure
--------*/
Controller_ctx* Controller_new_ctx(void* cdata){
   Controller_ctx* ctx = (Controller_ctx*)calloc(1, sizeof(Controller_ctx));
   ctx->client_data = cdata;
   Controller_reset(ctx);
   return ctx;
}
/*--------
Step procedure
--------*/
void Controller_step(Controller_ctx* ctx){
//LOCAL VARIABLES
   _boolean L12;
   _boolean L17;
   _boolean L11;
   _boolean L23;
   _boolean L25;
   _boolean L22;
   _boolean L29;
   _boolean L28;
   _boolean L31;
   _boolean L27;
   _boolean L26;
   _boolean L21;
   _boolean L20;
   _boolean L19;
   _boolean L18;
   _boolean L10;
   _boolean L9;
   _boolean L34;
   _boolean L33;
   _boolean L38;
   _boolean L37;
   _boolean L36;
   _boolean L32;
   _boolean L8;
   _real L40;
   _real L51;
   _real L54;
   _real L50;
   _real L48;
   _real L55;
   _real L47;
   _real L45;
   _real L58;
   _real L44;
   _real L65;
   _boolean L64;
   _real L66;
   _real L63;
   _real L62;
   _real L69;
   _real L67;
   _real L61;
   _real L60;
   _real L43;
   _real L39;
   _real L7;
   _real L73;
   _real L72;
   _real L76;
   _real L75;
   _real L74;
   _real L71;
   _real T57;
   _boolean T35;
   _boolean T30;
   _boolean T24;
   _boolean T16;
//CODE
   if (ctx->M13) {
      L12 = _false;
   } else {
      L12 = ctx->M16;
   }
   L17 = (ctx->_Cg >= ctx->_soeuil_blanc);
   L11 = (L12 || L17);
   if (ctx->M13) {
      L23 = _false;
   } else {
      L23 = ctx->M24;
   }
   L25 = (ctx->_Cg <= ctx->_soeuil_noir);
   L22 = (L23 || L25);
   if (ctx->M13) {
      L29 = _false;
   } else {
      L29 = ctx->M30;
   }
   L28 = (! L29);
   L31 = (ctx->_obstacle >= ctx->_soeuil_obstacle);
   L27 = (L28 && L31);
   L26 = (! L27);
   L21 = (L22 && L26);
   L20 = (! L21);
   L19 = (L20 || L27);
   L18 = (! L19);
   L10 = (L11 && L18);
   L9 = (! L10);
   if (ctx->M13) {
      L34 = _false;
   } else {
      L34 = ctx->M35;
   }
   L33 = (L34 || L31);
   L38 = (! L12);
   L37 = (L38 && L10);
   L36 = (! L37);
   L32 = (L33 && L36);
   L8 = (L9 && L32);
   L40 = (1.000000 / 2.000000);
   L51 = (pi / 200.000000);
   L54 = (ctx->_Cd - ctx->_Cg);
   L50 = (L51 * L54);
   L48 = (0.002000 * L50);
   if (ctx->M13) {
      L55 = 0.000000;
   } else {
      L55 = ctx->M57;
   }
   L47 = (L48 + L55);
   L45 = (ki_teta * L47);
   L58 = (kp_teta * L50);
   L44 = (L45 + L58);
   L65 = (2.000000 * L44);
   L64 = (L65 < 0.000000);
   L66 = (- L65);
   if (L64) {
      L63 = L66;
   } else {
      L63 = L65;
   }
   L62 = (- L63);
   L69 = (ctx->_Cd + ctx->_Cg);
   L67 = (0.005000 * L69);
   L61 = (L62 + L67);
   L60 = (2.000000 * L61);
   L43 = (L44 + L60);
   L39 = (L40 * L43);
   if (L8) {
      L7 = ctx->_vitesse_rotation;
   } else {
      L7 = L39;
   }
   Controller_O_u_d(ctx->client_data, L7);
   L73 = (- 1.000000);
   L72 = (L73 * ctx->_vitesse_rotation);
   L76 = (- L44);
   L75 = (L76 + L60);
   L74 = (L40 * L75);
   if (L8) {
      L71 = L72;
   } else {
      L71 = L74;
   }
   Controller_O_u_g(ctx->client_data, L71);
   T57 = L47;
   T35 = L32;
   T30 = L31;
   T24 = L21;
   T16 = L10;
   ctx->M57 = T57;
   ctx->M57_nil = _false;
   ctx->M35 = T35;
   ctx->M35_nil = _false;
   ctx->M30 = T30;
   ctx->M30_nil = _false;
   ctx->M24 = T24;
   ctx->M24_nil = _false;
   ctx->M16 = T16;
   ctx->M16_nil = _false;
   ctx->M13 = ctx->M13 && !(_true);
}
