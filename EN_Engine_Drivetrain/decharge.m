clc;clear all;close all;
% t_max : largeur temporelle de la fenetre(en second)
% t_charge : periode pour chaque re-charge(en second)
t_max = 15; t_charge=5;
T0 = 20; % Temperature initiale(en oC)
% Parametres intrinseques
S = 535E-4; % Section equivalent du dechauffage(en m^2)
m = 32E-3; % masse(en kg)
C_e = 321E-6; % Condensateur(en F)
C_q = 0.88E3; % Capacite thermique massique(en J/(kg.K))
h = 226; % Coeffiences de Newtons(en W/(K.m^2))
a = 0.009; % Variation thermique de la resistance(en K^(-1))
% Parametres du systeme
R0 = 6.8E3; V0 = 540; % Resistance(en Ohm) et tension(en V) intiales
% Initialisation
R=[R0];T=[T0];V=[V0];
t_pas = min(0.5,t_charge/5);t=t_pas:t_pas:t_max;index = 1;
% Iteration de calcul
for i = t
    % C*m*dT=(P_joule-P_newton)*dt
    % P_joule = V^2/R
    % P_newton = hS(T-T0)
    if mod(i,t_charge)==0
        V(index)=V0;
    end
    V = [V V(index)*exp(-t_pas/C_e/R(index))];
    dT = (V(index)^2/R(index)-h*S*(T(index)-T0))*t_pas/C_q/m;
    T = [T T(index)+dT];
    % R = R_0*(1+a*(T-T0))
    R = [R R0*(1+a*(T(index)-T0))];
    index = index+1;
end
% Affichage
figure();xlabel("t(s)");
yyaxis left; plot([0 t],T); ylabel("T[^oC]");hold on;
yyaxis right; plot([0 t],R./1000); ylabel("R[k\ohm]");
legend(["R","T"])