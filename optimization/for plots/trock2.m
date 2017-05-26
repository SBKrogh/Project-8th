load('try_for_B2.mat');

Ac = linear_b_est(1);

Bc = [linear_b_est(2) linear_b_est(3)];

Ec = [linear_b_est(4) linear_b_est(5)];

Cc = [linear_b_est(6); linear_b_est(7)];

Dc = [linear_b_est(8) linear_b_est(9);
    linear_b_est(10) linear_b_est(11)];

Kc = [linear_b_est(12) linear_b_est(13);
    linear_b_est(14) linear_b_est(15)];

Ts = 89.332338826894883;

B_c = [Bc Ec];
D_c = [Dc Kc];

sysc = ss(Ac,B_c,Cc,D_c);
sysdd = c2d(sysc, Ts,'zoh');

Ad = sysdd.A;
Bd = sysdd.B(1:2);
Ed = sysdd.B(3:4);
Cd = sysdd.C;
Dd = sysdd.D(:,1:2);
Dd(1,:) = -Dd(1,:);
Dd(1,2) = -Dd(1,2);
Dd = -Dd;
Kd = sysdd.D(:,3:4);