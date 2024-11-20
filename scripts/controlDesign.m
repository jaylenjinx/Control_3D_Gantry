clc;
clear;

load("tf_est.mat");

fs = 200;

syms s;

s = tf("s");

Kf = 1;
L = 1;
m = 0.1;
M = 0.2;
g = 9.81;
bc = 1;
bp = 1;

G_ua_id = (-Kf*L*m*s) / ((bc + M*s + m*s)*(m*L^2*s^2 + g*m*L + bp*s))

rltool(G_ua_id);