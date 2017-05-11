%Solve a quadratic programming problem

%%%%
%%%% lamda1 lamda2 lamda3 Gamma psi d_bar u_hat u_bar theta delta_p_0
%%%% and u_max need to be definde. 
%%%%

%%% Our QP 
% 1/eta * (u_hat'*(2*(lamda1+lamda3*Gamma)*u_hat +
% u_hat'((B_tilde+C_tilde*psi)*d_tilde+C_tilde*theta*delta_p_0))

%%% Generel QP
% 0.5*x'H*x+f*x

%This means that 

H = 2*(lamda1+lamda3*Gamma); 
f = (2*lamda1+lamda3*Gamma)'*u_bar+(lamda2+lamda3*psi)*d_bar+lamda2*d_bar+lamda3*theta*delta_p_0;
lb = zeros(2,1);
ub = u_max*ones(2,1);

options = optimoptions('quadprog','Display','off');

[x,fval,output,lambda] = ...
   quadprog(H,f,A,b,[],[],lb,[],[],options);

x,fval,exitflag
