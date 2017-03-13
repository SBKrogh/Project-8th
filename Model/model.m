clear all; 
clc;
%Model 

%Including parameters
inertia_parameters
HandBmatrix

%These function can be used to get matrices 

J = inertiaFunc(L,D);

%Setting up state-space model

