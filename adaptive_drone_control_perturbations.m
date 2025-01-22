clear all
close all
clc


%% Drone parameters
MASS = 0.027; % kg
GRAVITY = [0;0;9.81];
INERTIA = [16.6e-6, 0.83e-6, 0.72e-6;
        0.83e-6, 16.6e-6, 1.8e-6;
        0.72e-6, 1.8e-6, 29.3e-6]; %from bitcraze
BODY_FRAME_THRUST = [0;0;1];

%% Simulation parameters
SIM_TIME = 15; % seconds
DELTA_TIME = 0.001;
TIME_STEPS = SIM_TIME/DELTA_TIME;
i = 1;
t = 0;

MAX_TRANS_C = 9.5;
MAX_ROT_C = 10;

%% Initialize state variables
position = [0;0;0];
orientation = quaternion(1,0,0,0);
orientation = normalize(orientation);
velocity = [0;0;0];
velocity_error = velocity;
angular_velocity = [0;0;0];

%% Control Variables

%Translational control gains
trans_kp_o = [12;12;12];
trans_kd_o = [9;9;9];

% trans_kp_o = [7;7;7];
% trans_kd_o = [3.75;3.75;3.75];

trans_kp = trans_kp_o;
trans_kd = trans_kd_o;

trans_kp_dot = [0;0;0];
trans_kd_dot = [0;0;0];

%Rotational control gains
ang_kp_o = [150;150;150];
ang_kd_o = [50;50;50];

ang_kp_dot = [0;0;0];
ang_kd_dot = [0;0;0];

ang_kp = ang_kp_o;
ang_kd = ang_kd_o;

%Adaptive and restriction control gains and constants
%lambda 1 affects the proportional gain both related to the reference
% and the restriction
% lambda 2 affects the rate of change of said gain; the lower it is, the
% faster it can change, this is reflected as the trajectory gets near the
% restriction, as it rejects it more strongly. However it looses
% controlablity when it reaches a certain distance from the restriction.
% Said distance would be lower if this number was higher, but this would
% also imply 
% lambda 3 affects velocity and 4 affects its rate of change
% so on can be inferred for alph, however, restrictions are only related
% to position.
lambda = [8 0.75 4 0.5];
alpha = [3 0.05 1 0.5];

restriction_radius = 1.5;
lambda_max = restriction_radius^2;

%% Desired variables


desired_orientation = quaternion(1,0,0,0);
desired_position = [-0.7;-0.7;0];

% Error
orientation_error = orientation;
position_error = position - desired_position;



%% Auxiliary variables for plotting 
plot_position = zeros(3, TIME_STEPS);
plot_desired_position = zeros(3, TIME_STEPS);
plot_trans_gains = zeros(3, TIME_STEPS);
plot_attitude = zeros(4, TIME_STEPS);
plot_desired_attitude = zeros(4, TIME_STEPS);
plot_attitude_error = zeros(4, TIME_STEPS);
plot_angular_error = zeros(1, TIME_STEPS);
time = zeros(1, TIME_STEPS);

