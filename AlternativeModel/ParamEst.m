clear all
clc
close all
%% Initial Values

pipe_param;

 pipe.e02.q0 = 0;
 pipe.e04.q0 = 0;
 pipe.e05.q0 = 0;
 pipe.e06.q0 = 0;
 pipe.e11.q0 = 0;
 pipe.e21.q0 = 0;
 pipe.e23.q0 = 0;

x0 = [  pipe.e02.q0;   pipe.e04.q0;  pipe.e05.q0;  pipe.e06.q0;  pipe.e11.q0;...
     pipe.e21.q0;  pipe.e23.q0];

Ts = 0.05;

%% load data from the lab
load('15sekdata.mat');
u(5:end) = 10^5*u(5:end);
y = 10^5 * y;

z = iddata(y,u,Ts,'Name', 'Data from Lab');
z.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
    'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
z.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
z.Tstart = 0;

% u1 = [ u(1:101,1) u(1:101,2) u(1:101,3) u(1:101,4) u(1:101,5) u(1:101,6) u(1:101,7) u(1:101,8)];
% y1 = [ y(1:101,1) y(1:101,2) y(1:101,3) y(1:101,4) y(1:101,5) y(1:101,6) y(1:101,7) y(1:101,8)];
% z1 = iddata(y1,u1,Ts,'Name', 'Data from Lab');
% z1.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z1.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z1.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z1.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% z1.Tstart = 0;
% 
% %%
% u3 = [ u(102:201,1) u(102:201,2) u(102:201,3) u(102:201,4) u(102:201,5) u(102:201,6) u(102:201,7) u(102:201,8)];
% y3 = [ y(102:201,1) y(102:201,2) y(102:201,3) y(102:201,4) y(102:201,5) y(102:201,6) y(102:201,7) y(102:201,8)];
% z2 = iddata(y3,u3,Ts,'Name', 'Data from Lab');
% z2.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z2.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z2.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z2.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% z2.Tstart = 0;
% 
% %%
% u3 = [ u(201:end,1) u(201:end,2) u(201:end,3) u(201:end,4) u(201:end,5) u(201:end,6) u(201:end,7) u(201:end,8)];
% y3 = [ y(201:end,1) y(201:end,2) y(201:end,3) y(201:end,4) y(201:end,5) y(201:end,6) y(201:end,7) y(201:end,8)];
% z3 = iddata(y3,u3,Ts,'Name', 'Data from Lab');
% z3.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z3.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z3.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z3.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% z3.Tstart = 0;
% 
% z = merge(z1, z2, z3);
% init_in = [ x0 x0 x0];
%% setup of the ident model
FileName      = 'zdot';       % File describing the model structure.
Order         = [8 8 7];           % Model orders [ny nu nx].
Parameters    = {[ pipe.e02.Cp;  pipe.e04.Cp;  pipe.e05.Cp; ...
     pipe.e06.Cp;  pipe.e11.Cp;  pipe.e21.Cp;  pipe.e23.Cp;  pipe.e03.Cp;  pipe.e07.Cp;...
     pipe.e10.Cp;  pipe.e12.Cp;  pipe.e14.Cp;  pipe.e17.Cp;  pipe.e18.Cp;  pipe.e19.Cp]}; % Initial parameters. Np = 15.

InitialStates = x0;            % Initial initial states.
nlgr = idnlgrey(FileName, Order, Parameters, InitialStates,0.05, ...
                'Name', 'First Simulation');
    

nlgr.Parameters.Minimum(1:15) = 0;
% nlgr.Parameters.Maximum(1:15) = 10;
nlgr.Algorithm.MaxIter=10;
%%
%
% In practice, there are disturbances that affect the outputs. An
% |idnlgrey| model does not explicitly model the disturbances, but assumes
% that these are just added to the output(s). Thus, |idnlgrey| models are
% equivalent to Output-Error (OE) models. Without a noise model, past
% outputs do not influence prediction of future outputs, which means that
% predicted output for any prediction horizon k coincide with simulated
% outputs.
%%
%
% 3. Specify input and output names, and units.
set(nlgr, 'InputName', {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'},...
          'InputUnit',{ '-','-','-','-','bar', 'bar', 'bar','bar'},...
          'OutputName', { 'C04relp','c18relp','c25relp','C16relp' ...
          'c21-22relp', 'c23relp', 'c28-29relp','c30relp'},...
          'OutputUnit', {'bar','bar','bar','bar', 'bar', 'bar','bar','bar'},...                        
          'TimeUnit', 's');
%%
% 
% Specify names and units of the initial states and parameters.
setinit(nlgr, 'Name', {'e02q' 'e04q' 'e05q' 'e06q' 'e11q' 'e21q' 'e23q'});
setinit(nlgr, 'Unit', {'m^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h'});
setpar(nlgr, 'Name', {'Cp'});
setpar(nlgr, 'Unit', {'-'});
% nlgr.Parameters.Minimum(:) = zeros(15, 1) ;

disp('The basic information about the model.')
size(nlgr)
present(nlgr)
 opt = compareOptions;
 opt.InitialCondition = x0;
datestr(now)
%% Estimation
% sys = nlgreyest(z, nlgr,opt)
nlgrF = pem(z, nlgr,'Display', 'on' , 'InitialState', x0 );
nlgrF.Name = 'New Estimation';
nlgr.Report
fprintf('\n\nThe search termination condition:\n')
nlgr.Report.Termination
compare(z, nlgr, nlgrF, 'init', 'm');
datestr(now)
p=nlgrF.Parameters.Value % save the new parameters
