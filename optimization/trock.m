
% Complete the state-space system matrices for estimation
[ M , N, As, Bs, Cs, Ds, S, C1, C2] = mat_est;

M_c = M;

N_c = [ N(:,5) N(:,6) ];

Q_c =[ N(:,2) N(:,4)];

C11 = [ C1(2,:); C1(4,:)];

C22 = [C2(2,2); C2(2,4)];

Ac = S* (M_c \ B_0)
Bc = -S* (M_c \ N_c)
Ec = S* (M_c \ Q_c)
Cc = -C11* (M_c \ B_0)
Dc = C11* (M_c \ N_c)
Kc = C22 - C11* (M_c \ Q_c)
Ds = [Ds(2,2) Ds(2,4) Ds(2,5) Ds(2,6);
    Ds(4,2) Ds(4,4) Ds(4,5) Ds(4,6)];
Ts = 6.4385;  %Note: Rethink this %

Bcc = [Bc Ec];
Dcc = [Dc Kc];

sysc = ss(Ac,Bcc,Cc,Ds);
sysdd = c2d(sysc, Ts,'zoh');

Ad = sysdd.A;
Bd = sysdd.B(1:2);
Ed = sysdd.B(3:4);
Cd = sysdd.C;
 Dd = sysdd.D(:,1:2);
 Kd = sysdd.D(:,3:4);
% 
% sys = ss(As,Bs,Cs,Ds);
% sysd = c2d(sys, Ts,'zoh');

% State-Space matrices for control in continous
% Ac = As;
% 
% Bc = [ Bs(5) Bs(6) ];
% 
% Ec =  [ Bs(2) Bs(4)];
% 
% Cc = [ Cs(2); Cs(4) ];
% 
% Dc = [ Ds(2,5) Ds(2,6); Ds(4,5) Ds(4,6) ];

% State-Space matrices for control in discrete
% Ad = sysd.A;
% 
% Bd = [ sysd.B(5) sysd.B(6) ];
% 
% Ed = [ sysd.B(2) sysd.B(4)] ;
%  
% Cd = [ sysd.C(2); sysd.C(4) ];
% 
%Dd = [ sysdd.D(1,3) sysdd.D(1,4); sysdd.D(2,3) sysdd.D(2,4) ];

%Kd = [ sysdd.D(1,1) sysdd.D(1,2); sysdd.D(2,1) sysdd.D(2,2) ];

E_new = Ed*pinv(Kd);     

%WTconstant = (pi * (0.32)^2)/(1000*9.8);

save('sysd.mat','Ad','Bd','E_new','Cd','Dd','Ts')