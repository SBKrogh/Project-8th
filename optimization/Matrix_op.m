clear;
load('data.mat');
% run('../Model/cost_function/mean_curve.m');
matrices;
trock;

G_2 = zeros(2,e);               % Mapping matrix for pumps
G_2(1,9) = 1;                   % Main pump 1 edge 1
G_2(2,11) = 1;                  % Main pump 2 edge 11

Hp = 24;

Lambda_1 = - G_2 * B_1' * (M_c \ N_c);

Lambda_2 = - G_2 * B_1' * (M_c \ Q_c);

Lambda_3 = - G_2 * B_1' * (M_c \ B_0);

%%
n = length(Lambda_1);
Lambda_A = Lambda_1 * data(1);

for i = 1:Hp-1
    Lambda_A(i + n: i + n + 1, i + n : i + n + 1) = Lambda_1 * data(i + 1);
    n = n + 1;
end

n = length(Lambda_2);
m = size(Lambda_2);
m = m(1);
Lambda_B = Lambda_2 * data(1);

for i = 1:Hp-1
    Lambda_B(i + m: i + m + 1, 1 + i*n :  i*n +n ) = Lambda_2 * data(i + 1);
    m = m + 1;
end

m = size(Lambda_3);
m = m(1);
Lambda_C = Lambda_3 * data(1);

for i = 1:Hp-1
    Lambda_C(i + m: i + m + 1,  i + 1 ) = Lambda_3 * data(i + 1);
    m = m + 1;
end


%%

Phi = zeros(24,1);

% State matrix
% Phi(1) = 1;
for i = 1:Hp
    Phi(i) = Ad^i;
end

% Input matrix
n = length(Bd);

N = n * Hp;

M = Hp;

k = 2;
Gamma = zeros(24,48);
for i = 1:n:N
    for j = k:M 
        Gamma(j,i:i+n-1) = Ad^(j-k) * Bd;
    end
    k = k + 1 ;
end

% Disturbance Matrix
l = 2;

n = length(Ed);

N = n * Hp;
Psi = zeros(24,48);

for i = 1:n:N
    for j = l:M 
        Psi(j,i:i+n-1) = Ad^(j-l) * Ed; %#ok<*SAGROW>
    end
    l = l + 1 ;
end
%%
m = size(Cd);
m = m(1);
Theta = Cd;

for i = 1:Hp-1
    Theta(i + m: i + m + 1,  i + 1 ) = Cd;
    m = m + 1;
end

n = length(Dd);
Omega = Dd;

for i = 1:Hp-1
    Omega(i + n: i + n + 1, i + n : i + n + 1) = Dd;
    n = n + 1;
end

n = length(Kd);
m = size(Kd);
m = m(1);
Pi = Kd;

for i = 1:Hp-1
    Pi(i + m: i + m + 1, 1 + i*n :  i*n +n ) = Kd;
    m = m + 1;
end
