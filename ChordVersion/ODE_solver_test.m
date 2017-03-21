syms u(t) v(t)

ode1 = diff(u) == 3*u + 4*v;
ode2 = diff(v) == -4*u + 3*v;
odes = [ode1; ode2]

S = dsolve(ode1)
% 
% uSol(t) = S.u
% vSol(t) = S.v
% 
% [uSol(t), vSol(t)] = dsolve(odes)

% cond1 = u(0) == 0;
% cond2 = v(0) == 1;
% conds = [cond1; cond2];
% [uSol(t), vSol(t)] = dsolve(odes,conds)
% 
% fplot(uSol)
% hold on
% fplot(vSol)
% grid on
% legend('uSol','vSol','Location','best')