%Valve parameters
Cv = zeros(length(U),23)';
Cv(15,:) = (U(:,1));
Cv(17,:) = (U(:,2));
Cv(22,:) = (U(:,3));
Cv(23,:) = (U(:,4));
