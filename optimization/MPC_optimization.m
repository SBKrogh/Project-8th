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

d_hp = 0.05*90*ones(48,1);      % Small signal deviation of the Valves OD
U_bar_hp = 0.2*ones(48,1);      % Input pressure to ring pumps operating point
q_bar_p_hp = 1.4*ones(48,1);    % Flow operating point of the ring pumps


%%%%%%%%%%%%%%%%%% Generel QP %%%%%%%%%%%%%%%%%%
% 0.5*x'R*x+f'*x
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Output constraint
y_low = -0.0755*ones(48,1);         % Lower bound small deviation for Pressure PMA
y_high = 0.0245*ones(48,1);         % Upper bound small deviation for Pressure PMA

% Pressure operating point of the PMA end-users
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

R = (Lambda_A + Lambda_C*Gamma); 

f = U_bar_hp'*(Lambda_A+Lambda_C*Gamma)+d_hp'*(Lambda_B+Lambda_C*Psi)'+delta_p_0*(Lambda_C*Phi)'+q_bar_p_hp';

A = [-L_y; L_y; -Gamma; Gamma];
b = [y1; y2; dalta_p_wt_1; dalta_p_wt_2];

lb = u_low*ones(48,1);
ub = u_high*ones(48,1);

%options = optimoptions('Display','iter-detailed');%quadprog

options = optimoptions('quadprog','Display','iter-detailed')
[u_hp,cost,output,lambda] = ...
   quadprog(R,f,[],[],[],[],lb,ub,[],options);

u_hp,cost

%Checking positive definiteness:

r1 = randn(48,1);
r2 = randn(8,1);

%%


% 
% H = H(1:2,1:2);
% 
% theta = (0:0.01:2*pi);
% 
% x = [cos(theta); sin(theta)];
% 
% r = sqrt(diag(x'*H(1:2,1:2)*x));
% 
% m = -0.5*inv(H) * f(1,1:2);
% 
% c = (x + 0.5 * inv(H) * f)' * H * (x + 0.5 * inv(H) * f) - 0.25 * f' * inv(H) * f;
% 
% cbar = sqrt(c + 0.25 * f' * inv(H) * f);
% 
% plot(m(1) + x(1,:).\r'*cbar,...
%     m(2) + x(2,:).\r'*cbar, '--r')



%Test 
%x = sym('x',[48 1]);
%
%x = ([1:1:48])';
%
%
%plot(x'*H(1:2,1:2)*x+f(1,1:2)*x)
