%Valve function
function mu = valve(Cv,i,B_1,U)
%z = sym('z', [7; 1]);
syms z1(t) z2(t) z3(t) z4(t) z5(t) z6(t) z7(t)
z= [z1(t); z2(t); z3(t); z4(t); z5(t); z6(t); z7(t)];


mu = (Cv(i,:)* (abs(B_1(:,i)'*z).*B_1(:,i)'*z))';
end

