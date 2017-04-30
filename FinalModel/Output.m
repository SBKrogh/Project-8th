function [ C1, C2 ] = Output( lambdaC, mu_I_C, mu_S_C, B_1)

C1 = zeros(8);
C2 = zeros(8);

% output matrix depending on states
C1(3,:) = (lambdaC(13) * B_1(:,13)' + lambdaC(16) * B_1(:,16)' + mu_S_C(17) * B_1(:,17)');
C1(4,:) = (lambdaC(19) * B_1(:,19)' + lambdaC(7) * B_1(:,7)' + mu_S_C(23) * B_1(:,23)');
C1(6,:) = (mu_S_C(17)) * B_1(:,17)';
C1(5,:) = (lambdaC(14) * B_1(:,14)' + mu_S_C(15) * B_1(:,15)') ;
C1(8,:) = (mu_S_C(23)) * B_1(:,23)';
C1(7,:) = (lambdaC(21) * B_1(:,21)' + mu_S_C(22) * B_1(:,22)');

% output matrix depending on inputs
C2(1,5) = -1;
C2(2,6) = -1;
C2(3,2) = mu_I_C(17);
C2(3,7) = 1;
C2(4,4) = mu_I_C(23);
C2(4,8) = 1;
C2(6,2) = mu_I_C(17);
C2(5,1) = mu_I_C(15);
C2(8,4) = mu_I_C(23);
C2(7,3) = mu_I_C(22);



end

