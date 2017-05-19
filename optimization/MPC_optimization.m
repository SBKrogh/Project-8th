clear all
close all
clc
%%
%Solve a quadratic programming problem

%Variabels that we need to sort out.
% delta_p_0 d_hp U_bar_hp q_bar_p_hp

% Variabels that we use in the Matrix_op.m file
% Lambda_A Lambda_B Lambda_C Gamma Psi Phi Theta Omega Pi 
Matrix_op;
trock;                  %Load system matrices

delta_p_0 = 0.05;      %small-signal initial WT pressure measurement

d_hp = 0.05*90*ones(48,1);      % Small signal deviation of the Valves OD
U_bar_hp = 0.2*ones(48,1);      % Input pressure to ring pumps operating point
q_bar_p_hp = 1.4*ones(48,1);    % Flow operating point of the ring pumps

%%%%%%%%%%%%%%%%%% Generel QP %%%%%%%%%%%%%%%%%%
% 0.5*x'R*x+f'*x
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Output constraint
y_low =  0.08*ones(48,1);         % Full-signal upper and lower bounds 
y_high = 0.18*ones(48,1);           

% Pressure operating point of the PMA end-users
y_bar = [0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
        0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
        0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
        0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991];    

y1 = y_low - y_bar - Theta*Phi*delta_p_0-(Theta*Psi+Pi)*d_hp;
y2 = y_high - y_bar - Theta*Phi*delta_p_0-(Theta*Psi+Pi)*d_hp;
L_y = Theta*Gamma+Omega;

% State constraint
x_low = 0.055*ones(24,1);
x_high = 0.164*ones(24,1);
x_bar = 0.127*ones(24,1);

delta_p_wt_1 = x_low-x_bar - Phi*delta_p_0 - Psi*d_hp;
delta_p_wt_2 = x_high-x_bar - Phi*delta_p_0 - Psi*d_hp;

% input constraint 
u_low = -0.2;
u_high = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Setting up the QP %%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

R = 2*(Lambda_A + Lambda_C*Gamma); 
R1=(R+R')/2;
R2=(R-R')/2;
f = U_bar_hp'*(Lambda_A+Lambda_C*Gamma)+d_hp'*(Lambda_B+Lambda_C*Psi)'+delta_p_0*(Lambda_C*Phi)'+q_bar_p_hp';

%CONSTRAINTS FOR Y AND X
A = [-L_y; L_y; -Gamma; Gamma];
b = [y1; y2; delta_p_wt_1; delta_p_wt_2];

%CONSTRAINTS FOR Y
% A = [-L_y; L_y];
% b = [y1; y2];

%CONSTRAINTS FOR X
% A = [-Gamma;Gamma];
% b = [delta_p_wt_1; delta_p_wt_2];

lb = u_low*ones(48,1);
ub = u_high*ones(48,1);

%options = optimoptions('Display','iter-detailed');%quadprog

options = optimoptions('quadprog','Display','iter-detailed')
[u_hp,fval,exitflag,output,lambda] = ...
   quadprog(R1,f,[],[],[],[],lb,ub,[],options);



u_hp,exitflag,output



