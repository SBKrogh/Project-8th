%Solve a simple quadratic programming problem

H = [5 -1; -1 2]; 
f = [-2; -6];
lb = zeros(2,1);
ub = 1.2*ones(2,1);

options = optimoptions('quadprog','Display','off');

[x,fval,exitflag,output,lambda] = ...
   quadprog(H,f,A,b,[],[],lb,ub,[],options);

x,fval,exitflag