%Elevation function 
function xi2 = elev(delta_z,i,U,k)
g = 9.82; % m/s^2 

if k == 0 
    
xi = (delta_z(i)*g*1000)/(10^5);
xi2 = (repmat(xi,length(U),1));

else

xi2 = (delta_z(i)*g*1000)/(10^5);

end

