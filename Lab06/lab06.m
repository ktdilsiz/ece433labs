lab05;

OS = input('Overshoot? : ');
Ts = input('Settling Time? : ');
r = input('r? : ');
Konstant = log(OS/100);

zeta = sqrt(Konstant^2/(pi^2 + Konstant^2));

Wn = 4/(zeta*Ts);

%  K1 = Wn^2/alpha;
%  
%  Kp = (2*zeta*Wn - tau)/alpha;

%lab 7 variables when zero = r*K1/Kp

p = (r-1)*Wn/(2*zeta);
% Kp = r*Wn^2/alpha;
% K1 = (((r - 1)*Wn*Kp/2)/zeta)/r;
% Kd = ((2*zeta*Wn + p) - tau)/alpha;

% clearvars -except Kp Kd K1 alpha tau

z = zeta;
a = alpha;
wn = Wn;

Kp = (r/a)*wn^2;
K1 = (r-1)*wn^3/(2*z*a);
Kd = (((2*z*wn)-tau +(((r-1)*wn)/(2*z)))/a);

% kp = (r/a)*wn^2;
% ki = (r-1)*wn^3/(2*z*a);
% kd = (((2*z*wn)-tau +(((r-1)*wn)/(2*z)))/a);

% i = 1;
% for t = 0.5:0.05:15
%     r = t; 
%     kp(i) = (r/a)*wn^2;
%     ki(i) = (r-1)*wn^3/(2*z*a);
%     kd(i) = (((2*z*wn)-tau +(((r-1)*wn)/(2*z)))/a);
%     e(i) = 1/(1+kp(i));
%     i=i+1;
% end
% plot(e)
% 
% n = (pi/2).*[a*kp, a*ki];
% d = [1, tau+kd*a, kp*a, ki*a];
% t = tf(n,d);
% ltiview(t)

%(-352*pi/180)/10 for potemtiometer
%((-1000*2*pi/60)/1.5)/Kg for Tacometer
%2*pi/(1024*4) for Encoder

% potentiometer from HIL Read Analog Timebase 0 --> continous rise theta
% encoder from HIL Read Encoder 0 --> sawtooth
% tacometer rom HIL Read Analog Timebase 1 --> omega/speed

% Signal Generator amplitude 1, Frequency 0.4, Hertz, User simulation time
% bias of 1.5 --> u + 1.5

% HIL Write Analog

% Triangle wave
% Repeating Sequence
% [0 1/4/f 1/2/f 3/4/f 1/f]
% [0 m 0 -m 0]

%[alpha][1 tau 0]
%
% 
%
%
%

