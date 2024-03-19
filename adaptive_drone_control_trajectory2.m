clear all
close all
clc


% Drone parameters
MASS = 0.5; % kg
GRAVITY = [0;0;9.81];
INERTIA_X = 5e-3;
INERTIA_Y = 5e-3;
INERTIA_Z = 1e-2;
INERTIA = diag([INERTIA_X, INERTIA_X, INERTIA_Z]);
BODY_FRAME_THRUST = [0;0;1];

% Simulation parameters
SIM_TIME = 20; % seconds
DELTA_TIME = 0.01;
TIME_STEPS = SIM_TIME / DELTA_TIME;
i = 1;
t = 0;

MAX_TRANS_C = 9.5;
MAX_ROT_C = 10;

% Randomly initialize position
position = rand(3,1)*20-10;
% position = [10;-5;6];

% Non-Randomly initialize orientation
orientation = quaternion(1,0,0,0);
orientation = normalize(orientation);
velocity = [0;0;0];
velocity_error = velocity;
angular_velocity = [0;0;0];

% Control Variables
kp_fixed = 4;
kd_fixed = 2;

kp = kp_fixed;
kd = kd_fixed;

ang_kp_fixed = 20;
ang_kd_fixed = 6;

ang_kp = ang_kp_fixed;
ang_kd = ang_kd_fixed;

lambda = [0.12 0. 15 0.002];
alpha = [25 0.005 20 1.5];

% Desired variables

desired_orientation = randrot;

% Init error
desired_position = [cos(0);sin(0);(sin(0)+1)*2];
orientation_error = orientation;
position_error = position - desired_position;

%Auxiliary variables for plotting 
plot_position = zeros(3, TIME_STEPS);
plot_desired_position = zeros(3, TIME_STEPS);
plot_attitude = zeros(4, TIME_STEPS);
plot_desired_attitude = zeros(4, TIME_STEPS);
plot_attitude_error = zeros(4, TIME_STEPS);
plot_angular_error = zeros(1, TIME_STEPS);
time = zeros(1, TIME_STEPS);

% Simulation loop
while t < SIM_TIME
    desired_position = [cos(t);sin(t);(sin(0.05*t)+1)*2];
    position_error_prev  = position_error;
    position_error = position - desired_position;
    t = t + DELTA_TIME;

    % Estimate translational control gains

    kp_dot = norm(-lambda(1)*(position_error) + lambda(2)*(kp_fixed - kp));
    kd_dot = norm(-lambda(3)*(velocity_error) + lambda(4)*(kd_fixed - kd));

    kp = kp + kp_dot * DELTA_TIME;
    kd = kd + kd_dot * DELTA_TIME;

    if norm(position_error) < 0.0005
        kp = kp_fixed;
        kd = kd_fixed;
    end
    
    % Translational Control
    velocity_error = (position_error - position_error_prev)/DELTA_TIME;
    trans_control = -MASS*(kp*position_error + kd*(velocity_error) - GRAVITY); 

    control_thrust = trans_control/norm(trans_control);

    % Orientation Control
    desired_orientation = exp(0.5*log(quaternion([dot([0;0;1],control_thrust);[cross([0;0;1],control_thrust)]]')));
    desired_orientation = normalize(desired_orientation);
    orientation_error_prev =  orientation_error;
    orientation_error = orientation*(desired_orientation');
    angular_velocity_error = rotvec(orientation_error*orientation_error_prev')'/DELTA_TIME;
    velocity_error = position_error - position_error_prev;
    if norm(rotvec(orientation_error)) > pi || norm(rotvec(orientation_error))< -pi
        disp('Invirtiendo referencia')
        desired_orientation = -desired_orientation;
        orientation_error = (desired_orientation')*orientation;
    end 

    % Estimate rotational control gains}
    ang_kp_dot = norm(-alpha(1)*(position_error) + alpha(2)*(kp_fixed - kp));
    ang_kd_dot = norm(-alpha(3)*(velocity_error) + alpha(4)*(kd_fixed - kd));

    ang_kp = ang_kp + ang_kp_dot * DELTA_TIME;
    ang_kd = ang_kd + ang_kd_dot * DELTA_TIME;

    % if norm(orientation_error) < 0.0005
    %     ang_kp = ang_kp_fixed;
    %     ang_kd = ang_kd_fixed;
    % end

    orientation_control = (-ang_kp*(rotvec(orientation_error)')-ang_kd*angular_velocity_error);

    torque = INERTIA*orientation_control + cross(angular_velocity,INERTIA*angular_velocity);
        

    % Update orientation and position
    [~,ax,ay,az] = parts(orientation*quaternion(0,0,0,norm(trans_control)/MASS)*(orientation'));
    velocity =  velocity + ( -1*GRAVITY +  [ax;ay;az])* DELTA_TIME;
    position = position + velocity * DELTA_TIME; 
    orientation_dot = 0.5*quaternion([0,angular_velocity'])*orientation;
    orientation = orientation + orientation_dot*DELTA_TIME;
    orientation = normalize(orientation);
    dot_w = (INERTIA)\(torque- cross(angular_velocity,INERTIA*angular_velocity));
    angular_velocity = angular_velocity + dot_w * DELTA_TIME;
    
    % Update plotting matrix
    plot_position(:, i) = position;
    plot_desired_position(:, i) = desired_position;
    [plot_attitude(1,i),plot_attitude(2,i),plot_attitude(3,i),plot_attitude(4,i)] = parts(orientation);
    [plot_desired_attitude(1,i),plot_desired_attitude(2,i),plot_desired_attitude(3,i),plot_desired_attitude(4,i)] = parts(desired_orientation);
    [plot_attitude_error(1,i),plot_attitude_error(2,i),plot_attitude_error(3,i),plot_attitude_error(4,i)] = parts(orientation_error);
    plot_angular_error(i) = norm(rotvec(orientation_error));
    time(i) = t;
    i = i + 1;

end


%Plotting
figure;
plot3(plot_position(1, :), plot_position(2, :), plot_position(3, :));
title('Trajectory');
xlabel('X');
ylabel('Y');
zlabel('Z');
grid on;

figure;
plot(time, plot_attitude(1, :), 'k');
hold on
plot(time, plot_attitude(2, :), 'r');
plot(time, plot_attitude(3, :), 'g');
plot(time, plot_attitude(4, :), 'b');
plot(time, plot_desired_attitude(1, :), 'k-.');
plot(time, plot_desired_attitude(2, :), 'r-.');
plot(time, plot_desired_attitude(3, :), 'g-.');
plot(time, plot_desired_attitude(4, :), 'b-.');

figure;
plot(time,plot_position(1, :), 'k');
hold on
plot(time,plot_position(2, :), 'b');
plot(time,plot_position(3, :), 'r');
plot(time,plot_desired_position(1, :), 'k-.');
plot(time,plot_desired_position(2, :), 'b-.');
plot(time,plot_desired_position(3, :), 'r-.');
title('posición del dron (metros)');
xlabel('Tiempo');
ylabel('Valor');
grid on;
