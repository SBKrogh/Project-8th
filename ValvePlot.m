fig=figure(1)
c.ngl=3.2;
c.OD=(0:0.0001:1);
a=c.OD.*90;
a_min=15;
a_max=90;
Kv=zeros(1,length(a));

for i=1:length(c.OD)

if (a(i) <= a_min )
   Kv(i)=0; 
elseif ((a(i)-a_min)/(a_max-a_min) <= 1/c.ngl )
Kv(i)=1*(a(i)-a_min)/(a_max-a_min)*c.ngl*exp(1-c.ngl);

elseif ((a(i)-a_min)/(a_max-a_min) > 1/c.ngl)
Kv(i)=1*exp(c.ngl*(((a(i)-a_min)/(a_max-a_min))-1));

end    


end
reduce_plot(a,Kv)
title('Belimo R2015-1-S1')
xlabel('OD [%]') % x-axis label
ylabel('Kv(OD)/Kvs') % y-axis label