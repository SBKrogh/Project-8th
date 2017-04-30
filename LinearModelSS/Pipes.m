function [ lambdaD, lambdaC, c ] = Pipes( c, B1, zo )
%PIPES Summary of this function goes here
%   Detailed explanation goes here

lambda = zeros(24,1);
lambda(1) = 2 * c.e01.Cp * abs(B1(:,1)' * zo);
lambda(2) = 2 * c.e02.Cp * abs(B1(:,2)' * zo);
lambda(3) = 2 * c.e03.Cp * abs(B1(:,3)' * zo);
lambda(4) = 2 * c.e04.Cp * abs(B1(:,4)' * zo);
lambda(5) = 2 * c.e05.Cp * abs(B1(:,5)' * zo);
lambda(6) = 2 * c.e06.Cp * abs(B1(:,6)' * zo);
lambda(7) = 2 * c.e07.Cp * abs(B1(:,7)' * zo);
lambda(8) = 2 * c.e08.Cp * abs(B1(:,8)' * zo);
lambda(10) = 2 * c.e10.Cp * abs(B1(:,10)' * zo);
lambda(13) = 2 * c.e13.Cp * abs(B1(:,13)' * zo);
lambda(14) = 2 * c.e14.Cp * abs(B1(:,14)' * zo);
lambda(16) = 2 * c.e16.Cp * abs(B1(:,16)' * zo);
lambda(19) = 2 * c.e19.Cp * abs(B1(:,19)' * zo);
lambda(20) = 2 * c.e20.Cp * abs(B1(:,20)' * zo);
lambda(21) = 2 * c.e21.Cp * abs(B1(:,21)' * zo);

% Insert the connection of the WT
lambda(24) = 2 * c.e24.Ah22 * B1(:,24)' * zo;

lambdaC = lambda/(10^5*3600^2);
lambdaD = diag(lambda)/(10^5*3600^2);

c.lambda = lambda;

end

