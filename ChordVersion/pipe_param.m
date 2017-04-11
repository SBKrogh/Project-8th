%Pipe parameters
L=[
    5;                 %e2 - Pipe
    20;                %e4 - Pipe
    10;                %e5 - Pipe
    20;                %e6 - Pipe
    0;                 %e11 - Valve
    2;                 %e21 - Pipe
    15;                %e23 - Pipe
%-----------------------------------------
    0;                 %e1 - Main pump 1
    10;                %e3 - Pipe
    5;                 %e7 - Pipe
    0;                 %e8 - Main pump 2
    0;                 %e9 - PMA1 pump
    2;                 %e10 - Pipe
    1;                 %e12 - Pipe
    1;                 %e13 - Pipe
    2;                 %e14 - Pipe
    0;                 %e15 - Valve
    0;                 %e16 - PMA2 pump
    3;                 %e17 - Pipe
    0;                 %e18 - Valve
    1;                 %e19 - Pipe
    1;                 %e20 - Pipe
    0;                 %e22 - Valve
    ];

D=[
    0.020;             %e2 - Pipe
    0.020;             %e4 - Pipe
    0.020;             %e5 - Pipe
    0.020;             %e6 - Pipe
    1;                 %e11 - Valve
    0.010;             %e21 - Pipe
    0.010;             %e23 - Pipe
%----------------------------------------
    1;                %e1 - Main pump 1
    0.020;             %e3 - Pipe
    0.020;             %e7 - Pipe
    1;                 %e8 - Main pump 2
    1;                 %e9 - PMA1 pump
    0.010;             %e10 - Pipe
    0.010;             %e12 - Pipe
    0.010;             %e13 - Pipe
    0.010;             %e14 - Pipe
    1;                 %e15 - Valve
    1;                 %e16 - PMA2 pump
    0.010;             %e17 - Pipe
    1;                 %e18 - Valve
    0.010;             %e19 - Pipe
    0.010;             %e20 - Pipe
    1;                 %e22 - Valve
    ];

Cp = ones(1,23)';
Cp(8) = 0;
Cp(11) = 0;
Cp(12) = 0;
Cp(15) = 0;
Cp(17) = 0;
Cp(18) = 0;
Cp(22) = 0;
Cp(23) = 0;
