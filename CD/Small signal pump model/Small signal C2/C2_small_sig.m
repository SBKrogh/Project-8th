%clc; close all; clear all;
data = load('pump.mat');
data1 = load('Pump_ref.mat');

figure
reduce_plot(data.pump_pressure(1,:),data.pump_pressure(2,:))
% hold on 
% plot(data.pump_pressure(1,:),data.pump_pressure(3,:))
% hold on 
% plot(data.pump_pressure(1,:),data.pump_pressure(4,:))
% hold on
% plot(data.pump_pressure(1,:),data.pump_pressure(5,:))
grid on 
xlabel('Differential pressure [Bar]')
ylabel('Time [s]')
title('Differential pressure over pump C2 - \omega = 0.45 and 0.35')

hold on 
plot(1800,data.pump_pressure(2,36000),'*r',3600,data.pump_pressure(2,72000),'r*')

data.pump_pressure(2,36000)
data.pump_pressure(2,36000*2)



deltaP = (data.pump_pressure(2,3600) - data.pump_pressure(2,72000))/0.1;


a0 = 1.2024;
a1 = 0.0098;
a2 = 0.0147;

(deltaP-2*a0*0.4)/a1



