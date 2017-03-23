%Main Pump function
function alpha = pump_main(omega_main,i,flag,B_1,z)

%Parameters for the Grundfos UPMXL GEO 25-125 180 pump 
A_h01 = 1.2024; 
A_h11 = 0.0098; 
A_h21 = 0.0147; 
kv100 = 1; 


alpha = (((2/(kv100)^2)-A_h21)*abs(B_1(:,i)'*z).*B_1(:,i)'*z + A_h11*omega_main(i).*B_1(:,i)'*z + A_h01*omega_main(i).^2).*flag(i);
end