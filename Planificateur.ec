node Planificateur
  (Obstacle: real;
  Cg: real;
  soeuil_obstacle: real;
  soeuil_noir: real;
  soeuil_blanc: real)
returns
  (etat: bool);

var
  V13_w_005: bool;
  V14_w_006: bool;
  V15_w_007: bool;
  V16_w_008: bool;
  V17_w_009: bool;
  V19_w_011: bool;
  V152_w_001: bool;
  V153_w_002: bool;
  V162_w_002: bool;
  V163_w_003: bool;
  V164_w_004: bool;
  V175_w_001: bool;
  V176_w_002: bool;
  V187_w_004: bool;
  V188_w_005: bool;
  V189_w_006: bool;
  V190_w_007: bool;
  V191_w_009: bool;
  V192_w_002: bool;
  V193_w_003: bool;
  V194_w_004: bool;
  V195_w_002: bool;
  V196_w_003: bool;
  V197_w_004: bool;

let
  etat = (V17_w_009 and V14_w_006);
  V13_w_005 = (V192_w_002 and V193_w_003);
  V14_w_006 = (V162_w_002 and V163_w_003);
  V15_w_007 = (V153_w_002 and V13_w_005);
  V16_w_008 = (Obstacle >= soeuil_obstacle);
  V17_w_009 = (not V13_w_005);
  V19_w_011 = (V176_w_002 and V16_w_008);
  V152_w_001 = (false -> (pre V13_w_005));
  V153_w_002 = (not V152_w_001);
  V162_w_002 = (V164_w_004 or V16_w_008);
  V163_w_003 = (not V15_w_007);
  V164_w_004 = (false -> (pre V14_w_006));
  V175_w_001 = (false -> (pre V16_w_008));
  V176_w_002 = (not V175_w_001);
  V187_w_004 = (V191_w_009 or V19_w_011);
  V188_w_005 = (Cg >= soeuil_blanc);
  V189_w_006 = (Cg <= soeuil_noir);
  V190_w_007 = (V195_w_002 and V196_w_003);
  V191_w_009 = (not V190_w_007);
  V192_w_002 = (V194_w_004 or V188_w_005);
  V193_w_003 = (not V187_w_004);
  V194_w_004 = (false -> (pre V13_w_005));
  V195_w_002 = (V197_w_004 or V189_w_006);
  V196_w_003 = (not V19_w_011);
  V197_w_004 = (false -> (pre V190_w_007));
tel

