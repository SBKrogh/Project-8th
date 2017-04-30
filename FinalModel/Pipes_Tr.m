function [ lambdaD, lambdaC ] = Pipes_Tr( par )
%PIPES Summary of this function goes here
%   Detailed explanation goes here

lambda = zeros(24,1);
lambda(1) = par(1);
lambda(2) = par(2);
lambda(3) = par(3);
lambda(4) = par(4);
lambda(5) = par(5);
lambda(6) = par(6);
lambda(7) = par(7);
lambda(8) = par(8);
lambda(10) = par(9);
lambda(13) = par(10);
lambda(14) = par(11);
lambda(16) = par(12);
lambda(19) = par(13);
lambda(20) = par(14);
lambda(21) = par(15);


lambdaC = lambda/(10^5*3600^2);
lambdaD = diag(lambda)/(10^5*3600^2);


end

