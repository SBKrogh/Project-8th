clear all
close all
clc
%%
%Solve a quadratic programming problem

%Variabels that we need to sort out.
% delta_p_0 d_hp U_bar_hp q_bar_p_hp
% 

% Variabels that we hare in the Matrix_op.m file
% Lambda_A Lambda_B Lambda_C Gamma Psi Phi Theta Omega Pi 
Matrix_op;
trock;                  %Load system matrices

delta_p_0 = 0.002;

d_hp = 0.05*ones(96,1);
U_bar_hp = 0.2*ones(48,1);
q_bar_p_hp = 1.4*ones(48,1);


%%%%%%%%%%%%%%%%%% Generel QP %%%%%%%%%%%%%%%%%%
% 0.5*x'H*x+f'*x
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Output constraint
y_low = -0.0755*ones(48,1);
y_high = 0.0245*ones(48,1);
y_bar = [0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
        0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
        0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
        0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991];

y1 = y_low - y_bar - Theta*Phi*delta_p_0-(Theta*Psi+Pi)*d_hp;
y2 = y_high - y_bar - Theta*Phi*delta_p_0-(Theta*Psi+Pi)*d_hp;
L_y = Theta*Gamma+Omega;

% State constraint
x_low = -0.077*ones(24,1);
x_high = 0.033*ones(24,1);
x_bar = 0.127*ones(24,1);

dalta_p_wt_1 = x_low-x_bar - Phi*delta_p_0 - Psi*d_hp;
dalta_p_wt_2 = x_high-x_bar - Phi*delta_p_0 - Psi*d_hp;

% input constraint 
u_low = 0;
u_high = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Setting up the QP %%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

H_wrong = (Lambda_A+Lambda_C*Gamma); 
H = (H_wrong+H_wrong')./2;
f = U_bar_hp'*(Lambda_A+Lambda_C*Gamma)+d_hp'*(Lambda_B+Lambda_C*Psi)'+delta_p_0*(Lambda_C*Phi)'+q_bar_p_hp';

A = [-L_y; L_y; -Gamma; Gamma];
b = [y1; y2; dalta_p_wt_1; dalta_p_wt_2];

lb = u_low*ones(48,1);
ub = u_high*ones(48,1);

%options = optimoptions('Display','iter-detailed');%quadprog

options = optimoptions('quadprog','Display','iter-detailed')
[u_hp,cost,output,lambda] = ...
   quadprog(H,f,[],[],[],[],lb,ub,[],options);

u_hp,cost




%Test 
%x = sym('x',[48 1]);
%
%x = ([1:1:48])';
%
%
%plot(x'*H*x+f*x)















