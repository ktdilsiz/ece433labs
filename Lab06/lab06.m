lab05;

OS = input('Overshoot? : ');
Ts = input('Settling Time? : ');

Konstant = log(OS/100);

zeta = sqrt(Konstant^2/(pi^2 + Konstant^2));

Wn = 4/(zeta*Ts);

K1 = Wn^2/alpha;

Kp = (2*zeta*Wn - tau)/alpha;

