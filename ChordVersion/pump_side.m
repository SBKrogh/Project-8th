%Main Pump function
function alpha = pump_side(omega_side,i,flag,B_1,z)
%Parameters for the Grundfos UPM2 25-60 180 pump  
A_h02 = 0.6921; 
A_h12 = -0.0177; 
A_h22 = 0.0179; 
kv100 = 1; 

alpha = (((2/(kv100)^2)-A_h22)*abs(B_1(:,i)'*z).*B_1(:,i)'*z + A_h12*omega_side(i).*B_1(:,i)'*z + A_h02*omega_side(i).^2).*flag(i);

end