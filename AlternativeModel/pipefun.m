%Pipe function
function lambda = pipefun(c, q)
g = 9.82; % m/s^2 
rho = 1000;
lambda = (c.Cp * abs(q)*q) + ((c.Z)*g*1000);
end

