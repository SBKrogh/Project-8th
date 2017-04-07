load('Closing_valve.mat')
T = Outputs.time;

u = zeros(size(T),8);
% Valves inputs
u(1) = Outputs3.signals.values(:,1);
u(2) = Outputs3.signals.values(:,2);
u(3) = Outputs3.signals.values(:,3);
u(4) = Outputs3.signals.values(:,4);
% PMA inputs
u(5) = Outputs1.signals.values(:,1);
u(6) = Outputs1.signals.values(:,2);
u(7) = Outputs1.signals.values(:,3);
u(8) = Outputs1.signals.values(:,4);

y = zeros(size(T),8);
% Ring pressures
y(1) = Outputs2.signals.values(:,1);
y(2) = Outputs2.signals.values(:,2);
y(3) = Outputs2.signals.values(:,3);
y(4) = Outputs2.signals.values(:,4);
%Pma pressures
y(5) = Outputs.signals.values(:,1);
y(6) = Outputs.signals.values(:,2);
y(7) = Outputs.signals.values(:,3);
y(8) = Outputs.signals.values(:,4);
