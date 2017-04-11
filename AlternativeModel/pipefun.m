%Pipe function
function lambda = pipefun(c, q)
g = 9.82; % m/s^2 
rho = 1000;
lambda = (c.Cp * abs(q)*q /(10^5*3600^2)) + ((c.Z)*g*rho/10^5);
end

