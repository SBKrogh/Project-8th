%Elevation function 
function xi2 = elev(delta_z,i,U)
g = 9.82; % m/s^2 
xi = (delta_z(i)*g*1000)/(10^5);

xi2 = (repmat(xi,length(U),1));
end

