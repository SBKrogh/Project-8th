%% Build up the f function

function dzdt = zdot(t,z)

pump_param;
valve_param;
elev_param;
pipe_param;
matrices;

N = 23;

z = [z(1) z(2) z(3) z(4) z(5) z(6) z(7)]';

for i = 1:N
        f(i,1) = - pipe(Cp,i,B_1,z) - elev(delta_z,i,z) - valve(Cv,i,B_1,z) + pump_main(omega_main,i,flag,B_1,z) - pump_side(omega_side,i,flag,B_1,z); %Pump_side is missing !!!
end

for i = 1:N
        J(i,1) = inertia(L,D,i);
end


Theta = (B_1*diag(J)*B_1')\B_1;

dzdt =  Theta * f;

end

