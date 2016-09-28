
%G(s) = b1sm + b2sm-1 + ...+ bms + bm+1
%       sn + a1sn-1 + a2sn-2 + ...+ an-1s + an
% 
% num = [b1, b2, �, bm, bm+1];
% den = [1 a1, a2, �, an-1, an];
% G = tf(num, den);

clear all;

%% Question 1-1
%Question 1 with roots function

num = [1, 0, 2];
den = [1, 2, -1, 1];
Ga = tf(num, den);
Gapoles_roots = roots(den);
Gazeros_roots = roots(num);

num = [1, 0, 0, 1];
den = [1, 0, 2, 0, 1];
Gb = tf(num, den);
Gbpoles_roots = roots(den);
Gbzeros_roots = roots(num);

num = [4, 8, 10];
den = [2, 8, 18, 20];
Gc = tf(num, den);
Gcpoles_roots = roots(den);
Gczeros_roots = roots(num);

%end of cell 1-1

%% Question 1-2
%%Question 2 repeating question 1 with pole and tzero functions

Gapoles_pole = pole(Ga);
Gazeros_tzero = tzero(Ga);

Gbpoles_pole = pole(Gb);
Gbzeros_tzero = tzero(Gb);

Gcpoles_pole = pole(Gc);
Gczeros_tzero = tzero(Gc);

%end of cell 1-2

%% Question 1-3

%Stable
figure(1);
pzmap(Ga)
grid on

%Marginary Stable
figure(2);
pzmap(Gb)
grid on

%Unstable
figure(3);
pzmap(Gc)
grid on

%end of cell 1-3

%% Question 1-4

Gcombine = [Ga; Gb; Gc];

figure(4);
iopzmap(Gcombine)
grid on

%end of question 1-4

%% Question 1-5

numbefore = [1, 5];

num_conv = conv(6, numbefore);

den1 = [1, 3, 1];
den2 = [1, 6];
den3 = [1, 6, 5, 3];

den_conv = conv(conv(den1, den1), conv(den2, den3));

num_mul = 6 * numbefore;
den_mul = (tf(1, den1) * tf(1, den1))*(tf(1, den2) * tf(1, den3));

%conv was easier than combining tf and *

%end of question 1-5

%% Question 2

% num = conv([1,1], [1,2]);
polya_num = poly([-1; -2]);
polya_den = poly([-3; -1-3*1i ; -1+3*1i]); 

polyb_num = 3*poly([-3; -1]);
polyb_den = poly([-2; -2+1i ; -2-1i]); 

% den = conv(conv([1,3], [1,1 + 3*1i]), [1, 1 - 3*1i]);
% Ga = tf(num, den);
% 
% poly_num = poly(num);
% poly_den = poly(den);

%end of question 2

%% Question 3 

zpk_Ga = zpk([-1; -2], [-3; -1-3*1i ; -1+3*1i], 1);
zpk_Gb = zpk([-3; -1], [-2; -2+1i ; -2-1i], 3);

%zpk gives a simplified polynomial whereas poly gives the coefficients of
%the convoluted function

%end of Question 3

%% Question 4

num = conv([1,1], [1,2]);
den = conv(conv([1,3], [1,1 + 3*1i]), [1, 1 - 3*1i]);

[z4_Ga, p4_Ga, k4_Ga] = tf2zp(num, den);

num = 3*poly([-3; -1]);
den = poly([-2; -2+1i ; -2-1i]); 

[z4_Gb, p4_Gb, k4_Gb] = tf2zp(num, den);

% tf2zp command gives the zeros and poles in matrix forms whereas zpk gives
% us a simplified polynomial

%end of Question 4

%% Question 5

num = [2, 4, -16];
den = [1, 6, 11, 6];

zpk_question5 = zpk(roots(num),roots(den),1);

%end of Question 5

%% Question 6

[z6, p6, k6] = tf2zp(num, den);

%end of Question 6

%% Question 7

num = [-1, -4];
den = [1, 3, 2];

[r_a, p_a, k_a] = residue(num,den);

num = [1, 2, 5, 3, 6];
den = [1, 12, 39, 28];

[r_b, p_b, k_b] = residue(num,den);

num = [2, -1];
den = [1, 2, 1];

[r_c, p_c, k_c] = residue(num,den);

%r is the numerators of individual partial franction parts
%p is the denumerators
%k is the leftover polynomial

%end of Question 7

%% Question 8

num = [8];
den = [1,1,2];

step(num, den)

%end of question 8

%% Question 9

s = tf('s');
diffq9 = 8/(s*s + s + 2);

ltiview(diffq9)

%end of question 9

%% Question 10
num = [1];
den = [1,2,5];

[A,B,C,D] = tf2ss(num,den);
t = 0:0.01:15;
lsim( A,B,C,D, sin(5*t), t, [0 2])

%end of question 10


