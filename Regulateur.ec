const
  pi : real;
  kp_teta : real;
  ki_teta : real;
  
node Regulateur
  (etat: bool;
  vitesse_rotation: real;
  Cg: real;
  Cd: real)
returns
  (u_d: real;
  u_g: real);

var
  V12_w_001: real;
  V13_w_002: real;
  V14_w_003: real;
  V17_w_006: real;
  V19_w_008: real;
  V108_w_004: real;
  V141_w_003: real;
  V142_w_004: real;
  V143_w_005: real;
  V144_w_006: real;
  V145_w_007: real;
  V146_w_008: real;
  V147_w_009: real;
  V148_w_011: real;
  V149_w_012: real;
  V150_w_013: real;
  V151_w_014: real;
  V152_w_015: real;
  V153_w_016: real;

let
  u_d = (if etat then vitesse_rotation else V14_w_003);
  u_g = (if etat then V12_w_001 else V13_w_002);
  V12_w_001 = (-1.000000 * vitesse_rotation);
  V13_w_002 = ((1.000000 / 2.000000) * V150_w_013);
  V14_w_003 = ((1.000000 / 2.000000) * V151_w_014);
  V17_w_006 = ((pi / 200.000000) * V108_w_004);
  V19_w_008 = (Cd + Cg);
  V108_w_004 = (Cd - Cg);
  V141_w_003 = (0.000000 -> (pre V142_w_004));
  V142_w_004 = (V143_w_005 + V141_w_003);
  V143_w_005 = (0.002000 * V17_w_006);
  V144_w_006 = (V153_w_016 + V152_w_015);
  V145_w_007 = ((-V147_w_009) + V148_w_011);
  V146_w_008 = (2.000000 * V145_w_007);
  V147_w_009 = (if (V149_w_012 < 0.000000) then (-V149_w_012) else V149_w_012);
  V148_w_011 = (0.005000 * V19_w_008);
  V149_w_012 = (2.000000 * V144_w_006);
  V150_w_013 = ((-V144_w_006) + V146_w_008);
  V151_w_014 = (V144_w_006 + V146_w_008);
  V152_w_015 = (kp_teta * V17_w_006);
  V153_w_016 = (ki_teta * V142_w_004);
tel

