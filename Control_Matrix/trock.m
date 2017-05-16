% Load the parameters saved from the estimation
load('parameter_matrix.mat');

% Complete the state-space system matrices for estimation

Ad = linear_b_est(1);

Bd = [ linear_b_est(2) linear_b_est(3) linear_b_est(4) linear_b_est(5) linear_b_est(6) linear_b_est(7) linear_b_est(8) linear_b_est(9) ];

Cd = [ linear_b_est(10); linear_b_est(11); linear_b_est(12); linear_b_est(13); 1 ];

Dd = [ linear_b_est(14) linear_b_est(15) linear_b_est(16) linear_b_est(17) linear_b_est(18) linear_b_est(19) linear_b_est(20) linear_b_est(21);
    linear_b_est(22) linear_b_est(23) linear_b_est(24) linear_b_est(25) linear_b_est(26) linear_b_est(27) linear_b_est(28) linear_b_est(29);
    linear_b_est(30) linear_b_est(31) linear_b_est(32) linear_b_est(33) linear_b_est(34) linear_b_est(35) linear_b_est(36) linear_b_est(37);
    linear_b_est(38) linear_b_est(39) linear_b_est(40) linear_b_est(41) linear_b_est(42) linear_b_est(43) linear_b_est(44) linear_b_est(45);
    zeros(1,8)];


% State-Space matrices for control 
Ac = Ad;

Bc = [ Bd(5) Bd(6) ];

Ec =  Bd(1:4);

Cc = [ Cd(2); Cd(4) ];

Dc = [ Dd(2,5); Dd(4,6) ];

Kc = [ Dd(2,1:4); Dd(4,1:4) ];



%% Time constant WT




