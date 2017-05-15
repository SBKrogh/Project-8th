%Solve a quadratic programming problem

%Variabels that we need to sort out.
% Gamma psi phi delta_p_0 d_hp U_bar_hp
% C_hp D_hp E_hp K_hp 

% Variabels that we hare in the Matrix_op.m file
% lamda_A
Matrix_op;
trock;                  %Load system matrices

%%%%%%%%%%%%%%%%%% Generel QP %%%%%%%%%%%%%%%%%%
% 0.5*x'H*x+f*x
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Output constraint
y_low = 0.08;
y_high = 0.14;
output_con = (C_hp*Gamma*D_hp)*u_hp+C_hp*phi*delta_p_0+(C_hp*psi+K_hp)*d_hp;

% State constraint
x_low = 0;
x_high = 0.16;
state_con = phi*delta_p_0+Gamma*u_hp + psi*d_hp;

% input constraint 
u_low = 0;
u_high = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Setting up the QP %%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

H = 2*(lamda_A+lamdaC*Gamma); 
f = U_bar_hp*(lamda2+lamda3*psi)*d_bar+lamda2*d_bar+lamda3*theta*delta_p_0;

A = [y_low -output_con; output_con -y_high; x_low -state_con; state_con x_high];
b = [0; 0; 0; 0];

lb = u_low*ones(2,1);
ub = u_high*ones(2,1);

options = optimoptions('quadprog','Display','off');

[x,fval,output,lambda] = ...
   quadprog(H,f,A,b,[],[],lb,ub,[],options);

x,fval,exitflag

