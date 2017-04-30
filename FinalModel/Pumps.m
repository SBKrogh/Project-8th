function [ alpha_S ] = Pumps( B_1 )

G = zeros (24,8);

G(9,1) = 1;       % First main Pump e01
G(11,2) = 1;      % Second main Pump e08
G(12,3) = 1;      % First side Pump e09
G(18,4) = 1;      % Second side Pump e16

% alpha_1 = zeros(4,1);
% 
% alpha_1(1) = u(:,5);
% alpha_1(2) = u(:,6);
% alpha_1(3) = u(:,7);
% alpha_1(4) = u(:,8);

alpha_S = B_1 * G ;



end

