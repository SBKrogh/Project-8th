clear all
clc
for k = 1:24
%Things i need to define 
    t_clock = 3600*k;
   % x = [0.01;0.02;0.03;0.02;0.01;0.02;0.03;0.02;0.01;0.02;0.03;0.02;
  %      0.01;0.02;0.03;0.02;0.01;0.02;0.03;0.02;0.01;0.02;0.03;0.02];
   x = -0.01*ones(48,1); 
 
    %Time
    Ts = 6.438500000000000;
    t_h = 1+floor(t_clock/3600);
    
    %Define size of matrices 
    Lambda_A = zeros(48,48);
    Lambda_B = zeros(48,48);
    Lambda_C = zeros(48,24);

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

    [Lambda_A,Lambda_B,Lambda_C] = cost_update(data,Lambda_1,Lambda_2,Lambda_3,Hp,t_h);
    
     Lambda_A_old = Lambda_A;
     Lambda_B_old = Lambda_B;
     Lambda_C_old = Lambda_C;

    %Define sizes
    u_hp = zeros(48,1);
    u_hp1 = zeros(24,1);
    u_hp2 = zeros(24,1);

    %Load system matrices
    Gamma = load('Gamma.mat');
    Gamma = Gamma.Gamma;
    Omega = load('Omega.mat');
    Omega = Omega.Omega;
    Phi = load('Phi.mat');
    Phi = Phi.Phi;
    Pi = load('Pi.mat');
    Pi = Pi.Pi;
    Psi = load('Psi.mat');
    Psi = Psi.Psi;
    Theta = load('Theta.mat');
    Theta = Theta.Theta;
    %Load Disturbance
    constant_dist = load('constant_dist.mat'); %Disturbance_Plot
    Data_OD = constant_dist.constant_dist; % constant_dist
    t_1 = 0:3600:3600*(length(Data_OD)-1);


    delta_p_0 = x(k,:);      %small-signal initial WT pressure measurement

    %d_hp = 0.025*90*ones(48,1);      % Small signal deviation of the Valves OD
    d_hp = [Data_OD(1,:); Data_OD(1,:);
            Data_OD(2,:); Data_OD(2,:);
            Data_OD(3,:); Data_OD(3,:);
            Data_OD(4,:); Data_OD(4,:);
            Data_OD(5,:); Data_OD(5,:);
            Data_OD(6,:); Data_OD(6,:);
            Data_OD(7,:); Data_OD(7,:);
            Data_OD(8,:); Data_OD(8,:);
            Data_OD(9,:); Data_OD(9,:);
            Data_OD(10,:); Data_OD(10,:);
            Data_OD(11,:); Data_OD(11,:);
            Data_OD(12,:); Data_OD(12,:);
            Data_OD(13,:); Data_OD(13,:);
            Data_OD(14,:); Data_OD(14,:);
            Data_OD(15,:); Data_OD(15,:);
            Data_OD(16,:); Data_OD(16,:);
            Data_OD(17,:); Data_OD(17,:);
            Data_OD(18,:); Data_OD(18,:);
            Data_OD(19,:); Data_OD(19,:);
            Data_OD(20,:); Data_OD(20,:);
            Data_OD(21,:); Data_OD(21,:);
            Data_OD(22,:); Data_OD(22,:);
            Data_OD(23,:); Data_OD(23,:);
            Data_OD(24,:); Data_OD(24,:)
            ];

    U_bar_hp = 0.2*ones(48,1);      % Input pressure to ring pumps operating point
    q_bar_p_hp = 1.4*ones(48,1);    % Flow operating point of the ring pumps

    %%%%%%%%%%%%%%%%%% General QP %%%%%%%%%%%%%%%%%%
    % 0.5*x'R*x+f'*x
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%% Constraint %%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    % Output constraint
    y_low =  0.08*ones(48,1);         % Full-signal upper and lower bounds 
    y_high = 0.18*ones(48,1);           

    % Pressure operating point of the PMA end-users
    y_bar = [0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
            0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
            0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;
            0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991 ;0.1562; 0.0991];    

    y1 = y_low - y_bar - Theta*Phi*delta_p_0-(Theta*Psi+Pi)*d_hp;
    y2 = y_high - y_bar - Theta*Phi*delta_p_0-(Theta*Psi+Pi)*d_hp;
    L_y = Theta*Gamma+Omega;

    % State constraint
    x_low = 0.055*ones(24,1);
    x_high = 0.16*ones(24,1);
    x_bar = 0.127*ones(24,1);

    delta_p_wt_1 = x_low -x_bar - Phi*delta_p_0 - Psi*d_hp;
    delta_p_wt_2 = x_high-x_bar - Phi*delta_p_0 - Psi*d_hp;
    %delta_p_wt_2(1,1) = 0.014;
    % input constraint 
    u_low = 0.05;
    u_high = 1;

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%% Setting up the QP %%%%%%%%%%%%%%%%%% 
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    R = 2*(Lambda_A + Lambda_C*Gamma); 

    f = (U_bar_hp'*(Lambda_A+Lambda_C*Gamma)+d_hp'*(Lambda_B+Lambda_C*Psi)'+delta_p_0*(Lambda_C*Phi)'+q_bar_p_hp');

    %CONSTRAINTS FOR Y AND X
    A = [-L_y;L_y; -Gamma; Gamma];
    b = [y1; y2; delta_p_wt_1; delta_p_wt_2];

    lb = u_low*ones(48,1);
    ub = u_high*ones(48,1);

    func = QP_func(R,f);

    options = optimoptions('fmincon','Algorithm','interior-point');
    u_hp = fmincon(func,zeros(size(ub)),A,b,[],[],lb,ub,[],options);

    %%%

    u_hp1 = u_hp(1:2:length(u_hp));
    u_hp2 = u_hp(2:2:length(u_hp));

    u(k,:) = [u_hp1(1,:); u_hp2(1,:)];
    k = k+1;
end
figure
subplot(2,1,1)
plot(u)
grid on
subplot(2,1,2)
plot(data(1:k,:))
grid on

figure
subplot(2,1,1)
plot(u_hp1)
hold on
plot(u_hp2)
grid on
subplot(2,1,2)
plot(Data_OD)
grid on


















