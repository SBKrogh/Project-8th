%Inertia parameter function
function J = inertiafun(c)
rho = 1000; %kg/m^3
J = diag((4*c.L*rho)/(c.D^2*pi));
end

