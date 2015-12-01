
l_nominal=0.2;  %axe inter-roue
l1=0.19;
l2=0.21;

%Parametres du controleur d'orientation
ki_teta_nominal=0.4
kp_teta_nominal=0.2


%periode d'echantillonage, varier T pour etudier la robustesse
T_nominal = 0.0001; 


% definir le polynome
p= [ 4/(T_nominal*T_nominal) 2*kp_teta_nominal/(l_nominal*T_nominal)   ki_teta_nominal/l_nominal]



H = hurwitz(p,2);
