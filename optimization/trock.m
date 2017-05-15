
% Complete the state-space system matrices for estimation
[ M , N, As, Bs, Cs, Ds ] = mat_est;

M_c = M;

N_c = [ N(:,5) N(:,6) ];

Q_c = N(:,1:4);

sys = ss(As,Bs,Cs,Ds);

Ts = 600;

sysd = c2d(sys, Ts);

% State-Space matrices for control in continous
Ac = As;

Bc = [ Bs(5) Bs(6) ];

Ec =  Bs(1:4);

Cc = [ Cs(2); Cs(4) ];

Dc = [ Ds(2,5) Ds(2,6); Ds(4,5) Ds(4,6) ];

% State-Space matrices for control in discrete
Ad = sysd.A;

Bd = [ sysd.B(5) sysd.B(6) ];

Ed =  sysd.B(1:4);

Cd = [ sysd.C(2); sysd.C(4) ];

Dd = [ sysd.D(2,5) sysd.D(2,6); sysd.D(4,5) sysd.D(4,6) ];

Kd = [ sysd.D(2,1:4); sysd.D(4,1:4) ];


WTconstant = (pi * (0.32)^2)/(1000*9.8);

S =  - (1/WTconstant) * pinv(H_0) * H_1 * B_1';