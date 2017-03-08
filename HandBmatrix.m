clear all, clc;
H = [ zeros(1,8) 1 0 1 0 0 0 -1 0 -1 0 0 0 0 -1 -1 0 -1;
    1 zeros(1,7) -1 zeros(1,16);
    -1 1 0 0 -1 zeros(1,18) 1 0;
    0 -1 1 zeros(1,8) 1 zeros(1,13);
    0 0 -1 -1 zeros(1,13) 1 zeros(1,7);
    0 0 0 1 1 0 0 0 0 -1 zeros(1,15);    
    zeros(1,9) 1 -1 zeros(1,14);
    zeros(1,11) -1 1 zeros(1,12);    
    zeros(1,5) 1 0 1 0 0 0 0 -1 0 0 1 zeros(1,9);
    zeros(1,15) -1 1 zeros(1,8);
    zeros(1,5) -1 zeros(1,7) 1 zeros(1,11);
    zeros(1,13) -1 1 zeros(1,10);
    zeros(1,17) -1 1 zeros(1,6);
    zeros(1,6) 1 -1 zeros(1,10) -1 1 zeros(1,5);
    zeros(1,6) -1 zeros(1,15) 1 0 0;
    zeros(1,19) -1 1 zeros(1,4);
    zeros(1,20) -1 1 zeros(1,3);
    zeros(1,23) -1 1];

Bt = [1 zeros(1,14) 1 1;
    0 0 0 1 1 0 0 1 1 zeros(1,6) -1 -1;
    0 0 0 -1 -1 0 0 -1 -1 ones(1,5) 0 0 0;
    0 1 1 zeros(1,6) ones(1,5) 0 0 0;
    0 1 1 zeros(1,12) 1 1;
    zeros(1,5) 1 1 -1 -1 zeros(1,8);
    zeros(1,11) -1 -1 -1 1 0 0;
    zeros(1,7) -1 -1 0 0 1 1 1 0 0 0];
B = [eye(8) Bt];
    
H * B'