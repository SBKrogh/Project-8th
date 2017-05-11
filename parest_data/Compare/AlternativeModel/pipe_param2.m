% Pipe Lengths 

    pipe.e02.L = 5;                 %e2 - Pipe
    pipe.e04.L = 20;                %e4 - Pipe
    pipe.e05.L = 10;                %e5 - Pipe
    pipe.e06.L = 20;                %e6 - Pipe
    pipe.e11.L = 1;                 %e11 - Pipe
    pipe.e21.L = 2;                 %e21 - Pipe
    pipe.e23.L = 2;                 %e23 - Pipe
%-----------------------------------------
    pipe.e01.L = 0;                 %e1 - Main pump 1
    pipe.e03.L = 10;                %e3 - Pipe
    pipe.e07.L = 9;                 %e7 - Pipe
    pipe.e08.L = 0;                 %e8 - Main pump 2
    pipe.e09.L = 0;                 %e9 - PMA1 pump
    pipe.e10.L = 2;                 %e10 - Pipe
    pipe.e12.L = 1;                 %e12 - Pipe
    pipe.e13.L = 0;                 %e13 - Valve
    pipe.e14.L = 2;                 %e14 - Pipe
    pipe.e15.L = 0;                 %e15 - Valve
    pipe.e16.L = 0;                 %e16 - PMA2 pump
    pipe.e17.L = 3;                 %e17 - Pipe
    pipe.e18.L = 1;                 %e18 - Pipe
    pipe.e19.L = 1;                 %e19 - Pipe
    pipe.e20.L = 0;                 %e20 - Valve
    pipe.e22.L = 0;                 %e22 - Valve
   
 % Pipe Diameters

   pipe.e02.D =  0.020;             %e2 - Pipe
   pipe.e04.D =  0.020;             %e4 - Pipe
   pipe.e05.D =  0.020;             %e5 - Pipe
   pipe.e06.D =  0.020;             %e6 - Pipe
   pipe.e11.D =  0.010;             %e11 - Pipe
   pipe.e21.D =  0.010;             %e21 - Pipe
   pipe.e23.D =  0.010;             %e23 - Pipe
%----------------------------------------
   pipe.e01.D =  0;                 %e1 - Main pump 1
   pipe.e03.D =  0.020;             %e3 - Pipe
   pipe.e07.D =  0.020;             %e7 - Pipe
   pipe.e08.D =  0;                 %e8 - Main pump 2
   pipe.e09.D =  0;                 %e9 - PMA1 pump
   pipe.e10.D =  0.010;             %e10 - Pipe
   pipe.e12.D =  0.010;             %e12 - Pipe
   pipe.e13.D =  0;                 %e13 - Valve
   pipe.e14.D =  0.010;             %e14 - Pipe
   pipe.e15.D =  0;                 %e15 - Valve
   pipe.e16.D =  0;                 %e16 - PMA2 pump
   pipe.e17.D =  0.010;             %e17 - Pipe
   pipe.e18.D =  0.010;             %e18 - Pipe
   pipe.e19.D =  0.010;             %e19 - Pipe
   pipe.e20.D =  0;                 %e20 - Valve
   pipe.e22.D =  0;                 %e22 - Valve
    
% Elevation
   pipe.e02.Z =  0;             %e2 - pipe
   pipe.e04.Z =  0;             %e4 - pipe
   pipe.e05.Z =  0;             %e5 - pipe
   pipe.e06.Z =  0;             %e6 - pipe
   pipe.e11.Z =  0;             %e11 - pipe
   pipe.e21.Z =  0;             %e21 - pipe
   pipe.e23.Z =  0.5;             %e23 - pipe
%----------------------------------------
   pipe.e01.Z =  0;             %e1 - Main pump 1
   pipe.e03.Z =  0;             %e3 - pipe
   pipe.e07.Z =  0;             %e7 - pipe
   pipe.e08.Z =  0;             %e8 - Main pump 2
   pipe.e09.Z =  0;             %e9 - PMA1 pump
   pipe.e10.Z =  0;             %e10 - pipe
   pipe.e12.Z =  0;             %e12 - pipe
   pipe.e13.Z =  0;             %e13 - Valve
   pipe.e14.Z =  0;             %e14 - pipe
   pipe.e15.Z =  0;             %e15 - Valve
   pipe.e16.Z =  0;             %e16 - PMA2 pump
   pipe.e17.Z =  0.5;           %e17 - pipe
   pipe.e18.Z =  0;             %e18 - pipe
   pipe.e19.Z =  0;             %e19 - pipe
   pipe.e20.Z =  0;             %e20 - Valve
   pipe.e22.Z =  0;             %e22 - Valve
   
   % Kf values 
   pipe.e02.kf =  4.42;             %e2 - pipe
   pipe.e04.kf =  3.11+0.51;        %e4 - pipe
   pipe.e05.kf =  1.81;             %e5 - pipe
   pipe.e06.kf =  3.63+0.51;        %e6 - pipe
   pipe.e11.kf =  7.68;             %e11 - pipe
   pipe.e21.kf =  2.10;             %e21 - pipe
   pipe.e23.kf =  2.77;             %e23 - pipe