%% Simulation loop
while t < SIM_TIME


    if t < 2
        desired_position = [-0.7;-0.7;0];
    elseif t < 6
        desired_position = [1.7;0;0];
    elseif t < 9 
        desired_position = [0;1.8;0]; 
    else
        desired_position = [0;0;0];
    end

    % Perturbations

    position_pert = sin(t*5)*.05;
    % velocity_pert = cos(t*5)*.25;
    velocity_pert = 0;
    % desired_position = [t;t;t];
    position_error_prev  = position_error;
    position_error = position - desired_position + position_pert;
    velocity_error = (position_error - position_error_prev)/DELTA_TIME + velocity_pert;
    r = sqrt(position(1)^2 + position(2)^2 + position(3)^2); %position relative to the origin
    t = t + DELTA_TIME;

    

    % Estimate translational control gains
    for j = 1:3
       % trans_kp_dot(j) = (-lambda(1)/(lambda_max-norm(r)^2))*(position_error(j))*sign(position_error(j)) + lambda(2)*(trans_kp_o(j) - trans_kp(j));
       kp_dot = lambda(1)*(position_error(j))*sign(position_error(j)) + lambda(2)*(trans_kp_o(j) - trans_kp(j));
       trans_kd_dot(j) = lambda(3)*(velocity_error(j)) + lambda(4)*(trans_kd_o(j) - trans_kd(j));

       trans_kp(j) = trans_kp(j) + trans_kp_dot(j) * DELTA_TIME;
       trans_kd(j) = trans_kd(j) + trans_kd_dot(j) * DELTA_TIME;
    
    end
 
    
    % Translational Control
    trans_control = -MASS*(trans_kp.*position_error + trans_kd.*(velocity_error) + (-GRAVITY)); 
    norm_trans_control = norm(trans_control);
    control_direction = [0;0;0];
    if norm_trans_control ~= 0
        control_direction = trans_control/norm_trans_control; %Fu direction
    end
    
    [~,frx,fry,frz] = parts(orientation*quaternion(0,0,0,1)*(orientation')) ; %Fth
    control_thrust = trans_control(3)/dot([0;0;1],[frx;fry;frz]); %Fu

    % Orientation Control
    desired_orientation = exp(0.5*log(quaternion([dot([0;0;1],control_direction);[cross([0;0;1],control_direction)]]')));
    desired_orientation = normalize(desired_orientation);
    orientation_error_prev =  orientation_error;
    orientation_error = orientation*(desired_orientation');
    orientation_error_vector = rotvec(orientation_error)'; %Euler angle representation
    % angular_velocity_error = rotvec(orientation_error*orientation_error_prev')'/DELTA_TIME;
    [~,oex,oey,oez] = parts(2*orientation_error'*((orientation_error-orientation_error_prev)./DELTA_TIME));
    angular_velocity_error = [oex;oey;oez];
    
    if norm(rotvec(orientation_error)) > pi || norm(rotvec(orientation_error))< -pi
        disp('Inverting reference')
        desired_orientation = -desired_orientation;
        orientation_error = (desired_orientation)*(orientation');
    end 

    
    % Estimate rotational control gains
    for k = 1:3
        ang_kp_dot(k) = alpha(1)*(orientation_error_vector(k)) + alpha(2)*(ang_kp_o(k) - ang_kp(k));
        ang_kd_dot(k) = alpha(3)*(angular_velocity_error(k)) + alpha(4)*(ang_kd_o(k) - ang_kd(k));

        ang_kp(k) = ang_kp(k) + ang_kp_dot(k) * DELTA_TIME;
        ang_kd(k) = ang_kd(k) + ang_kd_dot(k) * DELTA_TIME;
    end

    orientation_control = (-ang_kp.*orientation_error_vector)-(ang_kd.*angular_velocity_error);
    torque = INERTIA*(orientation_control + cross(angular_velocity,INERTIA*angular_velocity));
        
    % Update orientation and position
    [~,ax,ay,az] = parts(orientation*quaternion(0,0,0,norm(control_thrust)/MASS)*(orientation'));
    az = az + (-GRAVITY(3));
    velocity =  velocity + ([ax;ay;az])* DELTA_TIME;
    position = position + velocity * DELTA_TIME; 
    orientation_dot = 0.5*quaternion([0,angular_velocity'])*orientation;
    orientation = orientation + orientation_dot*DELTA_TIME;
    orientation = normalize(orientation);
    dot_w = (INERTIA)\(torque- cross(angular_velocity,INERTIA*angular_velocity));
    angular_velocity = angular_velocity + dot_w * DELTA_TIME;
    
    % Update plotting matrix
    plot_position(:, i) = position;
    plot_desired_position(:, i) = desired_position;
    plot_trans_gains(:,i) = trans_kp;
    [plot_attitude(1,i),plot_attitude(2,i),plot_attitude(3,i),plot_attitude(4,i)] = parts(orientation);
    [plot_desired_attitude(1,i),plot_desired_attitude(2,i),plot_desired_attitude(3,i),plot_desired_attitude(4,i)] = parts(desired_orientation);
    [plot_attitude_error(1,i),plot_attitude_error(2,i),plot_attitude_error(3,i),plot_attitude_error(4,i)] = parts(orientation_error);
    plot_angular_error(i) = norm(rotvec(orientation_error));
    

    %Reset adaptive control when a great change in trajectory occurs
    for l = 1:3
        if abs(position_error(l)) > (abs(position_error_prev(l))+0.2)
            trans_kp = trans_kp_o;
            trans_kd = trans_kd_o;

            trans_kp_dot = [0;0;0];
            trans_kd_dot = [0;0;0];
        end
    end

    time(i) = t;
    i = i + 1;

end


%% Plotting
figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[0,0,1920,1080])
plot3(plot_position(1, :), plot_position(2, :), plot_position(3, :),'LineWidth',2.5);
hold on
plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'LineStyle', 'none' , 'Marker', 'square', MarkerSize=10, MarkerFaceColor='r');
[sx,sy,sz] = sphere(60);
s = surf(sx*restriction_radius,sy*restriction_radius,sz*restriction_radius);
s.FaceAlpha = 0.5;
s.EdgeColor = 'none';
s.FaceColor = 'interp';
xlabel('Coord. X [m]','FontSize',24);
ylabel('Coord. Y [m]','FontSize',24);
zlabel('Coord. Z [m]','FontSize',24);
legend('Position ', 'Reference ', 'FontSize', 24, Box="off")
axis([-3 3 -3 3 -3 3])
view([-30,60])
set(gca,"LineWidth", 2)
grid off;
print('../Plots/adaptive_control_pert/3D_Trajectory', '-depsc2')

figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[0,0,1920,1080])
set(gcf,"Renderer","painters")
plot(time, plot_attitude(1, :), 'k','LineWidth',2.5);
hold on
plot(time, plot_attitude(2, :), 'r','LineWidth',2.5);
plot(time, plot_attitude(3, :), 'g','LineWidth',2.5);
plot(time, plot_attitude(4, :), 'b','LineWidth',2.5);
plot(time, plot_desired_attitude(1, :), 'k-.','LineWidth',2.5);
plot(time, plot_desired_attitude(2, :), 'r-.','LineWidth',2.5);
plot(time, plot_desired_attitude(3, :), 'g-.','LineWidth',2.5);
plot(time, plot_desired_attitude(4, :), 'b-.','LineWidth',2.5);
legend('q_0','q_1','q_2','q_3','q_{r0}','q_{r1}','q_{r2}','q_{r3}','FontSize',22, Box="off");
xlabel('Time [s]', 'FontSize',24);
ylabel('Attitude Quaternion', 'FontSize',24);
box("off")
grid off;
print('../Plots/adaptive_control_pert/Attitude', '-depsc2')


figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[50,50,1920,1080])
plot(time,plot_trans_gains(1, :), 'k','LineWidth',2.5);
hold on
plot(time,plot_trans_gains(2, :), 'b','LineWidth',2.5);
plot(time,plot_trans_gains(3, :), 'r','LineWidth',2.5);
ylim([149.5 150.5])
legend('kp_0','kp_1','kp_2', 'FontSize',24, Box="off")
xlabel('Time [s]','FontSize',24);
ylabel('Trans kp [m]','FontSize',24);
grid off;
box("off")
print('../Plots/adaptive_control/tkp', '-depsc2')

figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[50,50,1920,1080])
set(gcf,"Renderer","painters")
plot(time,plot_position(1, :), 'k','LineWidth',2.5);
hold on
plot(time,plot_position(2, :), 'b','LineWidth',2.5);
plot(time,plot_position(3, :), 'r','LineWidth',2.5);
plot(time,plot_desired_position(1, :), 'k-.','LineWidth',2.5);
plot(time,plot_desired_position(2, :), 'b-.','LineWidth',2.5);
plot(time,plot_desired_position(3, :), 'r-.','LineWidth',2.5);
ylim([-5 5])
legend('p_0','p_1','p_2', 'FontSize',24, Box="off")
xlabel('Time [s]','FontSize',24);
ylabel('Position [m]','FontSize',24);
grid off;
box("off")
print('../Plots/adaptive_control_pert/Position', '-depsc2')

