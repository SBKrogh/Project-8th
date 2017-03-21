%Pump parameters
%CONSTANTS
%Parameters for the Grundfos UPMXL GEO 25-125 180 pump 
A_h01 = 1.2024; 
A_h11 = 0.0098; 
A_h21 = 0.0147; 
%Parameters for the Grundfos UPM2 25-60 180 pump 
A_h02 = 0.6921; 
A_h12 = -0.0177; 
A_h22 = 0.0179; 

kv100 = 1; 

omega_main = [zeros(1,7) 1 0 0 1 0 zeros(1,5) 0 0 0 0 0 0]';
omega_side = [zeros(1,7) 0 0 0 0 1 zeros(1,5) 1 0 0 0 0 0]';
flag =       [zeros(1,7) 1 0 0 1 1 zeros(1,5) 1 0 0 0 0 0]';

