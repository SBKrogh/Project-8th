%Valve function
function mu = valve(Cv,i,B_1,U,z)
%z = sym('z', [7; 1]);



mu = (Cv(i,:)* (abs(B_1(:,i)'*z).*B_1(:,i)'*z))';
end

