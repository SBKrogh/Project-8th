Hp = 24;
syms k
for i = Hp : -1 : 1
    
    S(i,:) = symsum(9^k * 2, k, i, 24);
    
end
