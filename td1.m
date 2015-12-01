% Degré du polynome
n = 2;

% Variables d'insertitude
T = 1;
l = 1;
kptheta = 1;
kitheta = 1;


a_2 = 4/T^2;
a_1 = 2*kptheta/(l*T);
a_0 = kitheta/l;

p = [ a_2 a_1 a_0 ];

H = hurwitz(p, n)



