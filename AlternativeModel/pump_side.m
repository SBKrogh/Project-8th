%Main Pump function
function alpha = pump_side(c,q)

% alpha = (((2/(c.kv100)^2)-c.Ah22)* abs(q).* q + c.Ah12 * c.omega * q + c.Ah02 * c.omega.^2);
alpha = c.dP;
end