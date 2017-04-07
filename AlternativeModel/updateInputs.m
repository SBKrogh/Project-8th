function [valve, pump, q] = updateInputs(valve, pump, u, q)

% Update Valves 

if  u(:,1) ~= 0
valve.e13.Cv = u(:,1);
else
valve.e13.Cv = 0.0001;
q(5) = 0;
q(14) = 0;
q(15) = 0;
end

if  u(:,2) ~= 0
valve.e15.Cv = u(:,2);
else
valve.e15.Cv = 0.0001;
q(17) = 0;
q(16) = 0;
end

if  u(:,3) ~= 0
valve.e20.Cv = u(:,3);
else
valve.e20.Cv = 0.0001;
q(22) = 0;
q(21) = 0;
q(20) = 0;
end

if  u(:,4) ~= 0
valve.e22.Cv = u(:,4);
else
valve.e22.Cv = 0.0001;
q(6) = 0;
q(23) = 0;
end

% valve.e13.Cv = u(:,1);
% valve.e15.Cv = u(:,2);
% valve.e20.Cv = u(:,3);
% valve.e22.Cv = u(:,4);

% Update Pumps
pump.e01.dP = u(:,5);
pump.e08.dP = u(:,6);
pump.e09.dP = u(:,7);
pump.e16.dP = u(:,8);




end