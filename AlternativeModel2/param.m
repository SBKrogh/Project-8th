function [out,t] = param()
% Call zdot function ot obtain chords flows

% Initial condition
init = [1 1 1 1 4 2 3]';

% Differential equation to obtain zdot vector
[t,z] = ode45 (@zdot, [0:1:100], init);

% Initialize parameters 
pump_param;
valve_param;
elev_param;
pipe_param;
matrices;

% Length of edges
N = 23;

% Length of the sample time used for z
M = length (z);

for j = 1:M
    
for i = 1:N
        z(j,:);
        f(i,j) = - pipe(Cp,i,B_1,z(j,:)') - elev(delta_z,i,z(j,:)') - valve(Cv,i,B_1,z(j,:)') + pump_main(omega_main,i,flag,B_1,z(j,:)') - pump_side(omega_side,i,flag,B_1,z(j,:)'); %Pump_side is missing !!!
end

for i = 1:N
        J(i,j) = inertia(L,D,i);
end

 Theta(:,:,j) = (B_1*diag(J(:,j))*B_1')\B_1;
 
 % Obtain the pressure difference on edges
 Dp(:,j)  = ( diag(J(:,j)) * B_1' * Theta(:,:,j) + eye(23) ) * f(:,j);  
 
 % Split atmospheric pressure from others
 H_11 = H_1(2:end, :);
 H_10 = H_1(1,:);
 
 % Apply the pseudo-inverse
 invH_11 = pinv(H_11');
 
 pa = 0;
 
 % obtain pressure difference on each node
 p(:,j) = invH_11 * (Dp(:,j) - H_10'*pa) ;
 
 out = [p(2,:); p(4,:); p(5,:); p(7,:); p(10,:); p(11,:); p(15,:) ;p(16,:)];
 
end

end

% Dp = ( J * B_1' * (Theta)\B_1 + eye(23) ) * f;