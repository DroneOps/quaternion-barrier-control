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
SIM_TIME = 40 ; % seconds
DELTA_TIME = 0.001;
TIME_STEPS = SIM_TIME/DELTA_TIME;
i = 1;
t = 0;

MAX_TRANS_C = 9.5;
MAX_ROT_C = 10.0;

%% Initialize state variables
stop = 3;
slide = 0.2;
% position = [slide+cos(3+t);sin(3+t);sin(0.5*t)*.5]/3;
position = [0;0;0];
orientation = quaternion(1,0,0,0);
orientation = normalize(orientation);
velocity = [0;0;0];
velocity_error = velocity;
angular_velocity = [0;0;0];

%% Control Variables

%Translational control gains
trans_kp_o = [32;32;32];
trans_kd_o = [6;6;6];

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
% lambda = [1.6 5 0.5 1];
% alpha = [1.5 0.05 2 0.02];
% lambda = [6 0.5 1.5 0.1];
% alpha = [3 0.1 4 0.1];
% lambda = [100 17 0 0];
% alpha = [0 0 0 0];
lambda = [30 50 0.5 15];
alpha = [6 0.05 8 0.05];
restriction_radius = 0.5;
lambda_max = restriction_radius^2;

%% Desired variables


desired_orientation = quaternion(1,0,0,0);
desired_position = position;

% Error
orientation_error = orientation;
position_error = position - desired_position;


%% Auxiliary variables for plotting 
plot_position = zeros(3, TIME_STEPS);
plot_desired_position = zeros(3, TIME_STEPS);
plot_position_norm = zeros(1, TIME_STEPS);
plot_constraint = zeros(1, TIME_STEPS);
plot_attitude = zeros(4, TIME_STEPS);
plot_desired_attitude = zeros(4, TIME_STEPS);
plot_attitude_error = zeros(4, TIME_STEPS);
plot_angular_error = zeros(1, TIME_STEPS);
plot_trans_gains = zeros(3, TIME_STEPS);
plot_trans_kd = zeros(3, TIME_STEPS);
plot_torques = zeros(3, TIME_STEPS);
plot_thrust = zeros(1, TIME_STEPS);
time = zeros(1, TIME_STEPS);

