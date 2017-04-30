function [ mu_S_D, mu_S_C ] = Valves_States_Tr( par )
%VALVES Summary of this function goes here
%   Detailed explanation goes here
mu = zeros(24,1);

mu(15) =  par(21);

mu(17) =  par(22);

mu(22) =  par(23);

mu(23) =  par(24);

mu_S_D = diag(mu);
mu_S_C = mu;



end

