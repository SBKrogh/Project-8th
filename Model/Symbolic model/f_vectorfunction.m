function [dx, y] = f_vectorfunction(Cp,U)

% Build up the f function
%Include the input to the system
% U = ones(20,8);        %This should be defined in another file and then included

%Include all the parameter files 
matrices
elev_param
pipe_param
Cv = valve_param(U);

%Define z as a vector of syms 
syms z1 z2 z3 z4 z5 z6 z7
z= [z1; z2; z3; z4; z5; z6; z7];
k = 0;
N = 23;
for i = 1:N
   f(:,i) = -pipe(Cp,i,B_1,U,z,k,[]) - elev(delta_z,i,U,k) - valve(Cv,i,B_1,z,k,[]) + dPpump(U,i,[],k);     
end

%
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

% Obtain de pressure difference

z = [z1  z2  z3  z4  z5  z6  z7];   % Redefine z with real values
k = 1;  % Some flag

for j = 1:length(U) 
    
for i = 1:N
   f_r(:,i) = -pipe(Cp,i,B_1,U,z,k,j) - elev(delta_z,i,U,k) - valve(Cv,i,B_1,z,k,j) + dPpump(U,i,j,k);     
end

 DeltaP (j,:) = f_r;

end

% Set the output 

y = zeros(length(U),8);

y(:,1) = DeltaP(:,8);     % Edge 1 Component C2
y(:,2) = DeltaP(:,11);    % Edge 8 Component 16
y(:,3) = DeltaP(:,12) + DeltaP(:,13) + DeltaP(:,16) + DeltaP(:,17);    % Edge 9 Component 18 & Edge 10 Component 19 & Edge 14 Component 23 & Edge 15 Component 24
y(:,4) = DeltaP(:,18) + DeltaP(:,19) + DeltaP(:,6) + DeltaP(:,23);    % Edge 16 Component 25 & Edge 17 Component 26 & Edge 21 Component 30 & Edge 22 Component 31
y(:,5) = DeltaP(:,17);    % Edge 15 Component 24
y(:,6) = DeltaP(:,15) + DeltaP(:,14);    % Edge 13 Component 20 & Edge 12 Component 21
y(:,7) = DeltaP(:,23);    % Edge 22 Component 31
y(:,8) = DeltaP(:,21) + DeltaP(:,22);    % Edge 19 Component 28 & Edge 20 Component 27

dx = [z1  z2  z3  z4  z5  z6  z7];      % States
end
