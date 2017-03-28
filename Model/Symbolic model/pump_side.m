%Main Pump function
function alpha = pump_side(omega_side,i,flag,B_1)
%Parameters for the Grundfos UPM2 25-60 180 pump  
A_h02 = 0.6921; 
A_h12 = -0.0177; 
A_h22 = 0.0179; 
kv100 = 1; 
%syms q(23);

syms z1(t) z2(t) z3(t) z4(t) z5(t) z6(t) z7(t)
z= [z1(t); z2(t); z3(t); z4(t); z5(t); z6(t); z7(t)];

alpha =(((2/kv100^2)-A_h22)*B_1(:,i)'*z.*abs(B_1(:,i)'*z) + A_h12*omega_side(i).*B_1(:,i)'*z + A_h02*omega_side(i).^2).*flag(i);
end