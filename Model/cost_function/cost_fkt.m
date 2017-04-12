clear all;
close all;
clc;
%% Load data

data = load('data.csv');
data_mean = data(:,3) - mean(data(:,3));

attt = autocorr(data_mean)
