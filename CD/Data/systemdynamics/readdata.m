%% %import data

clc 
clear all


%importfile('Filterdata');
%importfile('outputs21031430'); % C2 2.25| C16 2.25 | C18 0.8 | C25 4.2 | WT_L = 100L
%importfile('outputs21031310'); % C2 2.4| C16 2.4 | C18 0.7 | C25 4.2 | WT_L = 180L 
%importfile('outputs21031430'); % C2 2.05| C16 2.05 | C18 0.7 | C25 4.2 | WT_L = 30L 
%importfile('outputs21031420'); % C2 2.05| C16 2.05 | C18 0.7 | C25 4.2 | WT_L = 30L 
%A = importdata(Filter_data)
%newData1 = load('-mat', Filterdata);


%% %extraxt from struct  --**-- all valves open --**--

clc
clear all

Ts = 0.05;
SS = 25;
N = SS/Ts;
M = 1199; %(M+1) = number of sampels pr steadystate wanted 
u = [];
y = [];

for k = 2:2
    
filename = sprintf('%d',k);  

% Import the file
newData1 = load('-mat', filename);

% Create new variables in the base workspace from those fields.
vars = fieldnames(newData1);
for i = 1:length(vars)
    assignin('base', vars{i}, newData1.(vars{i}));
end
    
t = Outputs.time(N:N+M);

%Pma pressures
n11 = Outputs.signals.values(N:N+M,1);
n10 = Outputs.signals.values(N:N+M,2);
n16 = Outputs.signals.values(N:N+M,3);
n15 = Outputs.signals.values(N:N+M,4);

% Rellative pump pressures
C2 = Outputs1.signals.values(N:N+M,1);
C16 = Outputs1.signals.values(N:N+M,2);
C18 = Outputs1.signals.values(N:N+M,3);
C25 = Outputs1.signals.values(N:N+M,4);

% Ring pressures
n2 = Outputs2.signals.values(N:N+M,1);
n7 = Outputs2.signals.values(N:N+M,2);
n8 = Outputs2.signals.values(N:N+M,3);
n13 = Outputs2.signals.values(N:N+M,4);

u = [u; C2 C16 C18 C25];
y = [y; n2 n7 n8 n13 n11 n10 n16 n15];
end

v1 = ones(length(u),1);
v2 = ones(length(u),1);
v3 = ones(length(u),1);
v4 = ones(length(u),1);

u = [v1 v2 v3 v4, u];
T = 0:Ts:(length(u)-1)*Ts;
'done'
%% %edge detection
% f = edge(n2);
% j=0
% for n = 1:length(f)
%     
%    if f(n) == 1
%        j=j+1
%        tt=0.05*n
%        e(j)=tt       
%    end 
% end    
% 
% o = mean(n2)*ones(length(e),1)


%% %plot
close all

plot(t,n10,'r',t,n15,'y')
legend('n10','n15')
title('PMA pressures')
xlabel('Seconds')
ylabel('Bar')
grid on;

figure(2)
plot(t,C2,'b',t,C16,'g')
legend('C2','C16')
title('Relative pump pressures')
xlabel('Seconds')
ylabel('Bar')
grid on;

figure(3)
plot(t,n8,'r',t,n13,'y')
legend('n4','n5')
title('Ring pressures')
xlabel('Seconds')
ylabel('Bar')
grid on;

%hold on
%plot(e,o,'*')