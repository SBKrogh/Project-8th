function  Cv  = Cvalue( OD )

ngl = 3.2;
a = OD*90;
a_min = 15;
a_max = 90;
 
if (a <= a_min )
    Cv = 0; 
elseif ((a-a_min)/(a_max-a_min) <= 1/ngl )
    Cv = 1*(a-a_min)/(a_max-a_min)*ngl*exp(1-ngl);

elseif ((a-a_min)/(a_max-a_min) > 1/ngl)
    Cv = 1*exp(ngl*(((a-a_min)/(a_max-a_min))-1));
end    

end

