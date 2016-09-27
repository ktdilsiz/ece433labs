function [tpeak, os, t_r, t_s, wn, zeta]=peaktime(middle, last);

wn = sqrt(last);

zeta = middle/(2*wn);

tpeak = pi/(wn*sqrt(1-zeta^2));

os = exp(-pi*zeta/sqrt(1-zeta^2));

t_r = 2.2/(zeta*wn);
t_s = 4.6/(zeta*wn);
