%Valve function
function mu = valve(Cv,i,B_1,z,k,j)
%z = sym('z', [7; 1]);,k 

if k == 0

mu = (Cv(i,:)* (abs(B_1(:,i)'*z).*B_1(:,i)'*z))';

else 
    
mu = (Cv(i,:)* (abs(B_1(:,i)'*z(j,:)').*B_1(:,i)'*z(j,:)'))';

end
    
end

