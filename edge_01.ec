node edge_01
  (in: bool)
returns
  (out: bool);

var
  V30_w_000: bool;

let
  out = (in and V30_w_000);
  V30_w_000 = (false -> (pre out));
tel

