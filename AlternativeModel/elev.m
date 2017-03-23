%Elevation function 
function xi = elev(delta_z,i,z)
g = 9.82; % m/s^2 
xi = (delta_z(i)*g*1000)/(10^5);
end