discretization_v = 0.002;
step = 0;
size = 1;
%% Simulation loop
while t < SIM_TIME
    

    step = step+0.0005;
    % step = step+0.001;
    if t < 20
        size = size+0.00002;
    else
        size = size-0.00002;
    end
    % size = size+0.00004;
    


    % if t < 2
    %     desired_position = [-0.3;0.3;0];
    % elseif t < 6
    %     desired_position = [-0.3;-0.3;0];
    % elseif t < 9
        % desired_position = [0;-0.6;0]; 
    % else
    %     desired_position = [0;0;0];
    % end
   desired_position = [slide+cos(3+step)*size;sin(3+step)*size;sin(0.5*step)*size*.5]/3;
   % if step > stop
   %     desired_position = [slide+cos(3+stop);sin(3+stop);sin(0.5*stop)*.5]/3;
   % end
   % step = t*2;
   % bezier = (1-t);

    % desired_position = [t;t;t];
    position_error_prev  = position_error;
    position_error = position - desired_position;
    velocity_error = (position_error - position_error_prev)/DELTA_TIME;

    r = sqrt(position(1)^2 + position(2)^2 + position(3)^2); %position relative to the origin
    rd = sqrt(desired_position(1)^2 + desired_position(2)^2 + desired_position(3)^2);
    reduction_v = 0.9999;
    if r >= restriction_radius*reduction_v
        theta = atan2(desired_position(2),desired_position(1));
        beta = acos(desired_position(3)/rd);
        position(1) = restriction_radius*reduction_v*sin(beta)*cos(theta);
        position(2) = restriction_radius*reduction_v*sin(beta)*sin(theta);
        position(3) = restriction_radius*reduction_v*cos(beta);
        r = sqrt(position(1)^2 + position(2)^2 + position(3)^2);
        if restriction_radius - rd < -0.09
           position_error(1) = position(1) - (restriction_radius + 0.09)*sin(beta)*cos(theta);
           position_error(2) = position(2) - (restriction_radius + 0.09)*sin(beta)*sin(theta);
           position_error(3) = position(3) - (restriction_radius + 0.09)*cos(beta);
        end
    end
    t = t + DELTA_TIME;

    approx_v = 1;
    % Estimate translational control gains
    for j = 1:3
       

       trans_kp_dot(j) = ( -lambda(1)/(restriction_radius-r))*abs(position_error(j)) + lambda(2)*(trans_kp_o(j) - trans_kp(j));
       % trans_kp_dot(j) = lambda(1)*(position_error(j))*sign(position_error(j)) + lambda(2)*(trans_kp_o(j) - trans_kp(j));
       trans_kd_dot(j) = lambda(3)*(velocity_error(j)) + lambda(4)*(trans_kd_o(j) - trans_kd(j));
       trans_kp(j) = trans_kp(j)*approx_v + trans_kp_dot(j) * DELTA_TIME;
       trans_kd(j) = trans_kd(j)*approx_v + trans_kd_dot(j) * DELTA_TIME;


        % if trans_kp(j) > trans_kp_o(j)
        %     trans_kp(j) = trans_kp_o(j);
        % end

        % if trans_kd(j) < 0
        %     trans_kd(j) = 0;
        % end
    end
 
    
    % Translational Control
    trans_control = -MASS*(trans_kp.*position_error + trans_kd.*(velocity_error) + (-GRAVITY)); 

    % if norm(trans_control)~=0
        % trans_control = -MASS*(trans_kp.*position_error + trans_kd.*(velocity_error) + (-GRAVITY)); 
    %     trans_control = MAX_TRANS_C*tanh(norm(trans_control)/MAX_TRANS_C)*trans_control/norm(trans_control);
    % end

    norm_trans_control = norm(trans_control);
    control_direction = [0;0;0];
    if norm_trans_control ~= 0
        control_direction = trans_control/norm_trans_control; %Fu
    end
    
    [~,frx,fry,frz] = parts(orientation*quaternion(0,0,0,1)*(orientation')); %Fth
    control_thrust = trans_control(3)/dot([0;0;1],[frx;fry;frz]);

    % Orientation Control
    desired_orientation = exp(0.5*log(quaternion([dot([0;0;1],control_direction);[cross([0;0;1],control_direction)]]')));
    desired_orientation = normalize(desired_orientation);
    orientation_error_prev =  orientation_error;
    orientation_error = orientation*(desired_orientation');
    orientation_error_vector = rotvec(orientation_error)'; %Euler angle representation
    angular_velocity_error = rotvec(orientation_error*orientation_error_prev')'/DELTA_TIME;
    
    if norm(rotvec(orientation_error)) > pi || norm(rotvec(orientation_error))< -pi
        disp('Inverting reference')
        desired_orientation = -desired_orientation;
        orientation_error = (desired_orientation)*(orientation');
    end 

    % Estimate rotational control gains
    for k = 1:3
        ang_kp_dot(k) = alpha(1)*(orientation_error_vector(k)) + alpha(2)*(ang_kp_o(k) - ang_kp(k));
        ang_kd_dot(k) = alpha(3)*(angular_velocity_error(k)) + alpha(4)*(ang_kd_o(k) - ang_kd(k));

        ang_kp(k) = ang_kp(k)*approx_v + ang_kp_dot(k) * DELTA_TIME;
        ang_kd(k) = ang_kd(k)*approx_v + ang_kd_dot(k) * DELTA_TIME;
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
    plot_position_norm(:, i) = r;
    plot_constraint(:,i) = restriction_radius;
    plot_desired_position(:, i) = desired_position;
    [plot_attitude(1,i),plot_attitude(2,i),plot_attitude(3,i),plot_attitude(4,i)] = parts(orientation);
    [plot_desired_attitude(1,i),plot_desired_attitude(2,i),plot_desired_attitude(3,i),plot_desired_attitude(4,i)] = parts(desired_orientation);
    [plot_attitude_error(1,i),plot_attitude_error(2,i),plot_attitude_error(3,i),plot_attitude_error(4,i)] = parts(orientation_error);
    plot_angular_error(i) = norm(rotvec(orientation_error));
    plot_trans_gains(:,i) = trans_kp;
    plot_trans_kd(:,i) = trans_kd;
    plot_torques(:, i) = torque;
    plot_thrust(:, i) = control_thrust;
    

    % Reset adaptive control when a great change in trajectory occurs
    % 
    % if i~=1
    %     for l = 1:3
    %         if (plot_desired_position(l,i) ~= plot_desired_position(l,i-1))
    %             trans_kp(l) = trans_kp_o(l);
    %             trans_kd(l) = trans_kd_o(l);
    % 
    %             trans_kp_dot(l) = 0;
    %             trans_kd_dot(l) = 0;
    % 
    %         end
    %     end
    % end

    % if ()

    time(i) = t;
    i = i + 1;

end


%% Plotting
figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[0,0,1920,1080])
plot3(plot_position(1, :), plot_position(2, :), plot_position(3, :),'LineWidth',2.5);
hold on
% plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'LineStyle', 'none' , 'Marker', 'square', MarkerSize=10, MarkerFaceColor='r');
plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'r-.');
[sx,sy,sz] = sphere(60);
s = surf(sx*restriction_radius,sy*restriction_radius,sz*restriction_radius);
s.FaceAlpha = 0.5;
s.EdgeColor = 'none';
s.FaceColor = 'interp';
xlabel('Coord. X [m]','FontSize',24);
ylabel('Coord. Y [m]','FontSize',24);
zlabel('Coord. Z [m]','FontSize',24);
legend('Position ', 'Reference ', 'FontSize', 24, Box="off", Position=[0.65,0.7,0.1,0.1]);
axis('equal',[-1 1 -1 1 -1 1])
view([35,60])
set(gca,"LineWidth", 2)
grid off;
print('../Plots/restricted_control/3D_Trajectory', '-depsc2')

figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[80,220,1850,525])
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
legend('q_0','q_1','q_2','q_3','q_{r0}','q_{r1}','q_{r2}','q_{r3}','FontSize',22, Box="on", Color=[1,1,1], EdgeColor=[1,1,1]);
set(gca,"FontSize", 15);
xlabel('Time [s]', 'FontSize',24);
ylabel('Attitude Quaternion', 'FontSize',24);
box("off")
grid off;
print('../Plots/restricted_control/Attitude', '-depsc2')

figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[80,220,1850,525])
set(gcf,"Renderer","painters")
plot(time,plot_position(1, :), 'r','LineWidth',2.5);
hold on
plot(time,plot_position(2, :), 'g','LineWidth',2.5);
plot(time,plot_position(3, :), 'b','LineWidth',2.5);
plot(time,plot_desired_position(1, :), 'r-.','LineWidth',2.5);
plot(time,plot_desired_position(2, :), 'g-.','LineWidth',2.5);
plot(time,plot_desired_position(3, :), 'b-.','LineWidth',2.5);
ylim([-2 2])
legend('p_x','p_y','p_z', 'p_x_r','p_y_r','p_z_r', 'FontSize',24, Box="on", Color=[1,1,1], EdgeColor=[1,1,1])
set(gca,"FontSize", 15);
xlabel('Time [s]','FontSize',24);
ylabel('Position [m]','FontSize',24);
% axes('FontSize',24);
grid off;
box("off")
print('../Plots/restricted_control/Position', '-depsc2')

figure;
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[80,220,1850,525])
set(gcf,"Renderer","painters")
plot(time,plot_position_norm(1, :), 'k','LineWidth',2.5);
hold on
plot(time,plot_constraint(1, :), 'y','LineWidth',2.5);
% plot(time,plot_constraint(2, :), 'y','LineWidth',2.5);
ylim([-0.5 2])
legend('position norm','sphere constraint', 'FontSize',24, Box="on", Color=[1,1,1], EdgeColor=[1,1,1])
set(gca,"FontSize", 15);
xlabel('Time [s]','FontSize',24);
ylabel('Position [m]','FontSize',24);
grid off;
box("off")
print('../Plots/restricted_control/Constraint', '-depsc2')

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
print('../Plots/restricted_control/tkp', '-depsc2')

figure
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[50,50,1920,1080])
plot(time,plot_trans_kd(1, :), 'k','LineWidth',2.5);
hold on
plot(time,plot_trans_kd(2, :), 'b','LineWidth',2.5);
plot(time,plot_trans_kd(3, :), 'r','LineWidth',2.5);
ylim([-20 20])
legend('kd_0','kd_1','kd_2', 'FontSize',24, Box="off")
xlabel('Time [s]','FontSize',24);
ylabel('Trans kd [m]','FontSize',24);
grid off;
box("off")
print('../Plots/restricted_control/tkd', '-depsc2')

figure
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[50,50,1920,1080])
plot(time,plot_torques(1, :), 'k','LineWidth',2.5);
hold on
plot(time,plot_torques(2, :), 'b','LineWidth',2.5);
plot(time,plot_torques(3, :), 'r','LineWidth',2.5);
ylim([-1 1])
legend('tau_0','tau_1','tau_2', 'FontSize',24, Box="off")
xlabel('Time [s]','FontSize',24);
ylabel('Torques [N/m]','FontSize',24);
grid off;
box("off")
print('../Plots/restricted_control/torques', '-depsc2')

figure
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[50,50,1920,1080])
plot(time,plot_thrust(1, :), 'k','LineWidth',2.5);
hold on
ylim([-0 1])
legend('thrust', 'FontSize',24, Box="off")
xlabel('Time [s]','FontSize',24);
ylabel('Thrust [N]','FontSize',24);
grid off;
box("off")
print('../Plots/restricted_control/thrust', '-depsc2')