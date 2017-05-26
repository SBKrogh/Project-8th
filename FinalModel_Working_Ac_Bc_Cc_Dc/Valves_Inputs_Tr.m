function [ mu_I_D ] = Valves_Inputs_Tr( par )
%VALVES Summary of this function goes here
%   Detailed explanation goes here
mu = zeros(24,8);

mu(15,1) = par(17);

mu(17,2) = par(18);

mu(22,3) = par(19);

mu(23,4) =  par(20);


mu_I_D = mu;




end

