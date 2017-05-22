function [Lambda_A,Lambda_B,Lambda_C] = fcn(t_clock)

%Time
t_h = 1+floor(t_clock/3600);

%Data 
data = load('data.mat');
data = data.data;
G_2 = load('G_2.mat');
G_2 = G_2.G_2;
B_1 = load('B_1.mat');
B_1 = B_1.B_1;
M_c = load('M_c.mat');
M_c = M_c.M_c;
N_c = load('N_c.mat');
N_c = N_c.N_c;
Q_c = load('Q_c.mat');
Q_c = Q_c.Q_c;
B_0 = load('B_0.mat');
B_0 = B_0.B_0;

%Define Lambda_A/B/C
Hp = 24;

Lambda_1 =  G_2 * B_1' * (M_c \ N_c);

Lambda_2 = - G_2 * B_1' * (M_c \ Q_c);

Lambda_3 = - G_2 * B_1' * (M_c \ B_0);

%
n = length(Lambda_1);
Lambda_A = Lambda_1 * data(1+t_h);

for i = 1:Hp-1
    Lambda_A(i + n: i + n + 1, i + n : i + n + 1) = Lambda_1 * data(i + 1+t_h);
    n = n + 1;
end

n = length(Lambda_2);
m = size(Lambda_2);
m = m(1);
Lambda_B = Lambda_2 * data(1+t_h);

for i = 1:Hp-1
    Lambda_B(i + m: i + m + 1, 1 + i*n :  i*n +n ) = Lambda_2 * data(i + 1+t_h);
    m = m + 1;
end

m = size(Lambda_3);
m = m(1);
Lambda_C = Lambda_3 * data(1+t_h);

for i = 1:Hp-1
    Lambda_C(i + m: i + m + 1,  i + 1 ) = Lambda_3 * data(i + 1+t_h);
    m = m + 1;
end


Lambda_A = Lambda_A; 
Lambda_B = Lambda_B; 
Lambda_C = Lambda_C;

