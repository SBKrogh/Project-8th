function [valve, pump, q] = updateInputs(valve, pump, u, q)

% Update Valves 
valve.e13.Cv = Cvalue(u(:,1));

if valve.e13.Cv == 0
    valve.e13.Cv = 0.0001;
end

valve.e15.Cv = Cvalue(u(:,2));

if valve.e15.Cv == 0
    valve.e15.Cv = 0.0001;
end

valve.e20.Cv = Cvalue(u(:,3));

if valve.e20.Cv == 0
    valve.e20.Cv = 0.0001;
end

valve.e22.Cv = Cvalue(u(:,4));

if valve.e22.Cv == 0
    valve.e22.Cv = 0.0001;
end

% Update Pumps
pump.e01.dP = u(:,5);
pump.e08.dP = u(:,6);
pump.e09.dP = u(:,7);
pump.e16.dP = u(:,8);

% if  u(:,1) ~= 0
% valve.e13.Cv = u(:,1);
% else
% valve.e13.Cv = 0.0001;
% end
% 
% if  u(:,2) ~= 0
% valve.e15.Cv = u(:,2);
% else
% valve.e15.Cv = 0.0001;
% end
% 
% if  u(:,3) ~= 0
% valve.e20.Cv = u(:,3);
% else
% valve.e20.Cv = 0.0001;
% end
% 
% if  u(:,4) ~= 0
% valve.e22.Cv = u(:,4);
% else
% valve.e22.Cv = 0.0001;
% end

end