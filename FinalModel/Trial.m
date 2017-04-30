%% Matching matrix for the inputs
G = zeros(24,8);

% Valves
% G(15,1) = 1;      % e13 Valve
% G(17,2) = 1;      % e15 Valve
% G(22,3) = 1;      % e20 Valve
% G(23,4) = 1;      % e22 Valve

% Pumps
G(9,5) = 1;       % First main Pump e01
G(11,6) = 1;      % Second main Pump e08
G(12,7) = 1;      % First side Pump e09
G(18,8) = 1;      % Second side Pump e16

% Input matrix valve part
valve_input = zeros(24,1);

% syms mu1 mu2 mu3 mu4
% syms v


mu_state = zeros(24,1);
mu_state(15)=1;
mu_state(17)=1;
mu_state(22)=1;
mu_state(23)=1;

% valve_input(15) = mu1;
% valve_input(17) = mu2;
% valve_input(22) = mu3;
% valve_input(23) = mu4;

Diff_mu = diag(mu_state);

valve_input_matrix = B_1 * Diff_mu * B_1';

pump_input_matrix = B_1 * G;

B_u = valve_input_matrix + pump_input_matrix;

%% Matching matrix for states

lambda = zeros(24,1);
lambda(1) = 1;
lambda(2) = 2;
lambda(3) = 3;
lambda(4) = 4;
lambda(5) = 5;
lambda(6) = 6;
lambda(7) = 7;
lambda(8) = 8;
lambda(10) = 9;
lambda(13) = 10;
lambda(14) = 11;
lambda(16) = 12;
lambda(19) = 13;
lambda(20) = 14;
lambda(21) = 15;


lambda = diag(lambda);
lambda_A = B_1 * lambda * B_1';

mu_state = zeros(24,1);
mu_state(15) = 1;
mu_state(17) = 2;
mu_state(22) = 3;
mu_state(23) = 4;

mu_state = diag(mu_state);

mu_state_A = B_1 * mu_state * B_1';

ah21 = 1;
alpha_state = zeros(24,1);
alpha_state(24) = (2 * ah21);
alpha_state = diag(alpha_state);
alpha_state_A = B_1 * alpha_state * B_1';


A = lambda_A + mu_state_A + alpha_state_A;

%% Matching for the WT pressure state
C = pinv(H_0) * H_1 * B_1';

%% State-Space System

a = A\B_0;
B_t = A\B_u;



