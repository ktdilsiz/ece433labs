%%lab4 controls

Rm = 2.6;
Lm = 0.18e-3;

KgHigh = 70;
KgLow = 14;
KgPaper = KgHigh;

JeqPaper = 0.00213;
JeqHigh = 9.76e-5;
JeqLow = 2.08e-5;

BeqHigh =  0.015;
BeqLow = 1.5e-4;
BeqPaper = BeqHigh;

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
Jeq = JeqPaper;
Kg = KgHigh;
Ka = KaHigh;
Kb = KbHigh;

Vm = 1:0.01:10;

%%end of section

%%

s = tf('s');

% G1 = 1/((s^2)/Ka + s*(Beq/(Jeq*Ka) + Rm/Ka) + Rm*Beq/(Jeq*Ka) + Kb);
% 
% G2 = 1/(s*Lm + Rm - Kb/(Beq/(Jeq*Ka) + s/Ka));
% 
% IoverW = Beq/(Jeq*Ka) + s/Ka;
% 
% G2alt = G1 * IoverW;

%%end of section

%%

% G1result = Jeq*Ka/(Rm*Beq + Jeq*Ka*Kb)
% IoverWresult = (Beq/(Jeq*Ka));
% 
% G2result = Jeq*Ka/(Rm*Jeq*Ka - Kb);
% 
% G2altresult = G1result * IoverWresult

%%end of section

%%
%Least Squares Estimation

load ThetaSim
load VSim
load Wsim
t = data(1,:)';
Vm = Vdata(2,:)';
W_tach = Wdata(2,:)';
theta = Tdata(2,:)';

% fs = 0.001;
% fc = 
% fcm = fc/(fs/2);
% [b,a] = butter(3, fcm);
% 
% dtheta = diff(theta);
% wf = filter(b,a,dtheta);
% wff= filtfilt(b,a,dtheta);
% 
% dwf1 = diff(W_tach);
% dwf2 = filter(W_tach);
% 
% dwff1 = diff(dw1);
% dwff2 = filtfilt(W_tach);
% 
% W = [
% Y = [
% Rw = W.'*W;
% Rwy = Rw\W.'*Y;
% Ei = (Y.*'Y) - Y.')*(Rw\(W.'*Y));
















