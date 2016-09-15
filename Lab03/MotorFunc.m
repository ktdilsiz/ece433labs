%%lab3 controls

Rm = 2.6;
Lm = 0.18e-3;

KgHigh = 70;
KgLow = 14;
JeqHigh = 9.76e-5;
JeqLow = 2.08e-5;
BeqHigh =  0.015;
BeqLow = 1.5e-4;

Jg = 5.28e-5;
ng = 0.9;
nm = 0.69;
kt = 7.68e-3;
km = 7.68e-3;

KaHigh = ng*KgHigh*nm*kt/JeqHigh;
KaLow = ng*KgLow*nm*kt/JeqLow;
KbHigh = km*KgHigh;
KbLow = km*KgLow;

Beq = BeqHigh;
Jeq = JeqHigh;
Kg = KgHigh;
Ka = KaHigh;
Kb = KbHigh;

%%end of section

%%

s = tf('s');

G1 = 1/((s^2)/Ka + s*(Beq/(Jeq*Ka) + Rm/Ka) + Rm*Beq/(Jeq*Ka));

G2 = 1/(s*Lm + Rm - Kb/(Beq/(Jeq*Ka) + s/Ka));

%%end of section