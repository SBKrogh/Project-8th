%% Initial Values
clear all
clc
pipe_param;

%  pipe.e02.q0 = 0.5;
%  pipe.e04.q0 = 0.5;
%  pipe.e05.q0 = 0.5;
%  pipe.e06.q0 = 0.5;
%  pipe.e11.q0 = 0.5;
%  pipe.e21.q0 = 0.5;
%  pipe.e23.q0 = 0.5;

x0 = [0.000000000113370
   0.273490771269440
   0.000000000000028
   0.288559410641489
   0.000266688545476
   1.837629665797334
   1.832488026457060];

Ts = 0.05;

%% load data from the lab
% load('short_transition_data.mat');
% % u(5:end) = 10^5*u(5:end);
% % y = 10^5 * y;
% 
% z = iddata(y,u,Ts,'Name', 'Data from Lab');
% z.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% % z.Tstart = 0;

load('Closing_valve.mat')
T = Outputs.time;

u = zeros(length(T),8);
% Valves inputs
u(:,1) = Outputs3.signals.values(:,1);
u(:,2) = Outputs3.signals.values(:,2);
u(:,3) = Outputs3.signals.values(:,3);
u(:,4) = Outputs3.signals.values(:,4);
% PMA inputs
u(:,5) = Outputs1.signals.values(:,1);
u(:,6) = Outputs1.signals.values(:,2);
u(:,7) = Outputs1.signals.values(:,3);
u(:,8) = Outputs1.signals.values(:,4);

y = zeros(length(T),8);
% Ring pressures
y(:,1) = Outputs2.signals.values(:,1);
y(:,2) = Outputs2.signals.values(:,2);
y(:,3) = Outputs2.signals.values(:,3);
y(:,4) = Outputs2.signals.values(:,4);
%Pma pressures
y(:,5) = Outputs.signals.values(:,1);
y(:,6) = Outputs.signals.values(:,2);
y(:,7) = Outputs.signals.values(:,3);
y(:,8) = Outputs.signals.values(:,4);

Data1 = 436;
Data2 = 1560;
Data3 = 2700;
Data4 = 3960;
Offshet = 40;

u1 = [ u(Data1:Data1+Offshet,1)' u(Data2:Data2+Offshet,1)' u(Data3:Data3+Offshet,1)' u(Data4:Data4+Offshet,1)';...
u(Data1:Data1+Offshet,2)' u(Data2:Data2+Offshet,2)' u(Data3:Data3+Offshet,2)' u(Data4:Data4+Offshet,2)';...
u(Data1:Data1+Offshet,3)' u(Data2:Data2+Offshet,3)' u(Data3:Data3+Offshet,3)' u(Data4:Data4+Offshet,3)';...
u(Data1:Data1+Offshet,4)' u(Data2:Data2+Offshet,4)' u(Data3:Data3+Offshet,4)' u(Data4:Data4+Offshet,4)';...
u(Data1:Data1+Offshet,5)' u(Data2:Data2+Offshet,5)' u(Data3:Data3+Offshet,5)' u(Data4:Data4+Offshet,5)';...
u(Data1:Data1+Offshet,6)' u(Data2:Data2+Offshet,6)' u(Data3:Data3+Offshet,6)' u(Data4:Data4+Offshet,6)';...
u(Data1:Data1+Offshet,7)' u(Data2:Data2+Offshet,7)' u(Data3:Data3+Offshet,7)' u(Data4:Data4+Offshet,7)';...
u(Data1:Data1+Offshet,8)' u(Data2:Data2+Offshet,8)' u(Data3:Data3+Offshet,8)' u(Data4:Data4+Offshet,8)']';

y1 = [ y(Data1:Data1+Offshet,1)' y(Data2:Data2+Offshet,1)' y(Data3:Data3+Offshet,1)' y(Data4:Data4+Offshet,1)';...
y(Data1:Data1+Offshet,2)' y(Data2:Data2+Offshet,2)' y(Data3:Data3+Offshet,2)' y(Data4:Data4+Offshet,2)';...
y(Data1:Data1+Offshet,3)' y(Data2:Data2+Offshet,3)' y(Data3:Data3+Offshet,3)' y(Data4:Data4+Offshet,3)';...
y(Data1:Data1+Offshet,4)' y(Data2:Data2+Offshet,4)' y(Data3:Data3+Offshet,4)' y(Data4:Data4+Offshet,4)';...
y(Data1:Data1+Offshet,5)' y(Data2:Data2+Offshet,5)' y(Data3:Data3+Offshet,5)' y(Data4:Data4+Offshet,5)';...
y(Data1:Data1+Offshet,6)' y(Data2:Data2+Offshet,6)' y(Data3:Data3+Offshet,6)' y(Data4:Data4+Offshet,6)';...
y(Data1:Data1+Offshet,7)' y(Data2:Data2+Offshet,7)' y(Data3:Data3+Offshet,7)' y(Data4:Data4+Offshet,7)';...
y(Data1:Data1+Offshet,8)' y(Data2:Data2+Offshet,8)' y(Data3:Data3+Offshet,8)' y(Data4:Data4+Offshet,8)']';
% 
z = iddata(y1,u1,Ts,'Name', 'Data from Lab');
z.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z.OutputName = { 'Node 2','Node 7','Node 4','Node 5' ...
          'Node 11', 'Node10', 'Node 16','Node 15'};
