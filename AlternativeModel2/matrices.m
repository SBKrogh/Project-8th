H = [ zeros(1,8) 1 0 1 0 0 0 -1 0 -1 0 0 0 0 -1 -1 0 -1;
    1 zeros(1,7) -1 zeros(1,16);
    -1 1 0 0 -1 zeros(1,18) 1 0;
    0 -1 1 zeros(1,8) 1 zeros(1,13);
    0 0 -1 -1 zeros(1,13) 1 zeros(1,7);
    0 0 0 1 1 0 0 0 0 -1 zeros(1,15);    
    zeros(1,9) 1 -1 zeros(1,14);
    zeros(1,11) -1 1 zeros(1,12);    
    zeros(1,5) 1 0 1 0 0 0 0 -1 0 0 1 zeros(1,9);
    zeros(1,15) -1 1 zeros(1,8);
    zeros(1,5) -1 zeros(1,7) 1 zeros(1,11);
    zeros(1,13) -1 1 zeros(1,10);
    zeros(1,17) -1 1 zeros(1,6);
    zeros(1,6) 1 -1 zeros(1,10) -1 1 zeros(1,5);
    zeros(1,6) -1 zeros(1,15) 1 0 0;
    zeros(1,19) -1 1 zeros(1,4);
    zeros(1,20) -1 1 zeros(1,3);
    zeros(1,23) -1 1];

Bt = [1 zeros(1,14) 1 1;
    0 0 0 1 1 0 0 1 1 zeros(1,6) -1 -1;
    0 0 0 -1 -1 0 0 -1 -1 ones(1,5) 0 0 0;
    0 1 1 zeros(1,6) ones(1,5) 0 0 0;
    0 1 1 zeros(1,12) 1 1;
    zeros(1,5) 1 1 -1 -1 zeros(1,8);
    zeros(1,11) -1 -1 -1 1 0 0;
    zeros(1,7) -1 -1 0 0 1 1 1 0 0 0];
B = [eye(8) Bt];

%Reduced B matrix: B_1 for the parameter estimation
Bt_a = Bt(3:8,1:15);
Bt_b = [Bt(1,1:15)+Bt(2,1:15)];
e3 = [1;0;zeros(1,5)'];
Bt_1 = vertcat(Bt_b,Bt_a);
B_1 = [eye(7) Bt_1(:,1:1) e3 Bt_1(:,2:15)];
B_1(4,:) = [zeros(1,3) 1 zeros(1,3) 0 1 1 1 1 1 0 0 1 1 0 0 0 0 0 0];

% Reduced H matrix: H_1 for the parameter estimation
H_a = H(1:17,1:23);
H_1 = [H_a(:,1:1) H_a(:,3:9) H_a(:,2) H_a(:,10:23)];
H_11 = H_1(2:end, :);
H_10 = H_1(1,:);
 

%Check H_1*B_1'
check = H_1*B_1';
% if check == 0
%     disp('correct')
% end



