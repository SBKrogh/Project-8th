function [valve, pump] = updateInputs(valve, pump, u)

% Update Valves 

valve.e13.Cv = u(1,1);
valve.e15.Cv = u(1,2);
valve.e20.Cv = u(1,3);
valve.e22.Cv = u(1,4);

% Update Pumps
pump.e01.dP = u(1,5);
pump.e08.dP = u(1,6);
pump.e09.dP = u(1,7);
pump.e16.dP = u(1,8);




end