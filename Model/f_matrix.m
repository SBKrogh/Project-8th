%% Parameter for the f vector  

%Parameters that i sill need to define somewhere
%omega
%q(n)

%%% Parameters that at constant %%% 
%Parameters for the Grundfos UPMXL GEO 25-125 180 pump 
A_h0_1 = 1.2024; 
A_h1_1 = 0.0098; 
A_h2_1 = 0.0147; 
%Parameters for the Grundfos UPM2 25-60 180 pump 
A_h0_2 = 0.6921; 
A_h1_2 = -0.0177; 
A_h2_2 = 0.0179; 

k_v100 = 1; 

%%%%% PUMPS %%%%% 
% -a_h2*q^2 + a_h1*omega*q + a_h0*omega^2

%Grundfos UPMXL GEO 25-125 180 pump 
e1 = ((2/k_v100^2)-A_h2_1)*q(1)*abs(q(1)) + A_h1_1*omega*q(1) + A_h0_1*omega^2;
e8 = ((2/k_v100^2)-A_h2_1)*q(8)*abs(q(8)) + A_h1_1*omega*q(8) + A_h0_1*omega^2;
%Grundfos UPM2 25-60 180 pump 
e9 = ((2/k_v100^2)-A_h2_2)*q(9)*abs(q(9)) + A_h1_2*omega*q(9) + A_h0_2*omega^2;
e16 = ((2/k_v100^2)-A_h2_2)*q(16)*abs(q(16)) + A_h1_2*omega*q(16) + A_h0_2*omega^2;

%%%%% PIPES %%%%% 
% There are one unknow in the pipe model
% C_p * abs(q)*q - si

e2 = C_p(2) * abs(q(2))*q(2) - si(2);
e3 = C_p(3) * abs(q(3))*q(3) - si(3);
e4 = C_p(4) * abs(q(4))*q(4) - si(4);
e5 = C_p(5) * abs(q(5))*q(5) - si(5);
e6 = C_p(6) * abs(q(6))*q(6) - si(6);
e7 = C_p(7) * abs(q(7))*q(7) - si(7);
e10 = C_p(10) * abs(q(10))*q(10) - si(10);
e11 = C_p(11) * abs(q(11))*q(11) - si(11);
e12 = C_p(12) * abs(q(12))*q(12) - si(12);
e14 = C_p(14) * abs(q(14))*q(14) - si(14);
e17 = C_p(17) * abs(q(17))*q(17) - si(17);
e18 = C_p(18) * abs(q(18))*q(18) - si(18);
e19 = C_p(19) * abs(q(19))*q(19) - si(19);
e21 = C_p(21) * abs(q(21))*q(21) - si(21);
e23 = C_p(23) * abs(q(23))*q(23) - si(23);

%%%%% VALVES %%%%%
%C_v*q*abs(q)

e13 = q(13)*abs(q(13));
e15 = q(15)*abs(q(15));
e20 = q(20)*abs(q(20));
e22 = q(22)*abs(q(22));

% SETUP OF VECTOR % 

F = [
    e2;                 %e2 - Pipe
    e4;                 %e4 - Pipe
    e5;                 %e5 - Pipe
    e6;                 %e6 - Pipe
    e11;                %e11 - Pipe
    e21;                %e21 - Pipe
    e23;                %e23 - Pipe
%-------------------------------------------
    e1;                %e1 - Main pump 1
    e3;                 %e3 - Pipe
    e7;                 %e7 - Pipe
    e8;                 %e8 - Main pump 2
    e9;                 %e9 - PMA1 pump
    e10;                %e10 - Pipe
    e12;                %e12 - Pipe
    e13;                %e13 - Valve
    e14;                %e14 - Pipe
    e15;                %e15 - Valve
    e16;                %e16 - PMA2 pump
    e17;                %e17 - Pipe
    e18;                %e18 - Pipe
    e19;                %e19 - Pipe
    e20;                %e10 - Valve
    e22;                %e22 - Valve
    ]
