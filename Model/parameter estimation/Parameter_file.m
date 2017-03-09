%% Parameter for the model 

% A vector containing the pressure drop for each compound have to be set up

%%% Parameters that at constant %%% 

g = 9.82; %m/s^2
ro = 1000; %kg/m^3
%Parameters for the Grundfos UPMXL GEO 25-125 180 pump 
A_h0_1 = 1.2024; 
A_h1_1 = 0.0098; 
A_h2_1 = 0.0147; 
%Parameters for the Grundfos UPM2 25-60 180 pump 
A_h0_2 = 0.6921; 
A_h1_2 = -0.0177; 
A_h2_2 = 0.0179; 





%%%%% PUMPS %%%%% 
%delta_p = -a_h2*q^2 + a_h1*omega*q + a_h0*omega^2

C2 = -a_h2*q^2 + a_h1*omega*q + a_h0*omega^2
C16 = 
C18 = 
C25 = 
C32 = 

%%%%% PIPES %%%%% 
% There are one unknow in the pipe model
% delta_p = J*q_dot + C_p * abs(q)*q + si

C4 = 
C8 =
C9_C10 =
C11 =
C12_C13 =
C14 =
C19 =
C21 =
C22 =
C23 =
C26 =
C28 =
C29 =
C30 =
C42 =

%%%%% VALVES %%%%%
%delta_p = C_v*q*abs(q)

C20 = 
C24 = 
C27 = 
C31 = 

%%%%% WT %%%%% 
%
C33 = 1/C_H *q ;


% SETUP OF VECTOR % 

F = [C2;                %Main pump 1
    C4;                 %Pipe
    C8;                 %Pipe
    C9_C10;             %Pipe
    C11;                %Pipe
    C12_C13;            %Pipe
    C14;                %Pipe
    C16;                %Main pump 2
    C18;                %PMA1 pump
    C19;                %Pipe
    C20;                %Valve
    C21;                %Pipe
    C22;                %Pipe
    C23;                %Pipe
    C24;                %Valve
    C25;                %PMA2 pump
    C26;                %Pipe
    C27;                %Valve
    C28;                %Pipe
    C29;                %Pipe
    C30;                %Pipe
    C31;                %Valve
    C32;                %WT Pump
    C33;                %WT
    C42;                %Pipe
    ]
