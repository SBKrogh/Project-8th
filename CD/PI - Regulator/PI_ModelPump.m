clc; close all; clear all;
s = tf('s');
%% Models
% PI = (Ps+ki)/s, P: Proportional gain, ki, Integral gain

Gc2  = 0.966;
C2 = (1.39*s + 1.39)/s; %0.14

Gc16 = 0.976;
C16 = (1.39*s + 1.39)/s;

Gc18 = 0.217;
C18 = (5.89*s + 5.89)/s; 

Gc25 = 0.546;
C25 = (2.57*s + 2.57)/s; 



%% Pi controller



[y,t]= step(C2*Gc2/(1+C2*Gc2));
hold on


[y1,t1]=step(C16*Gc16/(1+C16*Gc16));
hold on


[y2,t2]=step(C18*Gc18/(1+C18*Gc18));
hold on

[y3,t3]=step(C25*Gc25/(1+C25*Gc25));




reduce_plot(t,y,t1,y1,t2,y2,t3,y3)
legend('C2','C16','C18','C25')
grid on
ylabel('Amplitude')
xlabel('Time [s]')
title('Step respons')

