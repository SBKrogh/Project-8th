clc; clear all; close all;
%%
data_old = load('pump_first.mat');
data_new = load('pump_new.mat');
%% Time

time_old = data_old.pump_pressure(1,:);
time_new = data_new.pump_pressure(1,:);

%% plot

figure
plot(time_old,data_old.pump_pressure(2,:),time_old,data_old.pump_pressure(3,:),time_old,data_old.pump_pressure(4,:),time_old,data_old.pump_pressure(5,:))
grid on 
xlabel('Time [s]')
ylabel('Differential pressure [Bar]')
legend('C2','C16','C18','C25')
title('First PI gain')

figure
plot(time_new,data_new.pump_pressure(2,:),time_new,data_new.pump_pressure(3,:),time_new,data_new.pump_pressure(4,:),time_new,data_new.pump_pressure(5,:))
grid on 
xlabel('Time [s]')
ylabel('Differential pressure [Bar]')
legend('C2','C16','C18','C25')
title('Tuned PI gain')
