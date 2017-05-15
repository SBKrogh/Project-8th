%Solve a quadratic programming problem

%Variabels that we need to sort out.
% delta_p_0 d_hp U_bar_hp q_bar_p_hp
% C_hp D_hp E_hp K_hp 

% Variabels that we hare in the Matrix_op.m file
% lamda_A lamda_B lamda_C Gamma Psi Phi 
Matrix_op;
trock;                  %Load system matrices

%%%%%%%%%%%%%%%%%% Generel QP %%%%%%%%%%%%%%%%%%
% 0.5*x'H*x+f*x
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
u_hp = 3;
% Output constraint
y_low = 0.08;
y_high = 0.14;
output_con = (C_hp*Gamma*D_hp)* u_hp +C_hp*Phi*delta_p_0+(C_hp*Psi+K_hp)*d_hp;

% State constraint
x_low = 0;
x_high = 0.16;
state_con = Phi*delta_p_0+Gamma* u_hp + Psi*d_hp;

% input constraint 
u_low = 0;
u_high = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Setting up the QP %%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

H = 2*(lamda_A+lamda_C*Gamma); 
f = U_bar_hp'*(lamda_A+lamda_C*Gamma)*d_hp'*(lamda_B+lamda_C*Psi)+delta_p_0*(lamda_C*Phi)+q_bar_p_hp;

A = [y_low -output_con; output_con -y_high; x_low -state_con; state_con x_high];
b = [0; 0; 0; 0];

lb = u_low*ones(2,1);
ub = u_high*ones(2,1);

options = optimoptions('quadprog','Display','off');

[u_hp,cost,output,lambda] = ...
   quadprog(H,f,A,b,[],[],lb,ub,[],options);

u_hp,cost,exitflag

