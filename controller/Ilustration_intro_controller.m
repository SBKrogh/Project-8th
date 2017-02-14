close all
clear all
clc

syms x y
% Cost function
    f = (x^2 + y);
    h(1) = fsurf(f,[-5 5 -3 3],'FaceColor','blue')       
    
hold on
%Constraint
   % g = x+y;
    g = 2;
    h(2)= fsurf(g,[-5 5 -3 3],'FaceColor','red');

%How do we want to figure to look
h(1).FaceAlpha = 0.5;
h(2).FaceAlpha = 1;

%Label
xlabel('u');
ylabel('\rho_{wt}');
zlabel('DKK/h');
title('Test of 3D plot')