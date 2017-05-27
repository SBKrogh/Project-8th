function [ M , N, A_c, B_c, C_c, D_c ] = mat_est

% Load the parameters saved from the estimation
load('M_n.mat')
load('C_D')
matrices;
pipe_param;

A = diag([linear_b_est(1) linear_b_est(2) linear_b_est(3) linear_b_est(4) linear_b_est(5) linear_b_est(6) linear_b_est(7)...
    linear_b_est(8) 0 linear_b_est(9) 0 0 linear_b_est(10) linear_b_est(11) linear_b_est(12) linear_b_est(13)...
    linear_b_est(14) 0 linear_b_est(15) linear_b_est(16) linear_b_est(17) linear_b_est(18) linear_b_est(19) linear_b_est(20)]);

N = [ linear_b_est(21)   linear_b_est(22)   linear_b_est(23)   linear_b_est(24)   1   linear_b_est(25)   linear_b_est(26)   linear_b_est(27) ;
    linear_b_est(28)   linear_b_est(29)    linear_b_est(30)   linear_b_est(31)   linear_b_est(32)   linear_b_est(33)   1   linear_b_est(34);
    linear_b_est(35)   linear_b_est(36)    linear_b_est(37)    linear_b_est(38)   linear_b_est(39)   linear_b_est(40) -1 1;
    linear_b_est(41)   linear_b_est(42) linear_b_est(43)  linear_b_est(44)   linear_b_est(45)   1   linear_b_est(46)   1;
    linear_b_est(47)   linear_b_est(48)   linear_b_est(49)   linear_b_est(50)   linear_b_est(51)   1    linear_b_est(52)  linear_b_est(53) ;
    linear_b_est(54)    linear_b_est(55)    linear_b_est(56)   linear_b_est(57)   linear_b_est(58)   linear_b_est(59)   linear_b_est(60)   linear_b_est(61);
    linear_b_est(62)   linear_b_est(63)   linear_b_est(64) linear_b_est(65)   linear_b_est(66)   linear_b_est(67)   linear_b_est(68)   linear_b_est(69);
    linear_b_est(70) linear_b_est(71)  linear_b_est(72)    linear_b_est(73)   linear_b_est(74)   linear_b_est(75)   linear_b_est(76)   linear_b_est(77)];


M = B_1 * A * B_1';


% A = [ linear_b_est(1)  linear_b_est(2)    0   0   linear_b_est(3)  0   0   0;
%     
%      linear_b_est(2)  linear_b_est(4)  linear_b_est(5)  0   linear_b_est(6)  linear_b_est(7)  0   linear_b_est(8);
%      
%      0       linear_b_est(5)  linear_b_est(9) linear_b_est(10) 0 linear_b_est(11) linear_b_est(12) linear_b_est(13);
%      
%      0      0       linear_b_est(10) linear_b_est(14) linear_b_est(15) 0 linear_b_est(16) linear_b_est(17);
%      
%      linear_b_est(3)  linear_b_est(6)     0   linear_b_est(15) linear_b_est(18) 0       0         0;
%      
%      0      linear_b_est(7)      linear_b_est(11) 0       0   linear_b_est(19) 0 linear_b_est(20);
%      
%      0       0          linear_b_est(12) linear_b_est(16) 0   0   linear_b_est(21) linear_b_est(22);
%      
%      0      linear_b_est(8)      linear_b_est(13) linear_b_est(17) 0 linear_b_est(20) linear_b_est(22) linear_b_est(23)];
 
C1 = [ est_C_D(1)  est_C_D(2) est_C_D(3) est_C_D(4) est_C_D(5) est_C_D(6) est_C_D(7) est_C_D(8);
    est_C_D(9)  est_C_D(10) est_C_D(11) est_C_D(12) est_C_D(13) est_C_D(14) est_C_D(15) est_C_D(16);
    est_C_D(17)  est_C_D(18) est_C_D(19) est_C_D(20) est_C_D(21) est_C_D(22) est_C_D(23) est_C_D(24);
    est_C_D(25)  est_C_D(26) est_C_D(27) est_C_D(28) est_C_D(29) est_C_D(30) est_C_D(31) est_C_D(32)];

C2 = [ est_C_D(33)  est_C_D(34) est_C_D(35) est_C_D(36) est_C_D(37) est_C_D(38) est_C_D(39) est_C_D(40);
    est_C_D(41)  est_C_D(42) est_C_D(43) est_C_D(44) est_C_D(45) est_C_D(46) est_C_D(47) est_C_D(48);
    est_C_D(49)  est_C_D(50) est_C_D(51) est_C_D(52) est_C_D(53) est_C_D(54) est_C_D(55) est_C_D(56);
    est_C_D(57)  est_C_D(58) est_C_D(59) est_C_D(60) est_C_D(61) est_C_D(62) est_C_D(63) est_C_D(64)];

WTconstant = (pipe.e26.area * 10^5)/(1000*9.8);
% 
% 
S =  (1/WTconstant) * pinv(H_0) * H_1 * B_1';

N_c = [ N(:,5) N(:,6)];

Q_c = [ N(:,2) N(:,4)];

C11 = [ C1(2,:); C1(4,:)];

C22 = [C2(2,2) C2(2,4);
    C2(4,2) C2(4,4)];


A_c =  S * (M \ B_0);

E_s = S * (M \ Q_c);

B_s = - S * (M \ N_c);

D_s = [C11 * (M\N_c) ];
D_s(1,:) = -D_s(1,:);
D_s(2,1) = - D_s(2,1);


C_c =  [- C11 * ( M \ B_0 )];

K_s =  [C22 - C11 * ( M \ Q_c ); zeros(1,2)];

B_c = [B_s E_s];
D_c = [D_s K_s];


end
