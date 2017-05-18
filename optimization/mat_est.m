function [ M , N, As, Bs, Cs, Ds ] = mat_est

load('est_trock_f.mat')
matrices;

M = [ linear_b_est(1)  linear_b_est(2) linear_b_est(3) linear_b_est(4) linear_b_est(5) linear_b_est(6) linear_b_est(7) linear_b_est(8);
    
     linear_b_est(2)  linear_b_est(9) linear_b_est(10) linear_b_est(11) linear_b_est(12) linear_b_est(13) linear_b_est(14) linear_b_est(15);
     
     linear_b_est(3)  linear_b_est(10) linear_b_est(109) linear_b_est(16) linear_b_est(17) linear_b_est(18) linear_b_est(19) linear_b_est(20);
     
     linear_b_est(4)  linear_b_est(11) linear_b_est(16) linear_b_est(21) linear_b_est(22) linear_b_est(23) linear_b_est(24) linear_b_est(25);
     
     linear_b_est(5)  linear_b_est(12) linear_b_est(17) linear_b_est(22) linear_b_est(26) linear_b_est(27) linear_b_est(28) linear_b_est(29);
     
     linear_b_est(6)  linear_b_est(13) linear_b_est(18) linear_b_est(23) linear_b_est(27) linear_b_est(30) linear_b_est(31) linear_b_est(32);
     
     linear_b_est(7)  linear_b_est(14) linear_b_est(19) linear_b_est(24) linear_b_est(28) linear_b_est(31) linear_b_est(33) linear_b_est(34);
     
     linear_b_est(8)  linear_b_est(15) linear_b_est(20) linear_b_est(25) linear_b_est(29) linear_b_est(32) linear_b_est(34) linear_b_est(35)];
 
    
N = [ 0   0   0   0   1   0   0   0 ;
    0   linear_b_est(36)    0   0   0   0   1   0;
    0   linear_b_est(37)    linear_b_est(38)    0   0   0 -1 1;
    0   0 linear_b_est(39)  0   0   1   0   1;
    0   0   0   0   0   1    0  0 ;
    linear_b_est(40)    linear_b_est(41)    0   0   0   0   0   0;
    0   0   linear_b_est(42) linear_b_est(43)   0   0   0   0;
    0 linear_b_est(44)  linear_b_est(45)    0   0   0   0   0];
    
C1 = [ linear_b_est(46)  linear_b_est(47) linear_b_est(48) linear_b_est(49) linear_b_est(50) linear_b_est(51) linear_b_est(52) linear_b_est(53);
    linear_b_est(54)  linear_b_est(55) linear_b_est(56) linear_b_est(57) linear_b_est(58) linear_b_est(59) linear_b_est(60) linear_b_est(61);
    linear_b_est(62)  linear_b_est(63) linear_b_est(64) linear_b_est(65) linear_b_est(66) linear_b_est(67) linear_b_est(68) linear_b_est(69);
    linear_b_est(70)  linear_b_est(71) linear_b_est(72) linear_b_est(73) linear_b_est(74) linear_b_est(75) linear_b_est(76) linear_b_est(77)];

C2 = [ linear_b_est(78)  linear_b_est(79) linear_b_est(80) linear_b_est(81) linear_b_est(82) linear_b_est(83) linear_b_est(84) linear_b_est(85);
    linear_b_est(86)  linear_b_est(87) linear_b_est(88) linear_b_est(89) linear_b_est(90) linear_b_est(90) linear_b_est(91) linear_b_est(92);
    linear_b_est(93)  linear_b_est(94) linear_b_est(95) linear_b_est(96) linear_b_est(97) linear_b_est(98) linear_b_est(99) linear_b_est(100);
    linear_b_est(101)  linear_b_est(102) linear_b_est(103) linear_b_est(104) linear_b_est(105) linear_b_est(106) linear_b_est(107) linear_b_est(108)];

WTconstant = (pi*0.32^2)/(1000*9.8);


B2 =  B_0;

H = - (1/WTconstant) * pinv(H_0) * H_1 * B_1';

%As = - H * (M \ B2);
As = -0.0001;

Bs = - H * (M \ N);

Cs =  [- C1 * ( M \ B2 ); 1];

Ds =  [C2 - C1 * ( M \ N ); zeros(1,8)];

end
