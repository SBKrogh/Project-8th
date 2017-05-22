t_clock = 345599*2;

d_intt = load('Disturbance_Plot.mat');

d_int =[d_intt.Data_OD d_intt.Data_OD];

t_h = 1+floor(t_clock/3600);
if t_h / 24 ~= floor(t_h/24)
  t_int  = t_h - floor(t_h/24)*24;
else
  t_int = 24;
end

d = d_int(t_int,:)'