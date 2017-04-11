%Pipe function
function lambda = pipe(Cp,i,B_1,z)
lambda = Cp(i).* abs(B_1(:,i)'*z).*B_1(:,i)'*z;
end

