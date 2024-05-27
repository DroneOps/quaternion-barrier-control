theta_x = (rand - 0.5) * pi/2;  % Ángulo alrededor del eje x
theta_y = (rand - 0.5) * pi/2;  % Ángulo alrededor del eje y
theta_z = (rand - 0.5) * pi/2;  % Ángulo alrededor del eje z
orientation = 0.5*quaternion(0,theta_x,theta_y,theta_z);
expq = exp(orientation);
logq = log(orientation);
qrot = rotvec(orientation);


