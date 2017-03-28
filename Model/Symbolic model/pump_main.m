%Main Pump function
function alpha = pump_main(omega_main,i,flag,B_1)

%Parameters for the Grundfos UPMXL GEO 25-125 180 pump 
A_h01 = 1.2024; 
A_h11 = 0.0098; 
A_h21 = 0.0147; 
kv100 = 1; 

%z = sym('z', [7; 1]);
syms z1(t) z2(t) z3(t) z4(t) z5(t) z6(t) z7(t)
z= [z1(t); z2(t); z3(t); z4(t); z5(t); z6(t); z7(t)];

alpha = (((2/(kv100)^2)-A_h21)*abs(B_1(:,i)'*z).*B_1(:,i)'*z + A_h11*omega_main(i).*B_1(:,i)'*z + A_h01*omega_main(i).^2).*flag(i);
end