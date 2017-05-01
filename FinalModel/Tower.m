function [ gammaD, gammaC, c ] = Tower( c, B1, zo )
% Insert the connection of the WT
gamma = zeros(24,1);
gamma(24) = - 2 * c.e24.Ah22 * B1(:,24)' * zo;

gammaC = gamma;
gammaD = diag(gamma);

c.gamma = gamma;

end

