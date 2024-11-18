%% Transfer Function Generation

clc;
clear;

% Loads the workspace values from the sys_id.mat material
load("sys_id.mat");

x_control_matrix = x_control.Data;
x_pos_matrix = squeeze(x_pos.Data);
x_angle_matrix = squeeze(x_angle.Data);

y_control_matrix = y_control.Data;
y_pos_matrix = squeeze(y_pos.Data);
y_angle_matrix = squeeze(y_angle.Data);

z_pos_matrix = squeeze(z_pos.Data);

fs = 200;

data = iddata(x_pos_matrix,x_control_matrix,fs);
np = 2;
nz = 0;
G_ux_id = tfest(data,np,nz)

data = iddata(x_angle_matrix,x_pos_matrix,fs);
np = 2;
nz = 2;
G_xa_id = tfest(data,np,nz)

data = iddata(x_angle_matrix,x_control_matrix,fs);
np = 2;
nz = 2;
G_ua_id = tfest(data,np,nz)

data = iddata(y_pos_matrix,y_control_matrix,fs);
np = 2;
nz = 0;
G_uy_id = tfest(data,np,nz)

data = iddata(y_angle_matrix,y_pos_matrix,fs);
np = 2;
nz = 2;
G_yu_id = tfest(data,np,nz)

data = iddata(y_angle_matrix,y_control_matrix,fs);
np = 2;
nz = 2;
G_ua2_id = tfest(data,np,nz)

figure(1);
tfestimate(x_control_matrix, x_pos_matrix, 1024, [], [], fs);
[T_xc_xp,f] = tfestimate(x_control_matrix, x_pos_matrix, 1024, [], [], fs);

figure(2);
tfestimate(x_pos_matrix, x_angle_matrix, 1024, [], [], fs);
[T_xp_xa,f] = tfestimate(x_pos_matrix, x_angle_matrix, 1024, [], [], fs);

figure(3);
tfestimate(y_control_matrix, y_pos_matrix, 1024, [], [], fs);
[T_yc_yp,f] = tfestimate(y_control_matrix, y_pos_matrix, 1024, [], [], fs);

figure(4);
tfestimate(y_pos_matrix, y_angle_matrix, 1024, [], [], fs);
[T_yp_ya,f] = tfestimate(y_pos_matrix, y_angle_matrix, 1024, [], [], fs);

% Saves the current workspace values to a tf_est.mat material
save("tf_est.mat", "x_control_matrix", "x_pos_matrix", "x_angle_matrix", "y_control_matrix", "y_pos_matrix", "y_angle_matrix", "z_pos_matrix", "T_xc_xp", "T_xp_xa", "T_yc_yp", "T_yp_ya", "f", "logsout");