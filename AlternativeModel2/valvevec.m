%Valve function
function mu = valvevec(valve,q)

mu = zeros(23,1);
mu(15)  = valvefun(valve.e13,q(15));
mu(17)  = valvefun(valve.e15,q(17));
mu(22)  = valvefun(valve.e20,q(22));
mu(23)  = valvefun(valve.e22,q(23));


end

