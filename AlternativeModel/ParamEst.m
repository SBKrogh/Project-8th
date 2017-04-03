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
load('parest_test_data.mat');
z = iddata(y,u,Ts,'Name', 'Data from Lab');
z.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
    'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
z.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
z.Tstart = 0;

%% setup of the ident model
FileName      = 'zdot';       % File describing the model structure.
Order         = [8 8 7];           % Model orders [ny nu nx].
Parameters    = {[ pipe.e02.Cp;  pipe.e04.Cp;  pipe.e05.Cp; ...
     pipe.e06.Cp;  pipe.e11.Cp;  pipe.e21.Cp;  pipe.e23.Cp;  pipe.e03.Cp;  pipe.e07.Cp;...
     pipe.e10.Cp;  pipe.e12.Cp;  pipe.e14.Cp;  pipe.e17.Cp;  pipe.e18.Cp;  pipe.e19.Cp]}; % Initial parameters. Np = 15.

InitialStates = x0;            % Initial initial states.
nlgr = idnlgrey(FileName, Order, Parameters, InitialStates, 0, ...
                'Name', 'Param-Estimation');

nlgr.Algorithm.MaxIter=5;
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

%% Estimation
% sys = nlgreyest(z, nlgr,opt)
nlgrF = pem(z, nlgr,'Display', 'on' , 'InitialState', x0 );
nlgrF.Name = 'ParameterEstimate';
nlgr.Report
fprintf('\n\nThe search termination condition:\n')
nlgr.Report.Termination
% compare(z, nlgr, nlgrF, 'init', 'm');
% datestr(now)
% p=nlgrF.Parameters.Value % save the new parameters
