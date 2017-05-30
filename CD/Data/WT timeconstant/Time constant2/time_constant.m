clear all; close all; clc; 
load('wt')
%% 

x = wt_pressure(1,:);
y = wt_pressure(2,:);

reduce_plot(x(400:length(x)),y(400:length(y)))
hold on
plot(23109*0.05,y(23109),'r*')
grid on 
title('Time constant')
xlabel('Time [s]')
ylabel('Pressure - water tank')