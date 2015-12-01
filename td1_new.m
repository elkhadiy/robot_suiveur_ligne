%%% Question 1

% Degré du polynome
n = 2;

% Variables d'insertitude
nb_points = 10;
T = 0.001;
l = 0.2;
alpha = 1/l;
omega = 1.25;
ksi = 1;
kp_theta = omega*omega/alpha;
ki_theta = 3*ksi*omega/alpha;

T_min = T-nb_points*dT;
T_max = T+nb_points*dT;
dT = 0.0001;

kp_theta_min = kp_theta-nb_points*dkp_theta;
kp_theta_max = kp_theta+nb_points*dkp_theta;
dkp_theta = 0.01;

ki_theta_min = ki_theta-nb_points*dki_theta;
ki_theta_max = ki_theta+nb_points*dki_theta;
dki_theta = 0.01;

% fait en sorte que tout ce qui se plot se superpose
hold on;

% for ki_theta = ki_theta_min:dki_theta:ki_theta_max
% for kp_theta = kp_theta_min:dkp_theta:kp_theta_max
% for T = T_min:dT:T_max
%     
%     a_2 = 4/(T^2);
%     a_1 = 2*kp_theta/(l*T);
%     a_0 = ki_theta/l;
% 
%     p = [ a_2 a_1 a_0 ];
% 
%     H = hurwitz(p, n);
%     
%     minor_1 = H(1,1);
%     minor_2 = H(2,2);
%     
%     plot(T, minor_1, 'o', 'color', 'blue');
%     plot(T, minor_2, 'o', 'color', 'red');
%     
%     %drawnow;
% end
% end
% end

%%% Question 2

A = 2*kp_theta/(l*T) - 4/T;
B = (ki_theta/l - 1)/A;

p0 = [4/T^2 4/T 1];
p1 = [1 B];

H0 = hurwitz(p0, n);
H1 = hurwitz(p1, n-1);

lamda = eig(-inv(H0)*H1);
lamda_min_neg = min(lamda);
q_min = (1/lamda_min_neg)*(-inv(H0)*H1);

for ki_theta = ki_theta_min:dki_theta:ki_theta_max
for T = T_min:dT:T_max
    
    kp_theta = T*ki_theta/(l*B) - l*T/(2*B) + 2*l;
    A = 2*kp_theta/(l*T) - 4/T;
    
    p0 = [4/T^2 4/T 1];
    p1 = [1 B];

    H0 = hurwitz(p0, n);
    H1 = hurwitz(p1, n-1);

    lamda = eig(-inv(H0)*H1);
    lamda_min_neg = min(lamda);

    q = (1/lamda_min_neg)*(-inv(H0)*H1);
    
end
end

