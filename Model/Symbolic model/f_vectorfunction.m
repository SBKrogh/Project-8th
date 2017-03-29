clear all
close all
clc
%% Build up the f function
%Include the input to the system
U = ones(20,8);        %This should be defined in another file and then included

%Include all the parameter files 
matrices
elev_param
pipe_param
valve_param

%Define z as a vector of syms 
syms z1 z2 z3 z4 z5 z6 z7
z= [z1; z2; z3; z4; z5; z6; z7];

N = 23;
for i = 1:N
   f(:,i) = -pipe(Cp,i,B_1,U,z) - elev(delta_z,i,U) - valve(Cv,i,B_1,U,z) + dPpump(U,i);     
end

%%
warning('off','all')

for i = 1:length(U)
    SolF(:,i) = solve(B_1*f(i,:)' == 0,z);
    z1(i,:) = double(SolF(i).z1);
    z2(i,:) = double(SolF(i).z2);
    z3(i,:) = double(SolF(i).z3);
    z4(i,:) = double(SolF(i).z4);
    z5(i,:) = double(SolF(i).z5);
    z6(i,:) = double(SolF(i).z6);
    z7(i,:) = double(SolF(i).z7);

end

warning('on','all')

display('Solver finished')