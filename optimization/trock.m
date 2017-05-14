% Load the parameters saved from the estimation
load('parameter_matrix.mat');

% Complete the state-space system matrices for estimation

As = linear_b_est(1);

Bs = [ linear_b_est(2) linear_b_est(3) linear_b_est(4) linear_b_est(5) linear_b_est(6) linear_b_est(7) linear_b_est(8) linear_b_est(9) ];

Cs = [ linear_b_est(10); linear_b_est(11); linear_b_est(12); linear_b_est(13); 1 ];

Ds = [ linear_b_est(14) linear_b_est(15) linear_b_est(16) linear_b_est(17) linear_b_est(18) linear_b_est(19) linear_b_est(20) linear_b_est(21);
    linear_b_est(22) linear_b_est(23) linear_b_est(24) linear_b_est(25) linear_b_est(26) linear_b_est(27) linear_b_est(28) linear_b_est(29);
    linear_b_est(30) linear_b_est(31) linear_b_est(32) linear_b_est(33) linear_b_est(34) linear_b_est(35) linear_b_est(36) linear_b_est(37);
    linear_b_est(38) linear_b_est(39) linear_b_est(40) linear_b_est(41) linear_b_est(42) linear_b_est(43) linear_b_est(44) linear_b_est(45);
    zeros(1,8)];

sys = ss(As,Bs,Cs,Ds);

Ts = 0.05;

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