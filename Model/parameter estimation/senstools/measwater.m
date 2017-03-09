dt = 0.065;
load('NameOfDataset.mat');
t = 0:dt:((length(NameOfDataset)-1)*dt);
t =t';
y = NameOfDataset;
u = (repmat(-101,1,length(t)))';
save ('measwater.mat','t','y','u')