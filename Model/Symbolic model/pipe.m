%Pipe function
function lambda2 = pipe(Cp,i,B_1,U,z,k,j)
%z = sym('z', [7; 1]);
if k == 0
    
lambda = Cp(i).* (abs(B_1(:,i)'*z).*B_1(:,i)'*z);

lambda2 = (repmat(lambda,length(U),1));

else 
    
lambda2 = Cp(i).* (abs(B_1(:,i)'*z(j,:)').*B_1(:,i)'*z(j,:)');


end

end

