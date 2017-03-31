dt = 0.05;
load('parest_test_data.mat');
t = 0:dt:((length(y)-1)*dt);
t =t';
%y = NameOfDataset;
%u = (repmat(1,8,length(t)))';
save ('measwater.mat','t','y','u')