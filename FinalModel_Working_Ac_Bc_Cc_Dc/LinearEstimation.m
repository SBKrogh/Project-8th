clear all
clc
%% Initializing

[ a, B, C, D] = Initialization_trock;


%% Load data from the lab
% load('parest_WT_cont_4inone.mat')
load('Long_data_new_layout.mat') % fits really great
Ts = 0.05;
u = u_sm;
y = y_sm;
% s = s_sm;
u(:,3:4) = 90 * u(:,3:4);
z = iddata(y,u,Ts,'Name', 'Data from Lab');
z.InputName = {'e01dp', 'e08dp', 'e15Cv', 'e22Cv'};
z.InputUnit =  {'bar', 'bar', '-','-',};
z.OutputName = {'PMA1','PMA2','WT'};
z.OutputUnit = {'bar','bar','bar'};

%% Set up the ident model
% load('prediction.mat')
d11 = D(1,1);
d12 = D(1,2);
d21 = D(2,1);
d22 = D(2,2);
% Param = { d11; d12; d21; d22};
 Parameters =   {[C(1), C(2),...
      D(1,1), D(1,2), D(1,3), D(1,4),...
      D(2,1), D(2,2), D(2,3), D(2,4)]};

linear_model = idgrey('Initialization_SS', [Parameters], 'c');

% opt = greyestOptions('InitialState','zero','Display','on','SearchMethod', 'gn');
% opt.SearchOption.MaxIter = 150;
% 
% datestr(now)
% linear_estimation = greyest(z, linear_model, opt);
% [linear_b_est,dlinear_b_est] = getpvec(linear_estimation,'free');
% datestr(now)
figure
compare(z, linear_model);
% compare(z, linear_model, linear_estimation);
%%
% figure
% compare(z, nlgr, 'init', 'm')

q = compare(z, linear_model, 'init', 'm');
Tss = 0.05*[1:1:574001];
%%



figure
reduce_plot(Tss/60,z.y(:,1),Tss/60,q.y(:,1))
grid on 
title('Node 11')
ylabel('Amplitude [Bar]')
xlabel('Time [min]')
legend('Data from lab (Node 11)','First simulation: 56.87 %')

figure
reduce_plot(Tss/60,z.y(:,2),Tss/60,q.y(:,2))
grid on 
title('Node 10')
ylabel('Amplitude [Bar]')
xlabel('Time [min]')
legend('Data from lab (Node 10)','First simulation: 44.32 %')

figure
reduce_plot(Tss/60,z.y(:,3),Tss/60,q.y(:,3))
grid on 
title('Node WT')
ylabel('Amplitude [Bar]')
xlabel('Time [min]')
legend('Data from lab (WT)','First simulation: -63.37 %')

% figure
% reduce_plot(Tss/60,z.y(:,4),Tss/60,q.y(:,4))
% grid on 
% title('Node 15')
% ylabel('Amplitude [Bar]')
% xlabel('Time [min]')
% xlim([0 38])
% legend('Data from lab (Node 15)','First simulation: 63.55 %')
% 
% figure
% reduce_plot(Tss/60,z.y(:,5),Tss/60,q.y(:,5))
% grid on 
% title('WT')
% ylabel('Amplitude [Bar]')
% xlabel('Time [min]')
% xlim([0 38])
% legend('Data from lab (WT)','First simulation: 43.11 %')
% 
