%
function y=simwater(u,t,par)

Cp(2) = par(1);
Cp(3) = par(2);
Cp(4) = par(3);
Cp(5) = par(4);
Cp(6) = par(5);
Cp(7) = par(6);
Cp(10) = par(7);
Cp(11) = par(8);
Cp(12) = par(9);
Cp(14) = par(10);
Cp(17) = par(11);
Cp(19) = par(12);
Cp(21) = par(13);
Cp(23) = par(14);




G = 
%
%
y = ode45 (@zdot
end