clc 
    A = 0.8187;
    B = [0.02102     0.00345  -7.995e-05  -7.345e-05];
    C = [0.4048; 0.5774];
    D = [0.05855     0.06303   -0.001981  -0.0001327;
         0.1194     0.04656   -9.32e-05   3.238e-05];
   
   sys = ss(Ad,[Bd Ed],Cd,[Dd Kd]);
%   sys = ss(A,B,C,D);
   
   input_int = [0 ; 0 ; 0 ; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1;
            1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1;
            1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1];
      %      1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1;
      %      1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1];
    input = [input_int input_int zeros(length(input_int),1) zeros(length(input_int),1)]./10;
    time = 0:Ts:Ts*(length(input)-1);
    
    [y,t,x] = lsim(sys,input',time);

plot(y)
hold on
plot(x)
legend('DeltaP_{cp_1}','DeltaP_{cp_2}','DeltaP_{WT}')
    
    
    
    
    
    