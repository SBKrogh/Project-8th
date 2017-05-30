clear all; close all; clc; 
load('wt')
%% 

x = wt_pressure(1,1:54244);
y = wt_pressure(2,34720:88964-1);

reduce_plot(x,y)
hold on
plot(19686*0.05,y(19686),'r*')
grid on 
title('Time constant')
xlabel('Time [s]')
ylabel('Pressure - water tank')