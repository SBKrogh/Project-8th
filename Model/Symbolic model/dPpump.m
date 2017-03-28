%Pressure diff in pumps 
function dpPump = dPpump(U,i)

dP_pump = [zeros(length(U),7) U(:,5) zeros(length(U),2) U(:,6) U(:,7) zeros(length(U),5) U(:,8) zeros(length(U),5)];
dpPump = dP_pump(:,i);
end

