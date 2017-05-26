function [ a, B, C, D] = Initialization_SS( par, Ts ) %#ok<INUSD>
%INITIALIZATION Summary of this function goes here
%   Detailed explanation goes here

a = -0.001119415617640;

B = [ 0.000297184296396894 (1.011362712563936e-4) -1.757484437305615e-7 2.924000584714482e-08 ];
%     B = [par(2) par(3)];

% C = 1;
C = [ par(1); par(2);1];

D = [ par(3) par(4) par(5) par(6);
    par(7) par(8) par(9) par(10);
    zeros(1,4)];
% D = zeros(1,4);
end
% 
% pipe.lambda(1) pipe.lambda(2) pipe.lambda(3) pipe.lambda(4) pipe.lambda(5)... 
%     pipe.lambda(6) pipe.lambda(7) pipe.lambda(8) pipe.lambda(10) pipe.lambda(13)...
%     pipe.lambda(14) pipe.lambda(16) pipe.lambda(19) pipe.lambda(20) pipe.lambda(21)...
%     valve.muI(15) valve.muI(17) valve.muI(22) valve.muI(23)...
%     valve.muS(15) valve.muS(17) valve.muS(22) valve.muS(23)

