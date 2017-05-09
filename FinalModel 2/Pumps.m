function [ alpha_S ] = Pumps( B_1 )

G = zeros (24,8);

G(9,5) = 1;       % First main Pump e01
G(11,6) = 1;      % Second main Pump e08
G(12,7) = 1;      % First side Pump e09
G(18,8) = 1;      % Second side Pump e16

alpha_S = B_1 * G ;

end

