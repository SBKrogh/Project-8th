clear all
clc
%% Initializing
valve_param;
pipe_param;
matrices;

zo = [ones(1,8)*0.1]';

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

% 1.0e+12 *[
% 
%                    0
%    0.087075998891227
%    0.124302437162751
%    0.205847352784372
%    0.102923664384889
%    0.211116071426078
%    0.094465488490238
%    0.000000000000005
%    2.327048603010433
%   -0.000000000000000
%    0.998168129534863
%   -0.000000000000000
%    0.847402208922971
%   -0.000000000000000
%    1.850433754894510
%   -0.000000208366323
%   -0.000000000000273
%    0.000000000000213
%   -0.000000000000194
%    0.000000000000002
%   -0.000000000000876
%   -0.000068961735391
%    0.000000000000016
%   -0.000000000000073]};
    



    
linear_model = idgrey('Initialization', Parameters, 'c');

opt = greyestOptions('InitialState','zero', 'Display','on','SearchMethod', 'gn');
opt.SearchOption.MaxIter = 100;

datestr(now)
linear_estimation = greyest(z, linear_model, opt);
[linear_b_est,dlinear_b_est] = getpvec(linear_estimation,'free');
datestr(now)
figure
compare(z, linear_model, linear_estimation);

