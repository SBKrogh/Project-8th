dt = 0.05;
load('NameOfDataset.mat');
t = 0:dt:((length(NameOfDataset)-1)*dt);
t =t';
y = NameOfDataset;
u = (repmat(1,4,length(t)))';
save ('measwater.mat','t','y','u')