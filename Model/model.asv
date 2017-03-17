clear all; 
clc;
%%%%%%% Model %%%%%%%

%Define the input to the pumps 
omega = [1;1;0;0];              %omega(1) main pump 1(C2) omega(2)main pump 1(C16)
                                %omega(3) PMA pump 1(C18) omega(4)PMA pump 1(C25)

%Test values: 
%B_1 = zeros(7,23);
C_p = ones(1,23);              

%Including parameters
HandBmatrix                     %System matrices 
initial_condition               %Define q and z at time 0
inertia_parameters              
elevation_parameters            

%%The Elevation Function can be used to get the si matrix 
si = ElevationFunc(delta_z);

f_matrix                        %Define the F vector 


%%The inertia function can be used to get inertia matrices 

J = inertiaFunc(L,D);

%Setting up state-space model

dZ = B_1 * J * B_1' * B_1 * F ;

time = [0 1];
y0 = q;

[t,z] = ode45(@(t,q) dZ,time,y0);