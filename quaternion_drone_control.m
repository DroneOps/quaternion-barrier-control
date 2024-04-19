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
% position = rand(3,1)*20-10;
position = 0;

% Randomly intialize orientation
theta_x = (rand - 0.5) * pi/2;  % Ángulo alrededor del eje x
theta_y = (rand - 0.5) * pi/2;  % Ángulo alrededor del eje y
theta_z = (rand - 0.5) * pi/2;  % Ángulo alrededor del eje z
orientation = exp(0.5*quaternion(0,theta_x,theta_y,theta_z));
% orientation = quaternion(1,0,0,0);s
orientation = normalize(orientation);
velocity = [0;0;0];
angular_velocity = [0;0;0];

% Control Variables
kp = 4;
ki= 0;
kd1 = 1;
kd2 = 2;
angular_kp = 20;
angular_ki = 0;
angular_kd1 = 2;
angular_kd2 = 6;
k_gravity = -0.5525;

% Desired variables
desired_position = [0.4+cos(t);sin(t);sin(0.5*t)/2];
% desired_orientation = randrot;

% Init error
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
    desired_position = [0.4+cos(t);sin(t);sin(0.5*t)/2];
    t = t + DELTA_TIME;
    % Translational Control
    trans_control = -kp*(position - desired_position) - kd1*velocity;
    % Bound control using a hyperbolic tangent
    if norm(trans_control)~=0
        trans_control = MAX_TRANS_C*tanh(norm(trans_control)/MAX_TRANS_C)*trans_control/norm(trans_control) - kd2*velocity;
    end
    trans_control = trans_control + MASS*GRAVITY;
    
    norm_thrust = norm(trans_control);
    control_thrust = [0;0;0];
    if norm_thrust ~= 0
        control_thrust = trans_control/norm_thrust; %Fu
    end


    % Orientation Control
    desired_orientation = exp(0.5*log(quaternion([dot([0;0;1],control_thrust);[cross([0;0;1],control_thrust)]]')));
    desired_orientation = normalize(desired_orientation);
    orientation_error_prev =  orientation_error;
    orientation_error = orientation*(desired_orientation');
    angular_velocity_error = rotvec(orientation_error*orientation_error_prev')'/DELTA_TIME;
    if norm(rotvec(orientation_error)) > pi || norm(rotvec(orientation_error))< -pi
        disp('Invirtiendo referencia')
        desired_orientation = -desired_orientation;
        orientation_error = (desired_orientation')*orientation;
    end 

    orientation_control = -angular_kp*rotvec(orientation_error)' - angular_kd1*angular_velocity_error;
    if norm(orientation_control) ~= 0 
        orientation_control = MAX_ROT_C*tanh(norm(orientation_control)/MAX_ROT_C)*orientation_control/norm(orientation_control) - angular_kd2*angular_velocity_error;
    end
    torque = INERTIA * orientation_control;
        

    % Update orientation and position
    [~,ax,ay,az] = parts(orientation*quaternion(0,0,0,norm_thrust/MASS)*(orientation'));
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
hold on
plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'r-.')
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
