close all
clc
%%
trock;                  %Load system matrices
load('inputdata');      %U is definded here

d_hat = [1;1;1;1];      %Define the disturbance as a constant, just for now
x0 = 0;
t = [1:Ts:Ts*length(U)];

%Standard setup for ss with disturbance 
%x[k+1]=Ax[k]+Bu[k]+Ke[k]
%y[k]=Cx[k]+Du[k]+e[k].

E_new = Ed*pinv(Kd);        

sys = idss(Ad,Bd,Cd,Dd,E_new,x0,Ts,...
    'StateName','WaterLevel','InputName','Input','OutputName','deltaP_cp');

%%%%%%%%%%%%%%% Simulation %%%%%%%%%%%%%%% 

[y,t,x] = lsim(sys,U,t,x0);

plot(y)
hold on
plot(x)
legend('DeltaP_{cp_1}','DeltaP_{cp_2}','DeltaP_{WT}')