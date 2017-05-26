function [ M , N, S, C1, C2] = mat_est

% Load the parameters saved from the estimation
load('est_newtrock.mat')
matrices;

A = diag([linear_b_est(1) linear_b_est(2) linear_b_est(3) linear_b_est(4) linear_b_est(5) linear_b_est(6) linear_b_est(7)...
    linear_b_est(8) 0 linear_b_est(9) 0 0 linear_b_est(10) linear_b_est(11) linear_b_est(12) linear_b_est(13)...
    linear_b_est(14) 0 linear_b_est(15) linear_b_est(16) linear_b_est(17) linear_b_est(18) linear_b_est(19) linear_b_est(20)]);

M = B_1 * A * B_1';
    
N = [ linear_b_est(95)   linear_b_est(96)   linear_b_est(97)   linear_b_est(98)   1   linear_b_est(99)   linear_b_est(100)   linear_b_est(101) ;
    linear_b_est(102)   linear_b_est(21)    linear_b_est(103)   linear_b_est(104)   linear_b_est(105)   linear_b_est(106)   1   linear_b_est(107);
    linear_b_est(108)   linear_b_est(22)    linear_b_est(23)    linear_b_est(109)   linear_b_est(110)   linear_b_est(111) -1 1;
    linear_b_est(112)   linear_b_est(113) linear_b_est(24)  linear_b_est(114)   linear_b_est(115)   1   linear_b_est(116)   1;
    linear_b_est(117)   linear_b_est(118)   linear_b_est(119)   linear_b_est(120)   linear_b_est(121)   1    linear_b_est(122)  linear_b_est(123) ;
    linear_b_est(25)    linear_b_est(26)    linear_b_est(124)   linear_b_est(125)   linear_b_est(126)   linear_b_est(127)   linear_b_est(128)   linear_b_est(129);
    linear_b_est(130)   linear_b_est(131)   linear_b_est(27) linear_b_est(28)   linear_b_est(132)   linear_b_est(133)   linear_b_est(134)   linear_b_est(135);
    linear_b_est(136) linear_b_est(29)  linear_b_est(30)    linear_b_est(137)   linear_b_est(138)   linear_b_est(139)   linear_b_est(140)   linear_b_est(141)];
    
C1 = [ linear_b_est(31)  linear_b_est(32) linear_b_est(33) linear_b_est(34) linear_b_est(35) linear_b_est(36) linear_b_est(37) linear_b_est(38);
    linear_b_est(39)  linear_b_est(40) linear_b_est(41) linear_b_est(42) linear_b_est(43) linear_b_est(44) linear_b_est(45) linear_b_est(46);
    linear_b_est(47)  linear_b_est(48) linear_b_est(49) linear_b_est(50) linear_b_est(51) linear_b_est(52) linear_b_est(53) linear_b_est(54);
    linear_b_est(55)  linear_b_est(56) linear_b_est(57) linear_b_est(58) linear_b_est(59) linear_b_est(60) linear_b_est(61) linear_b_est(62)];

C2 = [ linear_b_est(63)  linear_b_est(64) linear_b_est(65) linear_b_est(66) linear_b_est(67) linear_b_est(68) linear_b_est(69) linear_b_est(70);
    linear_b_est(71)  linear_b_est(72) linear_b_est(73) linear_b_est(74) linear_b_est(75) linear_b_est(76) linear_b_est(77) linear_b_est(78);
    linear_b_est(79)  linear_b_est(80) linear_b_est(81) linear_b_est(82) linear_b_est(83) linear_b_est(84) linear_b_est(85) linear_b_est(86);
    linear_b_est(87)  linear_b_est(88) linear_b_est(89) linear_b_est(90) linear_b_est(91) linear_b_est(92) linear_b_est(93) linear_b_est(94)];

WTconstant = (pi*0.32^2 * 10^5)/(1000*9.8);

S = (1/WTconstant) * pinv(H_0) * H_1 * B_1';

end
