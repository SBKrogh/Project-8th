clear all
close all
clc
%%
%Solve a quadratic programming problem

%Variabels that we need to sort out.
% delta_p_0 d_hp U_bar_hp q_bar_p_hp
% 

% Variabels that we hare in the Matrix_op.m file
% lamda_A lamda_B lamda_C Gamma Psi Phi Theta Omega Pi 
Matrix_op;
trock;                  %Load system matrices

delta_p_0 = 0;

%%%%%%%%%%%%%%%%%% Generel QP %%%%%%%%%%%%%%%%%%
% 0.5*x'H*x+f*x
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Output constraint
y_low = 0.08*ones(48,1);
y_high = 0.14*ones(48,1);
y_bar = 0.11*ones(48,1);

y1 = y_low - y_bar - Theta*Phi*delta_p_0-(Phi*Psi+Pi)*d_hp;
y2 = y_high - y_bar - Theta*Phi*delta_p_0-(Phi*Psi+Pi)*d_hp;
L_y = Phi*Gamma+Omega;

% State constraint
x_low = 0*ones(48,1);
x_high = 0.16*ones(48,1);
x_bar = 0.10*ones(48,1);

dalta_p_wt_1 = x_low-x_bar - Phi*delta_p_0 -(Phi*Psi+Pi)*d_hp;
dalta_p_wt_2 = x_high-x_bar - Phi*delta_p_0 -(Phi*Psi+Pi)*d_hp;

% input constraint 
u_low = 0;
u_high = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Setting up the QP %%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

H = 2*(lamda_A+lamda_C*Gamma); 
f = U_bar_hp'*(lamda_A+lamda_C*Gamma)*d_hp'*(lamda_B+lamda_C*Psi)+delta_p_0*(lamda_C*Phi)+q_bar_p_hp;

A = [L_y; -L_y; Gamma; -Gamma];
b = [y1; y2; dalta_p_wt_1; dalta_p_wt_2];

lb = u_low*ones(2,1);
ub = u_high*ones(2,1);

options = optimoptions('quadprog','Display','off');

[u_hp,cost,output,lambda] = ...
   quadprog(H,f,A,b,[],[],lb,ub,[],options);

u_hp,cost,exitflag

