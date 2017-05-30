clear , clc, 
% Sample Time
Ts = 87.5440;
Ts_h = 3600;

% Load end-users consumption
load('Disturbance_Plot.mat');
t_1 = 0:3600:3600*(length(Data_OD)-1);
t_h_old = 0;

constant_dist = ones(24,1);

% Load price-curve
data = load('data.mat');
data = data.data./10^6;

% Load discrete state-space system matrix
matrices, trock;