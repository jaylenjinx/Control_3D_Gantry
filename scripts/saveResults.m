%% Sys_id
% Saves the current workspace values to a sys_id.mat material
save("sys_id.mat", "x_pos", "y_pos", "z_pos", "x_angle", "y_angle", "x_control", "y_control", "time", "logsout");

% Z Axis at 37cm
% Z axis height from top of angle measurer thingo to top of weight

% Create a new figure
figure(1); 

% Plot the X Control Signal as the first bit
subplot(321)
plot(x_control);
grid on;
ylabel('X Control')

% Plot the Y Control Signal as the second bit
subplot(322)
plot(y_control);
grid on;
ylabel('Y Control')

% Plot the X Position as the third bit
subplot(323)
plot(x_pos);
grid on;
ylabel('X Position')

% Plot the Y Position as the fourth bit
subplot(324)
plot(y_pos);
grid on;
ylabel('Y Position')

% Plot the X Angle as the fifth bit
subplot(325)
plot(x_angle);
grid on;
ylabel('X Angle [rad]')

% Plot the Y Angle as the sixth and final bit
subplot(326)
plot(y_angle);
grid on;
ylabel('Y Angle [rad]')

% Plot the Z Position but its unneccessary
figure(2);
plot(z_pos);
grid on;
ylabel('Z Position')