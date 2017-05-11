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

Ts = 0.05;
%% Remove transient and first plot
DataStart=324;
DataStop=1155;

u1 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
    u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
y1 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
    y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];

z1 = iddata(y1,u1,Ts,'Name', 'Data from Lab');
z1.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z1.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z1.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
    'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
z1.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
z1.Tstart = 0;


%% Remove transient and second plot

DataStart=1414;
DataStop=2245;

u2 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
    u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
y2 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
    y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];

z2 = iddata(y2,u2,Ts,'Name', 'Data from Lab');
z2.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z2.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z2.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
    'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
z2.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
z2.Tstart = 0;

%% %% Remove transient and second plot

DataStart=2733;
DataStop=3564;

u3 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
    u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
y3 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
    y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];

z3 = iddata(y3,u3,Ts,'Name', 'Data from Lab');
z3.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z3.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z3.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
    'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
z3.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
z3.Tstart = 0;

%% %% Remove transient and second plot

DataStart=3854;
DataStop=4685;

u4 = [ u(DataStart:DataStop,1) u(DataStart:DataStop,2) u(DataStart:DataStop,3) u(DataStart:DataStop,4) ...
    u(DataStart:DataStop,5) u(DataStart:DataStop,6) u(DataStart:DataStop,7) u(DataStart:DataStop,8)];
y4 = [ y(DataStart:DataStop,1) y(DataStart:DataStop,2) y(DataStart:DataStop,3) y(DataStart:DataStop,4) ...
    y(DataStart:DataStop,5) y(DataStart:DataStop,6) y(DataStart:DataStop,7) y(DataStart:DataStop,8)];

z4 = iddata(y4,u4,Ts,'Name', 'Data from Lab');
z4.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z4.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z4.OutputName = { 'C04relp','c18relp','c25relp','C16relp' ...
    'c21-22relp', 'c23relp', 'c28-29relp','c30relp'};
z4.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};
z4.Tstart = 0;

%% 
z_gather = merge( z1, z2 , z3, z4);

