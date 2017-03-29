%Pipe function
function lambda2 = pipe(Cp,i,B_1,U,z)

lambda = Cp(i).* (abs(B_1(:,i)'*z).*B_1(:,i)'*z);

lambda2 = (repmat(lambda,length(U),1));
end

