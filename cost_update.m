function [Lambda_A,Lambda_B,Lambda_C] = cost_update(data,Lambda_1,Lambda_2,Lambda_3,Hp,t_h)

Lambda_A = zeros(48,48);
Lambda_B = zeros(48,48);
Lambda_C = zeros(48,24);

persistent i
if isempty(i)
    i = 0;
end

n = length(Lambda_1);
Lambda_A = Lambda_1 * data(1+t_h);

for i = 1:Hp-1
    Lambda_A(i + n: i + n + 1, i + n : i + n + 1) = Lambda_1 * data(i + 1+t_h);
    n = n + 1;
end

n = length(Lambda_2);
m = size(Lambda_2);
m = m(1);
Lambda_B = Lambda_2 * data(1+t_h);

for i = 1:Hp-1
    Lambda_B(i + m: i + m + 1, 1 + i*n :  i*n +n ) = Lambda_2 * data(i + 1+t_h);
    m = m + 1;
end

m = size(Lambda_3);
m = m(1);
Lambda_C = Lambda_3 * data(1+t_h);

for i = 1:Hp-1
    Lambda_C(i + m: i + m + 1,  i + 1 ) = Lambda_3 * data(i + 1+t_h);
    m = m + 1;
end

end