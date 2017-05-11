%Solve a quadratic programming problem

%%%%
%%%% and u_max need to be definde. 
%%%%

%%% Our QP 

%%% Generel QP

%This means that 

lb = zeros(2,1);
ub = u_max*ones(2,1);

options = optimoptions('quadprog','Display','off');

[x,fval,output,lambda] = ...
   quadprog(H,f,A,b,[],[],lb,[],[],options);

x,fval,exitflag
