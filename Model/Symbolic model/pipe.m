%Pipe function
function lambda2 = pipe(Cp,i,B_1,U)
%z = sym('z', [7; 1]);
syms z1(t) z2(t) z3(t) z4(t) z5(t) z6(t) z7(t)
z= [z1(t); z2(t); z3(t); z4(t); z5(t); z6(t); z7(t)];

lambda = Cp(i).* (abs(B_1(:,i)'*z).*B_1(:,i)'*z);

lambda2 = (repmat(lambda,length(U),1));
end

