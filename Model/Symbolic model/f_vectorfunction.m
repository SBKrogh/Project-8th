clear all
close all
clc
%% Build up the f function
%Include the input to the system
U = ones(100,8);        %This should be defined in another file and then included

%Include all the parameter files 
matrices
elev_param
pipe_param
valve_param

%Define z as a vector of syms 
syms z1(t) z2(t) z3(t) z4(t) z5(t) z6(t) z7(t)
z= [z1(t); z2(t); z3(t); z4(t); z5(t); z6(t); z7(t)];

N = 23;
for i = 1:N
   f(:,i) = -pipe(Cp,i,B_1,U) - elev(delta_z,i,U) - valve(Cv,i,B_1,U) + dPpump(U,i);     
end

%% 
z_0 = zeros(23,1);

sul = linsolve(f,z_0)


%%
i = 1;
for i = 1:length(U)
    SolF = solve(f(i,:) == 0,z)
end

