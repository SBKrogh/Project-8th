function [ gammaD, gammaC ] = Tower_Tr( par )
%TOWER_TR Summary of this function goes here
%   Detailed explanation goes here
gamma = zeros(24,1);
gamma(24) = par(16);

gammaC = gamma;
gammaD = diag(gamma);

end

