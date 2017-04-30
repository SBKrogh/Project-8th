function [ mu_I_D, mu_I_C, c ] = Valves_Inputs( c, B_1, zo )
%VALVES Summary of this function goes here
%   Detailed explanation goes here
mu = zeros(24,1);

mu(15) = (-2*3.2*exp(3.2*((2/5)-(2*c.e15.Oo) /75) +2)  * B_1(:,15)' * zo * abs(B_1(:,15)' * zo))  /75;

mu(17) = (-2*3.2*exp(3.2*((2/5)-(2*c.e17.Oo) /75) +2)  * B_1(:,17)' * zo * abs(B_1(:,17)' * zo))  /75;

mu(22) =  (-2*3.2*exp(3.2*((2/5)-(2*c.e22.Oo) /75) +2)  * B_1(:,22)' * zo * abs(B_1(:,22)' * zo)) /75;

mu(23) =  (-2*3.2*exp(3.2*((2/5)-(2*c.e23.Oo) /75) +2)  * B_1(:,23)' * zo * abs(B_1(:,23)' * zo)) /75;

c.muI = mu;

mu_I_D = diag(mu);
mu_I_C = mu;




end

