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
K1 = (((r - 1)*Wn*Kp/2)/zeta)/r;
Kp = r*Wn^2/alpha;
Kd = ((2*zeta*Wn + p) - tau)/alpha;

% clearvars -except Kp Kd K1 alpha tau

z = zeta;
a = alpha;
wn = Wn;

i = 1;
for t = 0.5:0.05:15
    r = t; 
    kp(i) = (r/a)*wn^2;
    ki(i) = (r-1)*wn^3/(2*z*a);
    kd(i) = (((2*z*wn)-tau +(((r-1)*wn)/(2*z)))/a);
    e(i) = 1/(1+kp(i));
    i=i+1;
end
plot(e)

n = (pi/2).*[a*kp, a*ki];
d = [1, tau+kd*a, kp*a, ki*a];
t = tf(n,d);
% ltiview(t)