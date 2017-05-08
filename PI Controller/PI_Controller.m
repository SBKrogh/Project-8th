clc; clear all; close all; 

%% Pi controller 
% This document has been made to describe the design of the pi controllers
% used in the water tower project at Aalborg university - Spring semester
% 2017 gr. 830

s = tf('s'); % Transfor function 

%% Flow through the four pumps 
% Pump C2 and C16
a0 = 1.2024;
a1 = 0.0098;
a2 = 0.0147;

% ring flow and speed
qc2 = 0.0609;
wc2 = 2/5;

qc16 = 0.169;
wc16 = 2/5;


G_c2 = a1*qc2 + 2*a0*wc2;    % Models
G_c16 = a1*qc16 + 2*a0*wc16;

% D_c2 = 1.4/s;
% D_c16 = 1.4/s;

D_c2 = 2/s;
D_c16 = 2/s;

sys1 = G_c2*D_c2/(1 + G_c2*D_c2); 
sys2 = G_c16*D_c16/(1 + G_c16*D_c16);

%% Pump C18 and C25
a0 = 0.6921;
a1 = -0.0177;
a2 = 0.0179;

% pma flow and speed
qc18 = 0.179;
wc18 =0.8/5;

qc25 = 0.272;
wc25 = 2/5;

G_c18 = a1*qc18 + 2*a0*wc18; % Models
G_c25 = a1*qc25 + 2*a0*wc25;

% D_c18 = 6/s; % Fine tuned gains 
% D_c25 = 4/s; 

D_c18 = 8/s;
D_c25 = 3/s;

c2d(sys1,0.05,'tustin')
sys3 = G_c18*D_c18/(1 + G_c18*D_c18);
sys4 = G_c25*D_c25/(1 + G_c25*D_c25);

%% 



step(sys1)
hold on
step(sys2)
hold on
step(sys3)
hold on
step(sys4)
grid on 
%ylabel('Step size')
%xlabel('Time [s]')
legend('G(C2)','G(C16)','G(C18)','G(C25)')
title('Step response of linearized pump model')
