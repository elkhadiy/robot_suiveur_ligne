

l_nominal=0.12;  %axe inter-roue
l1=0.1;
l2=0.14;

%Parametres du controleur d'orientation
alpha_nominal=1/l_nominal;
omega_nominal= 1.25 %1, 10; 
ksi_nominal= 1 %0.01, 0.005;
ki_teta_nominal=omega_nominal*omega_nominal/alpha_nominal
kp_teta_nominal=2*ksi_nominal*omega_nominal/alpha_nominal

%periode d'echantillonage, varier T pour etudier la robustesse
T_nominal = 100; 



% definir les polynomes
Pmm = [   4/(T_nominal*T_nominal)      2*kp_teta_nominal/(l2*T_nominal)        ki_teta_nominal/l2 ];
Ppp = [   4/(T_nominal*T_nominal)      2*kp_teta_nominal/(l1*T_nominal)        ki_teta_nominal/l1 ];
Pmp = [   4/(T_nominal*T_nominal)      2*kp_teta_nominal/(l1*T_nominal)        ki_teta_nominal/l2 ];
Ppm = [   4/(T_nominal*T_nominal)      2*kp_teta_nominal/(l2*T_nominal)        ki_teta_nominal/l1 ];



H1 = hurwitz(Pmm,2)
H2 = hurwitz(Ppp,2)
H3 = hurwitz(Pmp,2)
H4 = hurwitz(Ppm,2)