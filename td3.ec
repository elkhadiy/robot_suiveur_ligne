node td3
  (Cg: int;
  reset: bool)
returns
  (epsilon: bool);

var
  V7_w_000: bool;
  V8_w_001: bool;
  V9_w_002: bool;
  V10_w_003: bool;
  V11_w_004: bool;
  V12_w_005: bool;
  V86_w_001: bool;
  V87_w_004: bool;
  V88_w_006: bool;
  V99_w_001: bool;
  V100_w_004: bool;
  V101_w_006: bool;
  V114_w_001: bool;
  V115_w_004: bool;
  V116_w_006: bool;

let
  epsilon = (if V8_w_001 then false else V115_w_004);
  V7_w_000 = (not V12_w_005);
  V8_w_001 = (reset or V7_w_000);
  V9_w_002 = (not V10_w_003);
  V10_w_003 = (if reset then false else V100_w_004);
  V11_w_004 = (V9_w_002 or reset);
  V12_w_005 = (if V11_w_004 then false else V87_w_004);
  V86_w_001 = (false -> (pre V12_w_005));
  V87_w_004 = (V88_w_006 or V86_w_001);
  V88_w_006 = (Cg <= 100);
  V99_w_001 = (false -> (pre V10_w_003));
  V100_w_004 = (V101_w_006 or V99_w_001);
  V101_w_006 = (Cg >= 100);
  V114_w_001 = (false -> (pre epsilon));
  V115_w_004 = (V116_w_006 or V114_w_001);
  V116_w_006 = (Cg >= 100);
tel

