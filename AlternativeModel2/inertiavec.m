function [ Jgraph ] = inertiavec( pipe )
%INERTIAVEC Summary of this function goes here
%   Detailed explanation goes here
J = zeros(23,1);
J(1)  = inertiafun(pipe.e02 );
J(2)  = inertiafun(pipe.e04 );
J(3)  = inertiafun(pipe.e05 );
J(4)  = inertiafun(pipe.e06 );
J(5)  = inertiafun(pipe.e11 );
J(6)  = inertiafun(pipe.e21 );
J(7)  = inertiafun(pipe.e23 );
J(9)  = inertiafun(pipe.e03 );
J(10) = inertiafun(pipe.e07 );
J(13) = inertiafun(pipe.e10 );
J(14) = inertiafun(pipe.e12 );
J(16) = inertiafun(pipe.e14 );
J(19) = inertiafun(pipe.e17 );
J(20) = inertiafun(pipe.e18 );
J(21) = inertiafun(pipe.e19 );

Jgraph = diag(J);

end

