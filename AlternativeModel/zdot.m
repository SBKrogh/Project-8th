%% Build up the f function

function [dx, y] = zdot(t, x, u, p, varargin)


pump_param;
valve_param;
pipe_param;
matrices;

 pipe.e02.Cp = p(1);
 pipe.e04.Cp = p(2);
 pipe.e05.Cp = p(3);
 pipe.e06.Cp = p(4);
 pipe.e11.Cp = p(5);
 pipe.e21.Cp = p(6);
 pipe.e23.Cp = p(7);
 pipe.e03.Cp = p(8);
 pipe.e07.Cp = p(9);
 pipe.e10.Cp = p(10);
 pipe.e12.Cp = p(11);
 pipe.e14.Cp = p(12);
 pipe.e17.Cp = p(13);
 pipe.e18.Cp = p(14);
 pipe.e19.Cp = p(15);

q = B_1'*x;

[valve, pump, q] = updateInputs(valve, pump, u, q);

alpha = pumpvec(pump, q);
lambda =  lambdavec(pipe, q);
mu = valvevec(valve, q);
J = inertiavec(pipe);

F = +lambda + mu - alpha;

dx = - (B_1 * J * B_1') \ B_1 * F ;

dq = B_1'* dx;


DeltaP = (J*dq+mu+lambda-alpha);

pa = 1;
invH_11 = pinv(H_11');

%  obtain pressure difference on each node
rp = invH_11 * (DeltaP - H_10'*pa) ;


% y(:,1) = DeltaP(:,8);     % Edge 1 Component C2
% y(:,2) = DeltaP(:,11);    % Edge 8 Component 16
% y(:,3) = DeltaP(:,12) + DeltaP(:,13) + DeltaP(:,16) + DeltaP(:,17);    % Edge 9 Component 18 & Edge 10 Component 19 & Edge 14 Component 23 & Edge 15 Component 24
% y(:,4) = DeltaP(:,18) + DeltaP(:,19) + DeltaP(:,6) + DeltaP(:,23);    % Edge 16 Component 25 & Edge 17 Component 26 & Edge 21 Component 30 & Edge 22 Component 31
% y(:,5) = DeltaP(:,17);    % Edge 15 Component 24
% y(:,6) = DeltaP(:,15) + DeltaP(:,14);    % Edge 13 Component 20 & Edge 12 Component 21
% y(:,7) = DeltaP(:,23);    % Edge 22 Component 31
% y(:,8) = DeltaP(:,21) + DeltaP(:,22);    % Edge 19 Component 28 & Edge 20 Component 27

% y(:,1) = rp(2) - 1;
% y(:,2) = rp(7) - 1;
% y(:,3) = rp(4) - 1;
% y(:,4) = rp(5) - 1;
% y(:,5) = rp(10) - 1;
% y(:,6) = rp(11) - 1;
% y(:,7) = rp(15) - 1;
% y(:,8) = rp(16) - 1;

y(:,1) = rp(1) - 1;     % Node 2
y(:,2) = rp(6) - 1;     % Node 7
y(:,3) = rp(3) - 1;     % Node 4
y(:,4) = rp(4) - 1;     % Node 5
y(:,5) = rp(10) - 1;    % Node 11
y(:,6) = rp(9) - 1;     % Node 10
y(:,7) = rp(15) - 1;    % Node 16
y(:,8) = rp(14) - 1;    % Node 15



end

