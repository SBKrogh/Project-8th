function lambda = lambdavec( pipe, q)
lambda = zeros(23,1);

lambda(1)  = pipefun(pipe.e02,q(1));
lambda(2)  = pipefun(pipe.e04,q(2));
lambda(3)  = pipefun(pipe.e05,q(3));
lambda(4)  = pipefun(pipe.e06,q(4));
lambda(5)  = pipefun(pipe.e11,q(5));
lambda(6)  = pipefun(pipe.e21,q(6));
lambda(7)  = pipefun(pipe.e23,q(7));
lambda(9)  = pipefun(pipe.e03,q(9));
lambda(10) = pipefun(pipe.e07,q(10));
lambda(13) = pipefun(pipe.e10,q(13));
lambda(14) = pipefun(pipe.e12,q(14));
lambda(16) = pipefun(pipe.e14,q(16));
lambda(19) = pipefun(pipe.e17,q(19));
lambda(20) = pipefun(pipe.e18,q(20));
lambda(21) = pipefun(pipe.e19,q(21));


end

