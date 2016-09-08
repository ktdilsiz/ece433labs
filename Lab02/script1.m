
R = 5;
L = 0.05e-3;
k = 2e5;
b = 50;
m = 4e-3;
r = 0.04;
N = 50;
B = 0.25;
Kf = 2*pi*r*N*B;
% Settling time : 0.000706
% peak time: 0.00115
% percent overshoot:  0.0587
% steady-state: 3.14e-6


constant = R*k;

s = tf('s');
diffq9 = (Kf)/((s^3)*(L*m) + (s^2)*(L*b + R*m) + (s)*(R*b + L*k + Kf^2) + constant);

ltiview(diffq9)



% frequency 200 --> 3.139844527182682e-06
% frequency 2000 --> 2.971587003166542e-06
% frequency 20000 --> 3.547610542410406e-07

% as the frequency increases the magnitude of gain decreases
% the wave goes into steady state around 20000rad/sec
% at 20000 frequency you can see the matching values in simulink

% Settling time : 0.000706
% percent overshoot:  0.0587
% steady-state: 3.14e-6