load('try_for_C_D.mat')

Ac = -0.001119415617640;

Bc = [ 0.000297184296396894 1.011362712563936e-4 ];

Ec = [-1.757484437305615e-7 2.924000584714482e-08 ];

Cc = [ linear_b_est(1); linear_b_est(2)];

Dc = [linear_b_est(3) linear_b_est(4); 
    linear_b_est(7) linear_b_est(8)] ;

Kc = [ linear_b_est(5) linear_b_est(6);
    linear_b_est(9) linear_b_est(10)];

B_c = [Bc Ec];
D_c = [Dc Kc];

Ts = 89.332338826894883/10;

sysc = ss(Ac,B_c,Cc,D_c);
sysdd = c2d(sysc, Ts,'zoh');

Ad = sysdd.A;
Bd = sysdd.B(1:2);
Bd2 = sysdd.B(1:2)/2;
Ed = sysdd.B(3:4);
Cd = sysdd.C;
Dd = sysdd.D(:,1:2);
% Dd(1,:) = -Dd(1,:);
% Dd(1,2) = -Dd(1,2);
 Dd = -Dd;
 Dd(2,2) =- Dd(2,2);
Kd = sysdd.D(:,3:4);
