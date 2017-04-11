function Cp = calcFric(c)

wT = mean([10 20]);        % Water Temperature interval
wv = mean([0.5 1.5]);       % Water velocity interval in m/s
A   = pi*c.D^2/4;
Q = wv*A;                   % Average flow in the pipe
% e = 0.00001;                % Average roughness insidea PEM pipe wall
rho = 1000;                 % water density

vis=1.792*10^(-6)*(1+(wT/25)^1.165)^(-1);
% velocity to flow

%Reynold number
R=(4*Q)/(pi*vis*c.D);

% pipe friction factor
f=1.325*(log(c.e/(3.7*c.D))+5.74/R^0.9 )^(-2);



% Cp= f*((8*c.L*par.rho)/(pi^2*c.D^5*10^5*3600^2))+c.Kf*((8*par.rho)/(pi^2*c.D^4*10^5*3600^2));

Cp= f*((8*c.L*rho)/(pi^2*c.D^5))+c.kf*((8*rho)/(pi^2*c.D^4));


end


