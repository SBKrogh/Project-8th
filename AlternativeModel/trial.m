%% setup of the ident model
FileName      = 'zdot';       % File describing the model structure.
Order         = [15 8 7];           % Vector [Ny Nu Nx]: outputs Ny, inputs Nu, and states Nx..
Parameters    = {[Cp(1); Cp(2); Cp(3); Cp(4); Cp(5); Cp(6); Cp(7); Cp(9); Cp(10); Cp(13); Cp(14); ...
    Cp(16); Cp(19); Cp(20); Cp(21)]};

x0 = [0 0 0 0 0 0 0]';

InitialStates = x0;            % Initial initial states.
Ts            = 0;                 % Time-continuous system.
nlgr = idnlgrey(FileName, Order, Parameters, InitialStates, Ts, ...
                'Name', 'wAAUterWall');
       
% %Specify input and output names, and units.
% set(nlgr, 'InputName', {'c02dp', 'c16dp', 'c18dp','c25dp', 'c32dp', 'c20OD', 'c24OD', 'c27OD', 'c31OD', 'c34OD', 'c38OD'},...
%           'InputUnit', {'bar', 'bar', 'bar','bar','bar','%','%','%','%','%','%'},...
%           'OutputName', {  'c18relp','c25relp', 'c32relp','c21-22relp', 'c23relp', 'c28-29relp','c30relp', 'c35-36relp','c37relp'}, ...
%           'OutputUnit', { 'bar','bar','bar','bar', 'bar', 'bar','bar','bar','bar'},                         ...
%           'TimeUnit', 's');
% 
% % Specify names and units of the initial states and parameters.
% setinit(nlgr, 'Name', {'c09q' 'c13q' 'c21q' 'c23q' 'c26q' 'c28q' 'c30q' 'c33q' 'c35q' 'c37q' });
% setinit(nlgr, 'Unit', {'m^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' 'm^3/h' });
% setpar(nlgr, 'Name', {'Kf'});
% setpar(nlgr, 'Unit', {'-'});
% View the initial model.
disp('The basic information about the model.')
size(nlgr)
present(nlgr)
 opt = compareOptions;
 opt.InitialCondition = x0;
datestr(now)
%compare(zF, nlgr, [], opt)
%compare(z, nlgr, nlgrZF , 'init', 'm');
nlgrF = pem(z_ident, nlgr,'Display', 'on' , 'InitialState', x0_ident );
nlgrF.Name = 'wAAUterWallEstimate';