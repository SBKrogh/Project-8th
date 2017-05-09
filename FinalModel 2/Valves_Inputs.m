function [ mu_I_D, mu_I_C, c ] = Valves_Inputs( c, B_1, zo )
%VALVES Summary of this function goes here
%   Detailed explanation goes here
mu = zeros(24,8);

mu(15,1) = ( - 32 * exp ( 192/25 - ( 32 * c.e13.Oo * 90 / 375) ) * B_1(:,15)' * zo * abs(B_1(:,15)' * zo )) /375;

mu(17,2) = ( - 32 * exp ( 192/25 - ( 32 * c.e15.Oo * 90 / 375) ) * B_1(:,17)' * zo * abs(B_1(:,17)' * zo )) /375;

mu(22,3) = ( - 32 * exp ( 192/25 - ( 32 * c.e20.Oo * 90 / 375) ) * B_1(:,22)' * zo * abs(B_1(:,22)' * zo )) /375;

mu(23,4) = ( - 32 * exp ( 192/25 - ( 32 * c.e22.Oo * 90 / 375) ) * B_1(:,23)' * zo * abs(B_1(:,23)' * zo )) /375;

% (-2*3.2*exp(3.2*((12/5)-(2*c.e13.Oo * 90) /75))  * B_1(:,15)' * zo * abs(B_1(:,15)' * zo)) /75;
% mu(17,2) = (-2*3.2*exp(3.2*((12/5)-(2*c.e15.Oo * 90) /75))  * B_1(:,17)' * zo * abs(B_1(:,17)' * zo)) /75;
% mu(22,3) = (-2*3.2*exp(3.2*((12/5)-(2*c.e20.Oo * 90) /75))  * B_1(:,22)' * zo * abs(B_1(:,22)' * zo)) /75;
% mu(23,4) = (-2*3.2*exp(3.2*((12/5)-(2*c.e22.Oo * 90) /75))  * B_1(:,23)' * zo * abs(B_1(:,23)' * zo)) /75;

c.muI = mu;

mu_I_D = mu;
mu_I_C = mu;




end