z.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
z.Tstart = 0;
% 
% %% Remove transient and first plot
% DataStart=324;
% DataStop=424;
% 
% u1 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
%     u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
% y1 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
%     y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];
% 
% z1 = iddata(y1,u1,Ts,'Name', 'Data from Lab');
% z1.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z1.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z1.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z1.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% z1.Tstart = 0;
% 
% 
% %% Remove transient and second plot
% 
% DataStart=1414;
% DataStop=1514;
% 
% u2 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
%     u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
% y2 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
%     y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];
% 
% z2 = iddata(y2,u2,Ts,'Name', 'Data from Lab');
% z2.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z2.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z2.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z2.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% z2.Tstart = 0;
% 
% %% %% Remove transient and second plot
% 
% DataStart=2733;
% DataStop=2833;
% 
% u3 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
%     u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
% y3 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
%     y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];
% 
% z3 = iddata(y3,u3,Ts,'Name', 'Data from Lab');
% z3.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z3.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z3.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z3.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% z3.Tstart = 0;
% 
% %% %% Remove transient and second plot
% 
% DataStart=3854;
% DataStop=3954;
% 
% u4 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
%     u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
% y4 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
%     y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];
% 
% z4 = iddata(y4,u4,Ts,'Name', 'Data from Lab');
% z4.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
% z4.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
% z4.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
%     'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
% z4.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
% z4.Tstart = 0;

%% 
% z_gather = merge(z1, z2 , z3, z4);
% init_in = [x0 x0 x0 x0];
%% setup of the ident model
FileName      = 'zdot';       % File describing the model structure.
Order         = [8 8 7];           % Model orders [ny nu nx].

Parameters    = {[ pipe.e02.Cp;  pipe.e04.Cp;  pipe.e05.Cp; ...
     pipe.e06.Cp;  pipe.e11.Cp;  pipe.e21.Cp;  pipe.e23.Cp;  pipe.e03.Cp;  pipe.e07.Cp;...
     pipe.e10.Cp;  pipe.e12.Cp;  pipe.e14.Cp;  pipe.e17.Cp;  pipe.e18.Cp;  pipe.e19.Cp]}; % Initial parameters. Np = 15.

InitialStates = x0;            % Initial initial states.
nlgr = idnlgrey(FileName, Order, Parameters, InitialStates,0, ...
                'Name', 'First Simulation');
    

nlgr.Parameters.Minimum(1:15) = 0;  % nlgr.Parameters.Maximum(1:15) = 10;
nlgr.InitialStates(1).Minimum = 0;
nlgr.InitialStates(2).Minimum = 0;
nlgr.InitialStates(3).Minimum = 0;
nlgr.InitialStates(4).Minimum = 0;
nlgr.InitialStates(5).Minimum = 0;
nlgr.InitialStates(6).Minimum = 0;
nlgr.InitialStates(7).Minimum = 0;

% nlgr.InitialStates(1).Fixed = false;
% nlgr.InitialStates(2).Fixed = false;
% nlgr.InitialStates(3).Fixed = false;
% nlgr.InitialStates(4).Fixed = false;
% nlgr.InitialStates(5).Fixed = false;
% nlgr.InitialStates(6).Fixed = false;
% nlgr.InitialStates(7).Fixed = false;

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
          'OutputName', { 'Node 2','Node 7','Node 4','Node 5' ...
          'Node 11', 'Node10', 'Node 16','Node 15'},...
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

% disp('The basic information about the model.')
% size(nlgr)
% present(nlgr)
%  opt = compareOptions;
%  opt.InitialCondition = x0;
 datestr(now)
%% Estimation
% opt = nlgreyestOptions('Display','on');
% opt.SearchOption.MaxIter = 18;

% sys = nlgreyest(z, nlgr,opt);
nlgrF = pem(z, nlgr,'Display', 'on' , 'InitialState', x0 );
nlgrF.Name = 'New Estimation';
% nlgr.Report
% fprintf('\n\nThe search termination condition:\n')
% nlgr.Report.Termination
compare(z, nlgr, nlgrF, 'init', 'm');
datestr(now)
p=nlgrF.Parameters.Value % save the new parameters
