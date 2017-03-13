%Setting up the function that we will use in a big model later

function J = inertiaFunc(L,D)

J = diag((4*L*1000)./(D.^2*pi*10^5*3600));

end

