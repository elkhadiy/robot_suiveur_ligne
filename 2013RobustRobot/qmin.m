

%%%%% TD1 - Commande robuste et application au projet Robot %%%%%
%%%%% Question 2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Cette fonction calcule la borne inferieure qmin du parametre q
% en utilisant le critere Bialas apres que la fonction de transfert 
% est reecrite sous forme requise
% p(s) = p0(s) + q p1(s)
%
% Cette fonction qmin est appele'e par BialasRobotTraz.m
% Le fichier hurwitz.m doit etre pre'sent dans le meme repertoire

function [ q ] = qmin(l_nominal, ki_teta_nominal, kp_teta_nominal, T_nominal)
Anominal= -4/T_nominal + 2*kp_teta_nominal/(l_nominal*T_nominal);
Bnominal= (ki_teta_nominal/l_nominal - 1)/Anominal;

% Definir des polynomes
p0 = [4/(T_nominal*T_nominal)    4/T_nominal    1];
p1 = [1   (ki_teta_nominal/l_nominal - 1)/Anominal];

% Calculer les matrices de Hurwitz
H1 = hurwitz(p1,1);
H0 = hurwitz(p0,2);
H = -inv(H0)*H1;
lambda = eig(H);

% Prendre la valeur propre avec la patie reelle negative la plus petite
lambdamin = min(lambda);
if (lambdamin<0) 
    q = 1/min(lambda);
else
    fprintf('Pas de borne inferieure \n');
end

end



