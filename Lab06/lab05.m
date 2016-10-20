% %%lab4 controls
% 
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
% 
% %%end of section

%%

% s = tf('s');

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

load DataSim1
t = data(1,:)';
Vm = data(2,:)';
W_tach = data(3,:)';
theta = data(4,:)';

fs = 1000;
k = 36;
    fcm = k / (fs/2);
    
    [b,a] = butter(3, fcm);
    
    omega = diff(theta)*fs;
    
    wf = filter(b,a,omega);
    wff = filtfilt(b,a,omega);
    
    dwf = filter(b,a,diff(wf)*fs);
    dwff = filtfilt(b,a,diff(wff)*fs);
    
    index = 21:length(t)-20;
    W = [dwff(index) wff(index)];
    Y = Vm(index);
    
    Rw = W'*W;
    Rwy = W'*Y;
    RwInv = inv(Rw);

    Ry = Y'*Y;
    Ryw = Y'*W;
    
    K = RwInv*Rwy;
    
    Ei = sqrt((Ry - Ryw*RwInv*Rwy)/Ry);
    
    alpha = 1/K(1);
    tau = K(2)*alpha;
     
%[Eimin, I] = min(Ei)
%plot(fc,Ei);

%(-352*pi/180)/10 for potemtiometer
%((-1000*2*pi/60)/1.5)/Kg for Tacometer
%2*pi/(1024*4) for Encoder

% potentiometer from HIL Read Analog Timebase 0 --> continous rise theta
% encoder from HIL Read Encoder 0 --> sawtooth
% tacometer rom HIL Read Analog Timebase 1 --> omega/speed

% Signal Generator amplitude 1, Frequency 0.4
% bias of 1.5 --> u + 1.5

% HIL Write Analog












