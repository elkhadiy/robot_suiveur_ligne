



%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Question 2.1 %%%%%
%%%%%%%%%%%%%%%%%%%%%%%%

%Parametres du controleur d'orientation
l_nominal=0.2;  %axe inter-roue
alpha_nominal=1/l_nominal;
omega_nominal= 1.25 %10; 
ksi_nominal= 1 %0.005;
ki_teta_nominal=omega_nominal*omega_nominal/alpha_nominal
kp_teta_nominal=3*ksi_nominal*omega_nominal/alpha_nominal


% Periode d'echantillonage
T_nominal = 0.001; 


% On calcule Amin, la condition de robustesse est donc : A >= Amin et B =
% B_nominal
fprintf('\n\nQuestion 2.1\n');
fprintf('On calcule Amin\n');
Amin = qmin(l_nominal, ki_teta_nominal, kp_teta_nominal, T_nominal)


%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Question 2.2 %%%%%
%%%%%%%%%%%%%%%%%%%%%%%%
% Cette question sert a` illustrer comment utiliser les conditions de
% robustesse trouve'es. Supposons que l'on on veut varier ki_teta et T 
% par 5% de leurs valeurs nominales, la distance entre-roues l garde 
% sa valeur nominale

ki_teta = ki_teta_nominal + 5*ki_teta_nominal/100;
T = T_nominal + 5*T_nominal/100;
l = l_nominal;

% On calcule la valeur constante de B
A_nominal = -4/T_nominal + 2*kp_teta_nominal/(l_nominal*T_nominal);
B_nominal = (ki_teta_nominal/l_nominal - 1)/A_nominal;
Bcst = B_nominal;

% Puis, kp_teta doit etre choisi en respectant la contrainte Bcst=const
kp_teta = ( (ki_teta/l -1)/Bcst + 4/T )*(l*T)/2;

% On verifie si A >= Amin
fprintf('\n\nQuestion 2.2\n');
fprintf('On verifie si les valeurs des parametres choisies a partir\n');
fprintf('des contraintes satisfont A >= Amin\n');
A = -4/T + 2*kp_teta/(l*T)
Amin




%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Question 2.3 %%%%%
%%%%%%%%%%%%%%%%%%%%%%%%

% On peut varier la periode d'echantillonnage pour observer la robustesse
% Par exemple, en augmentant T_nominal on peut observer une reduction
% de la marge de robustesse 
fprintf('\n\nQuestion 2.3\n');
fprintf('On augmente la periode dechantillonnage\n');
fprintf('et observe le changement de Amin\n');
for i=1:4 
    T_n = T_nominal*10^i
    Amin = qmin(l_nominal, ki_teta_nominal, kp_teta_nominal, T_n)
end




