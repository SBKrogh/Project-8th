function [ a, B, C, D] = Initialization_trock 
load('try_for_C_D.mat')
%INITIALIZATION Summary of this function goes here
%   Detailed explanation goes here
% matrices;
% valve_param;
% pipe_param;
% zo = [1 2 1 2 3 2 1 2]';
% WTconstant = (pipe.e26.area * 10^5)/(1000*9.8);
% 
% [ lambdaD, lambdaC, pipe ] = Pipes( pipe, B_1, zo );
% [ mu_S_D, mu_S_C, valve ] = Valves_States( valve, B_1, zo );
% [ mu_I_D, mu_I_C, valve ] = Valves_Inputs( valve, B_1, zo);
% [ gammaD, gammaC, pipe ] = Tower( pipe, B_1, zo );
% [ C1, C2 ] = Output( lambdaC, mu_I_D, mu_S_C, B_1);
% [ alpha_S ] = Pumps( B_1 );
% 
% 
% A =  B_1 * (lambdaD + mu_S_D + gammaD) * B_1';
% 
% B1 =  (B_1 * mu_I_D + alpha_S);
% 
% B2 =  B_0;
% 
% S =  (1/WTconstant) * pinv(H_0) * H_1 * B_1';
% 
% B = - S * (A \ B1);
% B =[B(2) B(4) B(5:6)];
% 
% a =  S * (A \ B2);
% 
% C =  [- C1 * ( A \ B2 ); 1];
% C = [C(2); C(4);1];
% % C =  - C1 * ( A \ B2 );
% 
% D =  [C2 - C1 * ( A \ B1 ); zeros(1,8)];
% D = [ D(2,2) D(2,4) D(2,5) D(2,6);  D(4,2 ) D(4,4) D(4,5) D(4,6); zeros(1,4)];
% % D =  C2 - C1 * ( A \ B1 );

% S =  (1/WTconstant) * pinv(H_0) * H_1 * B_1';
% 
% N_c = [ N(:,5) N(:,6)];
% 
% Q_c = [ N(:,2) N(:,4)];
% 
% C11 = [ C1(2,:); C1(4,:)];
% 
% C22 = [C2(2,2) C2(2,4);
%     C2(4,2) C2(4,4)];
% 
% A_c =  S * (A \ B_0);
% 
% E_s = S * (A \ Q_c);
% 
% B_s = - S * (A \ N_c);
% 
% % D_s = [C2(2,5) C2(2,6); C2(4,5) C2(4,6) ; zeros(1,2)];
% D_s = [C11 * (A \ N_c); zeros(1,2) ];
% 
% C_c =  [- C11 * ( A \ B_0 ); 1];
% 
% K_s =  [C22 - C11 * ( A \ Q_c ); zeros(1,2)];
% 
% B_c = [B_s E_s];
% D_c = [D_s K_s];

a = -0.001119415617640;

B = [ 0.000297184296396894 1.011362712563936e-4 -1.757484437305615e-7 -2.924000584714482e-08 ];
%     B = [par(2) par(3)];

% C = 1;
C = [ linear_b_est(1); linear_b_est(2)];

D = [ -linear_b_est(3) -linear_b_est(4) linear_b_est(5) linear_b_est(6);
    -linear_b_est(7) linear_b_est(8) linear_b_est(9) linear_b_est(10)];



end
% 
% pipe.lambda(1) pipe.lambda(2) pipe.lambda(3) pipe.lambda(4) pipe.lambda(5)... 
%     pipe.lambda(6) pipe.lambda(7) pipe.lambda(8) pipe.lambda(10) pipe.lambda(13)...
%     pipe.lambda(14) pipe.lambda(16) pipe.lambda(19) pipe.lambda(20) pipe.lambda(21)...
%     valve.muI(15) valve.muI(17) valve.muI(22) valve.muI(23)...
%     valve.muS(15) valve.muS(17) valve.muS(22) valve.muS(23)