%----------------------------------------
   pipe.e01.kf =  0;                %e1 - Main pump 1
   pipe.e03.kf =  3.92;             %e3 - pipe
   pipe.e07.kf =  1.81;             %e7 - pipe
   pipe.e08.kf =  0;                %e8 - Main pump 2
   pipe.e09.kf =  0;                %e9 - PMA1 pump
   pipe.e10.kf =  3.57;             %e10 - pipe
   pipe.e12.kf =  1.46;             %e12 - pipe
   pipe.e13.kf =  0;                %e13 - Valve
   pipe.e14.kf =  2.55;             %e14 - pipe
   pipe.e15.kf =  0;                %e15 - Valve
   pipe.e16.kf =  0;                %e16 - PMA2 pump
   pipe.e17.kf =  2.77;             %e17 - pipe
   pipe.e18.kf =  2.26;             %e18 - pipe
   pipe.e19.kf =  0.81;             %e19 - pipe
   pipe.e20.kf =  0;                %e20 - Valve
   pipe.e22.kf =  0;                %e22 - Valve
 
    % e roughness 
   pipe.e02.e =  0.00001;             %e2 - pipe
   pipe.e04.e =  0.00001;        %e4 - pipe
   pipe.e05.e =  0.00001;             %e5 - pipe
   pipe.e06.e =  0.00001;        %e6 - pipe
   pipe.e11.e =  0.000007;             %e11 - pipe
   pipe.e21.e =  0.000007;             %e21 - pipe
   pipe.e23.e =  0.000007;             %e23 - pipe
%----------------------------------------
   pipe.e01.e =  0;                %e1 - Main pump 1
   pipe.e03.e =  0.00001;             %e3 - pipe
   pipe.e07.e =  0.00001;             %e7 - pipe
   pipe.e08.e =  0;                %e8 - Main pump 2
   pipe.e09.e =  0;                %e9 - PMA1 pump
   pipe.e10.e =  0.000007;             %e10 - pipe
   pipe.e12.e =  0.000007;             %e12 - pipe
   pipe.e13.e =  0;                %e13 - Valve
   pipe.e14.e =  0.000007;             %e14 - pipe
   pipe.e15.e =  0;                %e15 - Valve
   pipe.e16.e =  0;                %e16 - PMA2 pump
   pipe.e17.e =  0.000007;             %e17 - pipe
   pipe.e18.e =  0.000007;             %e18 - pipe
   pipe.e19.e =  0.000007;             %e19 - pipe
   pipe.e20.e =  0;                %e20 - Valve
   pipe.e22.e =  0;                %e22 - Valve

%  % Friction in the pipes
% 
%  pipe.e02.Cp = calcFric(pipe.e02);
%  pipe.e04.Cp = calcFric(pipe.e04);
%  pipe.e05.Cp = calcFric(pipe.e05);
%  pipe.e06.Cp = calcFric(pipe.e06);
%  pipe.e11.Cp = calcFric(pipe.e11);
%  pipe.e21.Cp = calcFric(pipe.e21);
%  pipe.e23.Cp = calcFric(pipe.e23);
%  pipe.e03.Cp = calcFric(pipe.e03);
%  pipe.e07.Cp = calcFric(pipe.e07);
%  pipe.e10.Cp = calcFric(pipe.e10);
%  pipe.e12.Cp = calcFric(pipe.e12);
%  pipe.e14.Cp = calcFric(pipe.e14);
%  pipe.e17.Cp = calcFric(pipe.e17);
%  pipe.e18.Cp = calcFric(pipe.e18);
%  pipe.e19.Cp = calcFric(pipe.e19);
% %----------------------------------------
%  pipe.e01.Cp = 0;
%  pipe.e08.Cp = 0;
%  pipe.e09.Cp = 0;
%  pipe.e13.Cp = 0;
%  pipe.e15.Cp = 0;
%  pipe.e16.Cp = 0;
%  pipe.e20.Cp = 0;
%  pipe.e22.Cp = 0;
