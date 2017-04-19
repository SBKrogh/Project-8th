clear all;
close all;
clc;
%% Preparing data for Feedback coeficients - LN stochastic p. 28
% 
data = load('data_v2.csv'); % Data
data = data(:,3); 

%% mean data curve 

data_new(1) = data(1)
data_new(2) = data(2) 

for k = 3:168


    data_new(k) = mean(data(k-2:k-1));
    
end
        

% 
% data_new = data_new(4:168)
% data = data(4:168)


%immse(data,data_new')

plot(data_new(1:60))
hold on
plot(data(1:60))
legend('SMA','Actually price')
grid on
xlabel('Hour')
ylabel('Electrical price [kWh]')