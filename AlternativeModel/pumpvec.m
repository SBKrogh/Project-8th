function [ alpha ] = pumpvec( pump, q )
%PUMPVEC Summary of this function goes here
%   Detailed explanation goes here
alpha = zeros(23,1);
[alpha(8)] = pump_main(pump.e01,  q(8));
[alpha(11)] = pump_main(pump.e08, q(11));
[alpha(12)] = pump_side(pump.e09, q(12));
[alpha(18)] = pump_side(pump.e16, q(18));

end

