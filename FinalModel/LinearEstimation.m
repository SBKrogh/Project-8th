clear all
clc
%% Initializing
valve_param;
pipe_param;
matrices;

zo = [ones(1,8)]';

[ lambdaD, lambdaC, pipe ] = Pipes( pipe, B_1, zo );
[ mu_S_D, mu_S_C, valve ] = Valves_States( valve, B_1, zo );
[ mu_I_D, mu_I_C, valve ] = Valves_Inputs( valve, B_1, zo);
[ gammaD, gammaC, pipe ] = Tower( pipe, B_1, zo );


%% Load data from the lab

load('linear_WT_smalsig_data_2804.mat')
Ts = 0.05;
% u(:,5:8) = 10^5*u(:,5:8);
z = iddata(y,u,Ts,'Name', 'Data from Lab');
z.InputName = {'e13Cv', 'e15Cv', 'e20Cv', 'e22Cv','e01dp', 'e08dp', 'e09dp','e12dp'};
z.InputUnit =  {'-','-','-','-','bar', 'bar', 'bar','bar'};
z.OutputName = {'Node 2','Node 7','Node 4','Node 5' ...
          'Node 11', 'Node10', 'Node 16','Node 15'};
z.OutputUnit = { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar'};

%% Set up the ident model
Parameters = { [pipe.lambda(1); pipe.lambda(2); pipe.lambda(3); pipe.lambda(4); pipe.lambda(5); ...
    pipe.lambda(6); pipe.lambda(7); pipe.lambda(8); pipe.lambda(10); pipe.lambda(13);...
    pipe.lambda(14); pipe.lambda(16); pipe.lambda(19); pipe.lambda(20); pipe.lambda(21); pipe.gamma(24);...
    valve.muI(15); valve.muI(17); valve.muI(22); valve.muI(23);...
    valve.muS(15); valve.muS(17); valve.muS(22); valve.muS(23)]};
%     1.0e+12 *[
% 
%                    0
%    0.087076238345090
%    0.124302454403404
%    0.205847369418466
%    0.102923684993785
%    0.211116070926012
%    0.094465229613196
%    0.000000000000000
%    2.327048603212619
%    0.000000000000000
%    0.998168129901555
%   -0.000000000000000
%    0.847402208643442
%   -0.000000000000000
%    1.850433755338155
%    0.000000000000001
%    0.000000000000647
%    0.000000000001876
%   -0.000000000001942
%    0.000000000000906
%   -0.000005901432044
%   -0.000006181238136
%   -0.000006004287595
%   -0.000007452922113]};
    

    
linear_model = idgrey('Initialization', Parameters, 'c');

opt = greyestOptions('InitialState','zero', 'Display','on','SearchMethod', 'gn');
opt.SearchOption.MaxIter = 2000;


linear_estimation = greyest(z, linear_model, opt);
[linear_b_est,dlinear_b_est] = getpvec(linear_estimation,'free');

% figure
% compare(z, linear_model, linear_estimation);

datestr(now)

