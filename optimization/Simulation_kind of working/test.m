function [Lambda_A,Lambda_B,Lambda_C] = test(t_clock,Lambda_A_old,Lambda_B_old,Lambda_C_old)
coder.extrinsic('cost_update');

data = load('data.mat');
data = data.data;

%Time
Ts = 6.438500000000000;
t_h = 1+floor(t_clock/3600);
t_h_2 = 1+floor((t_clock-Ts)/3600);

if t_clock == Ts || t_h ~= t_h_2
    %Define size of matrices 
    Lambda_A = zeros(48,48);
    Lambda_B = zeros(48,48);
    Lambda_C = zeros(48,24);

    %Data 
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

    [Lambda_A,Lambda_B,Lambda_C] = cost_update(data,Lambda_1,Lambda_2,Lambda_3,Hp,t_h);
    
     Lambda_A_old = Lambda_A;
     Lambda_B_old = Lambda_B;
     Lambda_C_old = Lambda_C;
else
 Lambda_A = zeros(48,48)+Lambda_A_old;
 Lambda_B = zeros(48,48)+Lambda_B_old;
 Lambda_C = zeros(48,24)+Lambda_C_old;
end
