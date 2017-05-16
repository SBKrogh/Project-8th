clc; close all; clear all;
data = load('pump.mat');
data1 = load('Pump_ref.mat');

figure
%plot(data.pump_pressure(1,:),data.pump_pressure(2,:))
% hold on 
 reduce_plot(data.pump_pressure(1,:),data.pump_pressure(4,:))
% hold on 
% plot(data.pump_pressure(1,:),data.pump_pressure(4,:))
% hold on
% plot(data.pump_pressure(1,:),data.pump_pressure(5,:))
grid on 
ylabel('Differential pressure [Bar]')
xlabel('Time [s]')
title('Differential pressure over pump C18 - \omega = 0.16 and 0.21')

hold on 
plot(1800,data.pump_pressure(4,36000),'*r',3600,data.pump_pressure(4,72000),'r*')

data.pump_pressure(4,36000)
data.pump_pressure(4,36000*2)



deltaP = (data.pump_pressure(2,3600) - data.pump_pressure(2,72000))/0.1;


a0 = 0.6921;
a1 = -0.0177;
a2 = 0.0179;

(deltaP-2*a0*0.4)/a1



