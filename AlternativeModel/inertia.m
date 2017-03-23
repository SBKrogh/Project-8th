%Inertia parameter function
function J = inertia(L,D,i)
ro = 1000; %kg/m^3
J = diag((4*L(i)*ro)./(D(i).^2*pi*10^5*3600));
end

