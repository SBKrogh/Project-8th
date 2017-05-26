function [ lambdaD, lambdaC, c ] = Pipes( c, B1, zo )
%PIPES Summary of this function goes here
%   Detailed explanation goes here

lambda = zeros(24,1);
lambda(1) = 2 * c.e02.Cp * abs(B1(:,1)' * zo)/(10^5*3600^2);
lambda(2) = 2 * c.e03.Cp * abs(B1(:,2)' * zo)/(10^5*3600^2);
lambda(3) = 2 * c.e04.Cp * abs(B1(:,3)' * zo)/(10^5*3600^2);
lambda(4) = 2 * c.e05.Cp * abs(B1(:,4)' * zo)/(10^5*3600^2);
lambda(5) = 2 * c.e06.Cp * abs(B1(:,5)' * zo)/(10^5*3600^2);
lambda(6) = 2 * c.e11.Cp * abs(B1(:,6)' * zo)/(10^5*3600^2);
lambda(7) = 2 * c.e21.Cp * abs(B1(:,7)' * zo)/(10^5*3600^2);
lambda(8) = 2 * c.e23.Cp * abs(B1(:,8)' * zo)/(10^5*3600^2);
lambda(10) = 2 * c.e07.Cp * abs(B1(:,10)' * zo)/(10^5*3600^2);
lambda(13) = 2 * c.e10.Cp * abs(B1(:,13)' * zo)/(10^5*3600^2);
lambda(14) = 2 * c.e12.Cp * abs(B1(:,14)' * zo)/(10^5*3600^2);
lambda(16) = 2 * c.e14.Cp * abs(B1(:,16)' * zo)/(10^5*3600^2);
lambda(19) = 2 * c.e17.Cp * abs(B1(:,19)' * zo)/(10^5*3600^2);
lambda(20) = 2 * c.e18.Cp * abs(B1(:,20)' * zo)/(10^5*3600^2);
lambda(21) = 2 * c.e19.Cp * abs(B1(:,21)' * zo)/(10^5*3600^2);

lambdaC = lambda;
lambdaD = diag(lambda);

c.lambda = lambda;

end

