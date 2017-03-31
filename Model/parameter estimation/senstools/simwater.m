%
function y=simwater(u,t,par)

%Define vector for Cps
Cp = zeros(23,1);

%Set values for the row that are pipes 
Cp(1) = par(1);
Cp(2) = par(2);
Cp(3) = par(3);
Cp(4) = par(4);
Cp(5) = par(5);
Cp(6) = par(6);
Cp(7) = par(7);
Cp(9) = par(8);
Cp(10) = par(9);
Cp(13) = par(10);
Cp(14) = par(11);
Cp(16) = par(12);
Cp(19) = par(13);
Cp(20) = par(14);
Cp(21) = par(15);

U = u;
%Define the "simulation"
y = f_vectorfunction(Cp,U);
end