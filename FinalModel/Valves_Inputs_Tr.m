function [ mu_I_D, mu_I_C ] = Valves_Inputs_Tr( par )
%VALVES Summary of this function goes here
%   Detailed explanation goes here
mu = zeros(24,1);

mu(15) = par(17);

mu(17) = par(18);

mu(22) = par(19);

mu(23) =  par(20);


mu_I_D = diag(mu);
mu_I_C = mu;




end

