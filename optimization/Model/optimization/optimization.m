%Solve a quadratic programming problem

%Variabels that we need to sort out.
% lamda1 lamda2 lamda3 Gamma psi d_bar u_hat u_bar theta delta_p_0. 
%

%%%%%%%%%%%%%%%%%% Generel QP %%%%%%%%%%%%%%%%%%
% 0.5*x'H*x+f*x

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Output constraint
% u_bar = (C_bar*Gamma)'*(y_bar-C_bar*theta*delta_p_0-C_bar*psi*d_bar)
y_low = 0.08;
y_high = 0.14;

u_y_low = (C_bar*Gamma)'*(y_low-C_bar*theta*delta_p_0-C_bar*psi*d_bar);
u_y_high = (C_bar*Gamma)'*(y_high-C_bar*theta*delta_p_0-C_bar*psi*d_bar);

% State constraint
% u_bar = Gamma'*(x_bar-theta*delta_p_0-psi*d_bar)
x_low = ;
x_high = 0.16;

u_x_low = Gamma'*(x_low-theta*delta_p_0-psi*d_bar);
u_x_high = Gamma'*(x_high-theta*delta_p_0-psi*d_bar);

% input constraint 
u_low = 0;
u_high = ;

%Picking out most narrov interval. 
u_min = max([u_y_low;u_x_low;u_low]);
u_max = min([u_y_high;u_x_high;u_high]);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Setting up the QP %%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

H = 2*(lamda1+lamda3*Gamma); 
f = (2*lamda1+lamda3*Gamma)'*u_bar+(lamda2+lamda3*psi)*d_bar+lamda2*d_bar+lamda3*theta*delta_p_0;

A = [y_low 1; -1 2; 2 1];
b = [2; 2; 3];

lb = u_min*ones(2,1);
ub = u_max*ones(2,1);

options = optimoptions('quadprog','Display','off');

[x,fval,output,lambda] = ...
   quadprog(H,f,,,[],[],lb,ub,[],options);

x,fval,exitflag

