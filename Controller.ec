const
  pi : real;
  kp_teta : real;
  ki_teta : real;
  
node Controller
  (Cg: real;
  Cd: real;
  obstacle: real;
  vitesse_rotation: real;
  soeuil_obstacle: real;
  soeuil_noir: real;
  soeuil_blanc: real)
returns
  (u_d: real;
  u_g: real);

var
  V19_w_005: bool;
  V21_w_007: real;
  V23_w_009: real;
  V24_w_010: real;
  V27_w_013: real;
  V29_w_015: real;
  V307_w_005: bool;
  V308_w_006: bool;
  V309_w_007: bool;
  V310_w_008: bool;
  V311_w_009: bool;
  V312_w_011: bool;
  V313_w_001: bool;
  V314_w_002: bool;
  V315_w_002: bool;
  V316_w_003: bool;
  V317_w_004: bool;
  V318_w_001: bool;
  V319_w_002: bool;
  V320_w_004: bool;
  V321_w_005: bool;
  V322_w_006: bool;
  V323_w_007: bool;
  V324_w_009: bool;
  V325_w_002: bool;
  V326_w_003: bool;
  V327_w_004: bool;
  V328_w_002: bool;
  V329_w_003: bool;
  V330_w_004: bool;
  V352_w_004: real;
  V374_w_003: real;
  V375_w_004: real;
  V376_w_005: real;
  V377_w_006: real;
  V378_w_007: real;
  V379_w_008: real;
  V380_w_009: real;
  V381_w_011: real;
  V382_w_012: real;
  V383_w_013: real;
  V384_w_014: real;
  V385_w_015: real;
  V386_w_016: real;

let
  u_d = (if V19_w_005 then vitesse_rotation else V24_w_010);
  u_g = (if V19_w_005 then V21_w_007 else V23_w_009);
  V19_w_005 = (V311_w_009 and V308_w_006);
  V21_w_007 = (-1.000000 * vitesse_rotation);
  V23_w_009 = ((1.000000 / 2.000000) * V383_w_013);
  V24_w_010 = ((1.000000 / 2.000000) * V384_w_014);
  V27_w_013 = ((pi / 200.000000) * V352_w_004);
  V29_w_015 = (Cd + Cg);
  V307_w_005 = (V325_w_002 and V326_w_003);
  V308_w_006 = (V315_w_002 and V316_w_003);
  V309_w_007 = (V314_w_002 and V307_w_005);
  V310_w_008 = (obstacle >= soeuil_obstacle);
  V311_w_009 = (not V307_w_005);
  V312_w_011 = (V319_w_002 and V310_w_008);
  V313_w_001 = (false -> (pre V307_w_005));
  V314_w_002 = (not V313_w_001);
  V315_w_002 = (V317_w_004 or V310_w_008);
  V316_w_003 = (not V309_w_007);
  V317_w_004 = (false -> (pre V308_w_006));
  V318_w_001 = (false -> (pre V310_w_008));
  V319_w_002 = (not V318_w_001);
  V320_w_004 = (V324_w_009 or V312_w_011);
  V321_w_005 = (Cg >= soeuil_blanc);
  V322_w_006 = (Cg <= soeuil_noir);
  V323_w_007 = (V328_w_002 and V329_w_003);
  V324_w_009 = (not V323_w_007);
  V325_w_002 = (V327_w_004 or V321_w_005);
  V326_w_003 = (not V320_w_004);
  V327_w_004 = (false -> (pre V307_w_005));
  V328_w_002 = (V330_w_004 or V322_w_006);
  V329_w_003 = (not V312_w_011);
  V330_w_004 = (false -> (pre V323_w_007));
  V352_w_004 = (Cd - Cg);
  V374_w_003 = (0.000000 -> (pre V375_w_004));
  V375_w_004 = (V376_w_005 + V374_w_003);
  V376_w_005 = (0.002000 * V27_w_013);
  V377_w_006 = (V386_w_016 + V385_w_015);
  V378_w_007 = ((-V380_w_009) + V381_w_011);
  V379_w_008 = (2.000000 * V378_w_007);
  V380_w_009 = (if (V382_w_012 < 0.000000) then (-V382_w_012) else V382_w_012);
  V381_w_011 = (0.005000 * V29_w_015);
  V382_w_012 = (2.000000 * V377_w_006);
  V383_w_013 = ((-V377_w_006) + V379_w_008);
  V384_w_014 = (V377_w_006 + V379_w_008);
  V385_w_015 = (kp_teta * V27_w_013);
  V386_w_016 = (ki_teta * V375_w_004);
tel

