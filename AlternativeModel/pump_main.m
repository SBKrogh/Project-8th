%Main Pump function
function alpha = pump_main(c,q)

% alpha = (((2/(c.kv100)^2)-c.Ah21) * abs(q) * q + c.Ah11 * c.omega * q + c.Ah01 * c.omega.^2);
alpha = c.dP;
end