%% X_Axis
%save("x_axis.mat", "x_pos", "y_pos", "z_pos", "x_angle", "y_angle", "x_control", "y_control", "logsout");

% Z Axis at 37cm

figure(1); 

subplot(322)
plot(x_control);
grid on;
ylabel('X Control')

subplot(321)
plot(y_control);
grid on;
ylabel('Y Control')

subplot(323)
plot(x_pos);
grid on;
ylabel('X Position')

subplot(324)
plot(y_pos);
grid on;
ylabel('Y Position')

%subplot(731)
%plot(z_pos);
%grid on;
%ylabel('Z Position')

subplot(325)
plot(x_angle);
grid on;
ylabel('X Angle [rad]')

subplot(326)
plot(y_angle);
grid on;
ylabel('Y Angle [rad]')
