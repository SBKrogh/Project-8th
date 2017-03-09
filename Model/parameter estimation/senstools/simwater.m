%
function y=simwater(u,t,par)
%
s=tf('s');
%
b_1 = par(1); 
omega = par(2); 
zeta = par(3);


G = 
%
%
y = lsim(G,u,t);
end