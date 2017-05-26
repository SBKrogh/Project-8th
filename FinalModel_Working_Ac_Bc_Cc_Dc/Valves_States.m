function [ mu_S_D, mu_S_C, c ] = Valves_States( c, B_1, zo )
%VALVES Summary of this function goes here
%   Detailed explanation goes here
mu = zeros(24,1);

mu(15) =  2 * exp((192/25 - (32 * c.e13.Oo * 90 / 375 )))  * abs(B_1(:,15)' * zo);

mu(17) =  2 * exp((192/25 - (32 * c.e15.Oo * 90 / 375 )))  * abs(B_1(:,17)' * zo);

mu(22) =  2 * exp((192/25 - (32 * c.e20.Oo * 90 / 375 )))  * abs(B_1(:,22)' * zo);

mu(23) =  2 * exp((192/25 - (32 * c.e22.Oo * 90 / 375 )))  * abs(B_1(:,23)' * zo);

c.muS = mu;

mu_S_D = diag(mu);
mu_S_C = mu;



end

