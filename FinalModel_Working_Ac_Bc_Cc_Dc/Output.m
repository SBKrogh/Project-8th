function [ C1, C2 ] = Output( lambdaC, mu_I_C, mu_S_C, B_1)

C1 = zeros(4, 8);
C2 = zeros(4, 8);

% output matrix depending on states
% C1(1,:) = (lambdaC(13) * B_1(:,13)' + lambdaC(16) * B_1(:,16)' + mu_S_C(17) * B_1(:,17)');
% C1(2,:) = (lambdaC(19) * B_1(:,19)' + lambdaC(7) * B_1(:,7)' + mu_S_C(23) * B_1(:,23)');
C1(1,:) = (lambdaC(14) * B_1(:,14)' + mu_S_C(15) * B_1(:,15)') ;
C1(2,:) = (mu_S_C(17) * B_1(:,17)');
C1(3,:) = (lambdaC(21) * B_1(:,21)' + mu_S_C(22) * B_1(:,22)');
C1(4,:) = (mu_S_C(23) * B_1(:,23)');

% output matrix depending on inputs

% C2(1,2) = mu_I_C(17,2);
% C2(1,7) = 1;
% C2(2,4) = mu_I_C(23,4);
% C2(2,8) = 1;
C2(1,1) = mu_I_C(15,1);
C2(2,2) = mu_I_C(17,2);
C2(3,3) = mu_I_C(22,3);
C2(4,4) = mu_I_C(23,4);


end

