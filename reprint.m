close all
clc
marker_space = 1 :400: 23000;


% Plotting
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[0,0,1920,1080])
% plot3(plot_position(1, :), plot_position(2, :), plot_position(3, :),'LineWidth',2.5);
% hold on
% % plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'LineStyle', 'none' , 'Marker', 'square', MarkerSize=10, MarkerFaceColor='r');
% plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'r-.', 'LineWidth',2.5);
% [sx,sy,sz] = sphere(60);
% s = surf(sx*restriction_radius,sy*restriction_radius,sz*restriction_radius);
% s.FaceAlpha = 0.5;
% s.EdgeColor = 'none';
% s.FaceColor = 'interp';
% xlabel('Coord. X [m]');
% ylabel('Coord. Y [m]');
% zlabel('Coord. Z [m]');
% legend('Position ', 'Reference ', 'FontSize', 24, Box="off", Position=[0.65,0.7,0.1,0.1]);
% set(gca, "XLim", [-0.8 0.8])
% set(gca, "YLim", [-0.8 0.8])
% set(gca, "ZLim", [-0.8 0.8])
% set(gca, "DataAspectRatio", [1 1 1])
% set(gca, "PlotBoxAspectRatio", [1 1 1])
% set(gca,"LineWidth", 2)
% set(gca,"FontSize", 12)
% set(gca,"LabelFontSizeMultiplier", 2)
% view([45,40])
% grid off;
% print('../Plots/restricted_control/3D_Trajectory', '-depsc2')
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time, plot_desired_attitude(1, :), 'k','LineWidth',3.5);
% hold on
% plot(time, plot_desired_attitude(2, :), 'r','LineWidth',3.5);
% plot(time, plot_desired_attitude(3, :), 'g','LineWidth',3.5);
% plot(time, plot_desired_attitude(4, :), 'b','LineWidth',3.5);
% plot(time, plot_attitude(1, :), 'k-.','LineWidth',.5, 'Marker','o','MarkerEdgeColor', [1,1,1],'MarkerFaceColor',[1,0.85,1],'MarkerIndices',marker_space);
% plot(time, plot_attitude(2, :), 'r-.','LineWidth',.5, 'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[1,0.5,0],'MarkerIndices',marker_space);
% plot(time, plot_attitude(3, :), 'g-.','LineWidth',.5, 'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[0,0.85,1],'MarkerIndices',marker_space);
% plot(time, plot_attitude(4, :), 'b-.','LineWidth',.5, 'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[0.85,1,0],'MarkerIndices',marker_space);
%
% xlim([0 SIM_TIME])
% legend('$q_{r0}$','$q_{r1}$','$q_{r2}$','$q_{r3}$', '$q_0$','$q_1$','$q_2$','$q_3$',...
%         'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.45,0.05,0.35]);
% set(gca,"FontSize", 15);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/adaptive_control/Position', '-depsc2')
% xlabel('Time [s]', 'FontSize',24);
% ylabel('Attitude Quaternion', 'FontSize',24);
% box("off")
% grid off;
% print('../Plots/restricted_control/Attitude', '-depsc2')


% figure;
% 
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_desired_position(1, :)+0.4, 'r','LineWidth',5);
% hold on
% plot(time,plot_position(1, :)+0.4, 'r-.','LineWidth',0.5, 'Marker','o','MarkerSize', 12, 'MarkerEdgeColor', 'k','MarkerFaceColor',[1,0.5,0],'MarkerIndices',marker_space);
% plot(time,plot_desired_position_adaptive(1, :), 'b','LineWidth',5);
% plot(time,plot_position_adaptive(1, :), 'b-.','LineWidth',0.5, 'Marker','o','MarkerSize', 12,'MarkerEdgeColor', 'k','MarkerFaceColor',[0,0.85,1],'MarkerIndices',marker_space);
% plot(time,plot_desired_position_pd(1, :)-0.4, 'g','LineWidth',5);
% plot(time,plot_position_pd(1, :)-0.4, 'g-.','LineWidth',0.5, 'Marker','o','MarkerSize', 12,'MarkerEdgeColor', 'k' ,'MarkerFaceColor',[0.85,1,0],'MarkerIndices',marker_space);
% ylim([-1 1])
% xlim([0 SIM_TIME])
% legend('r $p_{adx}$', 'r $p_{ax}$','a $p_{adx}$','a $p_{ax}$', 'pd $p_{adx}$', 'pd $p_{ax}$', ...
%     'FontSize',48, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.85,0.087,0.14,0.9]);
% set(gca,"FontSize", 30);
% set(gca,"OuterPosition", [-0.05,0,1,1])
% xlabel('Time [s]','FontSize',40);
% ylabel('Position [m]','FontSize',40);
% grid off;
% box("off")
% print('../Plots/traslational_plots/xPosition', '-depsc2')
% 
% figure;
% 
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_desired_position(2, :)+0.4, 'r','LineWidth',5);
% hold on
% plot(time,plot_position(2, :)+0.4, 'r-.','LineWidth',0.5, 'Marker','o','MarkerSize', 12, 'MarkerEdgeColor', 'k','MarkerFaceColor',[1,0.5,0],'MarkerIndices',marker_space);
% plot(time,plot_desired_position_adaptive(2, :), 'b','LineWidth',5);
% plot(time,plot_position_adaptive(2, :), 'b-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k', 'MarkerSize', 12, 'MarkerFaceColor',[0,0.85,1],'MarkerIndices',marker_space);
% plot(time,plot_desired_position_pd(2, :)-0.4, 'g','LineWidth',5);
% plot(time,plot_position_pd(2, :)-0.4, 'g-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k', 'MarkerSize', 12, 'MarkerFaceColor',[0.85,1,0],'MarkerIndices',marker_space);
% ylim([-1 1])
% xlim([0 SIM_TIME])
% legend('r $p_{ady}$', 'r $p_{ay}$','a $p_{ady}$','a $p_{ay}$', 'pd $p_{ady}$', 'pd $p_{ay}$', ...
%     'FontSize',48, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.85,0.087,0.14,0.9]);
% set(gca,"FontSize", 30);
% set(gca,"OuterPosition", [-0.05,0,1,1])
% xlabel('Time [s]','FontSize',40);
% ylabel('Position [m]','FontSize',40);
% grid off;
% box("off")
% print('../Plots/traslational_plots/yPosition', '-depsc2')
% 
% figure;
% 
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_desired_position(3, :)+0.4, 'r','LineWidth',5);
% hold on
% plot(time,plot_position(3, :)+0.4, 'r-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k', 'MarkerSize', 12, 'MarkerFaceColor',[1,0.5,0],'MarkerIndices',marker_space);
% plot(time,plot_desired_position_adaptive(3, :), 'b','LineWidth',5);
% plot(time,plot_position_adaptive(3, :), 'b-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k', 'MarkerSize', 12, 'MarkerFaceColor',[0,0.85,1],'MarkerIndices',marker_space);
% plot(time,plot_desired_position_pd(3, :)-0.4, 'g','LineWidth',5);
% plot(time,plot_position_pd(3, :)-0.4, 'g-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k', 'MarkerSize', 12,  'MarkerFaceColor',[0.85,1,0],'MarkerIndices',marker_space);
% ylim([-0.7 0.7])
% xlim([0 SIM_TIME])
% legend('r $p_{adz}$', 'r $p_{az}$','a $p_{adz}$','a $p_{az}$', 'pd $p_{adz}$', 'pd $p_{az}$', ...
%     'FontSize',48, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.85,0.087,0.14,0.9]);
% set(gca,"FontSize", 30);
% set(gca,"OuterPosition", [-0.05,0,1,1])
% xlabel('Time [s]','FontSize',40);
% ylabel('Position [m]','FontSize',40);
% grid off;
% box("off")
% print('../Plots/traslational_plots/zPosition', '-depsc2')
% %
% figure;
% marker_space = 1 : 200: 23000;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[100,124,1848,621])
% set(gcf,"Renderer","painters")
% plot(time,plot_position_norm_error(1, :), 'r','LineWidth',5);
% hold on
% % plot(time,plot_position_norm_error(3, :), 'r-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[1,0.5,0],'MarkerIndices',marker_space);
% plot(time,plot_position_norm_error_adaptive(1, :), 'b','LineWidth',5);
% % plot(time,plot_position_adaptive(3, :), 'b-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[0,0.85,1],'MarkerIndices',marker_space);
% plot(time,plot_position_norm_error_pd(1, :), 'g','LineWidth',5);
% % plot(time,plot_position_pd(3, :), 'g-.','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k' ,'MarkerFaceColor',[0.85,1,0],'MarkerIndices',marker_space);
% ylim([-0.2 0.1])
% xlim([0 SIM_TIME])
% legend('$||\vec{e}_r||$', '$||\vec{e}_{ad}||$', '$||\vec{e}_{pd}||$', ...
%         'FontSize',48, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.55,0.05,0.35]);
% set(gca,"FontSize", 30);
% xlabel('Time [s]','FontSize',40);
% ylabel('Position error [m]','FontSize',40);
% grid off;
% box("off")
% print('../Plots/traslational_plots/error_magnitude', '-depsc2')

%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_position(2, :), 'b','LineWidth',2.5);
% hold on
% plot(time,plot_desired_position(2, :), 'b-.','LineWidth',2.5);
% ylim([-1 1])
% xlim([0 SIM_TIME])
% legend('$p_z$','$p_{zr}$', ...
%         'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.55,0.05,0.35]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/Position2', '-depsc2')
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_position(3, :), 'b','LineWidth',2.5);
% hold on
% plot(time,plot_desired_position(3, :), 'b-.','LineWidth',2.5);
% ylim([-1 1])
% xlim([0 SIM_TIME])
% legend('$p_z$','$p_{zr}$', ...
%         'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.55,0.05,0.35]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/Position3', '-depsc2')



% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_position_norm(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time,plot_desired_position_norm(1, :), 'k-.', 'LineWidth',2.5)
% plot(time,plot_constraint(1, :), 'y','LineWidth',2.5);
% ylim([-0.5 1])
% xlim([0 SIM_TIME])
% legend('$\left\Vert \vec{p} \right\Vert$','$\left\Vert \vec{p_d} \right\Vert$', '$\left\Vert r \right\Vert$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/Constraint', '-depsc2')
% %
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[50,50,1920,1080])
% plot(time,plot_trans_gains(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time,plot_trans_gains(2, :), 'b','LineWidth',2.5);
% plot(time,plot_trans_gains(3, :), 'r','LineWidth',2.5);
% ylim([-100 40])
% xlim([0 25])
% legend('$kp_{x}$','$kp_{y}$','$kp_{z}$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% xlabel('Time [s]','FontSize',24);
% ylabel('Translational kp','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/tkp', '-depsc2')
%
% figure
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[50,50,1920,1080])
% plot(time,plot_trans_kd(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time,plot_trans_kd(2, :), 'b','LineWidth',2.5);
% plot(time,plot_trans_kd(3, :), 'r','LineWidth',2.5);
% ylim([-20 20])
% legend('kd_0','kd_1','kd_2', 'FontSize',24, Box="off")
% xlabel('Time [s]','FontSize',24);
% ylabel('Trans kd [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/tkd', '-depsc2')

% figure
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% plot(time,plot_torques(1, :), 'k','LineWidth',5);
% hold on
% plot(time,plot_torques(2, :), 'b','LineWidth',5);
% plot(time,plot_torques(3, :), 'r','LineWidth',5);
% ylim([-1.6 1.6])
% xlim([0 SIM_TIME])
% legend('$\tau_x$','$\tau_y$','$\tau_z$', ...
%     'FontSize',48, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% set(gca,"FontSize", 30);
% set(gca,"LineWidth", 1.5);
% xlabel('Time [s]','FontSize',40);
% ylabel('Torques [N/m]','FontSize',40);
% 
% 
% zoomX = [16 SIM_TIME]; % x-range of zoom
% zoomY = [-0.5 0.5]; % y-range of zoom
% 
% 
% % Use rectangle function
% rectangle('Position', [zoomX(1), zoomY(1), diff(zoomX), diff(zoomY)], ...
%           'EdgeColor', 'k', 'LineStyle', '--', 'LineWidth', 2.0);
% 
% box off



% set(gca, "LineWidth", 2)
% 
% insetPos = [0.168831168831168,0.56952380952381,0.471861471861472,0.357142857142857]; % [x y width height] relative to figure
% axInset = axes('Position', insetPos);
% 
% % Plot on inset axes
% 
% 
% box on
% 
% plot(time,plot_torques(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time,plot_torques(2, :), 'b','LineWidth',2.5);
% plot(time,plot_torques(3, :), 'r','LineWidth',2.5);
% ylim([-0.03 0.03])
% xlim([16 SIM_TIME])
% axInset.LineWidth = 1.5;
% title(axInset, "Zoomed in")
% grid off;

%% Restricted Torque 
figure
set(gcf,"Color",[1,1,1])
set(gcf,"Position",[73,12,1843,950])

zoomX = [16 SIM_TIME];
zoomY = [-0.005 0.005];

% === (a) Main plot (top left)
ax1 = axes('Position', [0.08,0.597894736842105,0.38825827455236,0.332105263157895]);
plot(time,plot_torques(1, :), 'k','LineWidth',5); hold on
plot(time,plot_torques(2, :), 'b','LineWidth',5);
plot(time,plot_torques(3, :), 'r','LineWidth',5);
ylim([-1.6 1.6]); xlim([0 SIM_TIME]);
rectangle('Position', [zoomX(1), -0.5, diff(zoomX), 1], ...
          'EdgeColor', 'k', 'LineStyle', '--', 'LineWidth', 2.0);
set(gca,"FontSize", 30, "LineWidth", 1.5);
xlabel('Time [s]','FontSize',40);
ylabel('Torques [N/m]','FontSize',40);
box off

% === (b) Zoom tau_x (top right)
ax2 = axes('Position', [0.556158437330441,0.597894736842105,0.417254476397178,0.332105263157895]);
plot(time,plot_torques(1, :), 'k','LineWidth',2);
ylim(zoomY); xlim(zoomX);
set(gca,"FontSize", 30, "LineWidth", 1.5);
xlabel('Time [s]','FontSize',40);
ylabel('$\mathbf{\tau_x}$','FontSize',45,'Interpreter','latex');
%title(' $\tau_x$', 'Interpreter','latex','FontSize',34);
box off

% === (c) Zoom tau_y (bottom left)
ax3 = axes('Position', [0.08,0.07,0.387173087357569,0.331052631578947]);
plot(time,plot_torques(2, :), 'b','LineWidth',2);
ylim(zoomY); xlim(zoomX);
set(gca,"FontSize", 30, "LineWidth", 1.5);
xlabel('Time [s]','FontSize',40);
ylabel('$\mathbf{\tau_y}$ ','FontSize',45,'Interpreter','latex');
%title('Zoom $\tau_y$', 'Interpreter','latex','FontSize',34);
box off

% === (d) Zoom tau_z (bottom right)
ax4 = axes('Position', [0.555615843733044,0.07,0.419424850786761,0.331052631578947]);
plot(time,plot_torques(3, :), 'r','LineWidth',2);
ylim(zoomY); xlim(zoomX);
set(gca,"FontSize", 30, "LineWidth", 1.5);
xlabel('Time [s]','FontSize',40);
ylabel('$\mathbf{\tau_z}$','FontSize',45,'Interpreter','latex');
%title('Zoom $\tau_z$', 'Interpreter','latex','FontSize',34);
box off



print('../Plots/restricted_control/torques', '-depsc2')

%
% figure
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% plot(time,plot_thrust(1, :), 'k','LineWidth',2.5);
% hold on
% ylim([0 1])
% legend('$F_{th}$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% xlabel('Time [s]','FontSize',24);
% ylabel('Thrust [N]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/thrust', '-depsc2')
% marker_space = 1 : 200: 23000;
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[0,0,1920,1080])
% plot3(plot_position(1, :), plot_position(2, :), plot_position(3, :),'LineWidth',2.5);
% hold on
% % plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'LineStyle', 'none' , 'Marker', 'square', MarkerSize=10, MarkerFaceColor='r');
% plot3(plot_desired_position(1, :), plot_desired_position(2, :), plot_desired_position(3, :), 'r-.', 'LineWidth',2.5);
% [sx,sy,sz] = sphere(60);
% s = surf(sx*restriction_radius,sy*restriction_radius,sz*restriction_radius);
% s.FaceAlpha = 0.5;
% s.EdgeColor = 'none';
% s.FaceColor = 'interp';
% xlabel('Coord. X [m]');
% ylabel('Coord. Y [m]');
% zlabel('Coord. Z [m]');
% legend('Position ', 'Reference ', 'FontSize', 24, Box="off", Position=[0.65,0.7,0.1,0.1]);
% set(gca, "XLim", [-0.8 0.8])
% set(gca, "YLim", [-0.8 0.8])
% set(gca, "ZLim", [-0.8 0.8])
% set(gca, "DataAspectRatio", [1 1 1])
% set(gca, "PlotBoxAspectRatio", [1 1 1])
% set(gca,"LineWidth", 2)
% set(gca,"FontSize", 12)
% set(gca,"LabelFontSizeMultiplier", 2)
% view([45,40])
% grid off;
% print('../Plots/restricted_control/3D_Trajectory', '-depsc2')
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time, plot_attitude(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time, plot_attitude(2, :), 'r','LineWidth',2.5);
% plot(time, plot_attitude(3, :), 'g','LineWidth',2.5);
% plot(time, plot_attitude(4, :), 'b','LineWidth',2.5);
% plot(time, plot_desired_attitude(1, :), 'k-.','LineWidth',2.5);
% plot(time, plot_desired_attitude(2, :), 'r-.','LineWidth',2.5);
% plot(time, plot_desired_attitude(3, :), 'g-.','LineWidth',2.5);
% plot(time, plot_desired_attitude(4, :), 'b-.','LineWidth',2.5);
% xlim([0 SIM_TIME])
% legend('$q_0$','$q_1$','$q_2$','$q_3$','$q_{r0}$','$q_{r1}$','$q_{r2}$','$q_{r3}$', ...
%         'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.45,0.05,0.35]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]', 'FontSize',24);
% ylabel('Attitude Quaternion', 'FontSize',24);
% box("off")
% grid off;
% print('../Plots/restricted_control/Attitude', '-depsc2')
% hold off
%
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_desired_position(1, :), 'r','LineWidth',2.5);
% hold on
% plot(time,plot_position(1, :), 'r','LineWidth',0.5, 'Marker','o','MarkerEdgeColor', 'k' ,'MarkerFaceColor',[0.00,0.45,0.74],'MarkerIndices',marker_space);
% % plot(time,plot_position_adaptive(1, :), 'b','LineWidth',2.5);
% % plot(time,plot_desired_position_adaptive(1, :), 'b-.','LineWidth',2.5);
% ylim([-1 1])
% xlim([0 SIM_TIME])
% legend('$p_x$', '$p_{xr}$', ...
%         'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.75,0.052,0.1548]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/Position1', '-depsc2')
% hold off
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_desired_position(2, :), 'g','LineWidth',2.5);
% hold on
% plot(time,plot_position(2, :), 'g-.','LineWidth',.5, 'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[1.00,0.41,0.16],'MarkerIndices',marker_space);
% ylim([-1 1])
% xlim([0 SIM_TIME])
% legend('$p_y$','$p_{yr}$', ...
%         'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.75,0.052,0.1548]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/Position2', '-depsc2')
% hold off
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_desired_position(3, :), 'b','LineWidth',2.5);
% hold on
% plot(time,plot_position(3, :), 'b-.','LineWidth',.5, 'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[0.40,0.90,0.05],'MarkerIndices',marker_space);
% ylim([-1 1])
% xlim([0 SIM_TIME])
% legend('$p_z$','$p_{zr}$', ...
%         'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.75,0.052,0.1548]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/Position3', '-depsc2')
% hold off
%
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_desired_position_norm(1, :), 'r', 'LineWidth',2.5)
% hold on
% plot(time,plot_position_norm(1, :), 'k-.','LineWidth',.5 ,'Marker','o','MarkerEdgeColor', 'k','MarkerFaceColor',[0,0.45,0.75],'MarkerIndices',marker_space);
% plot(time,plot_constraint(1, :), 'Color' , [0.3,0.8,0.2] ,'LineWidth',2.5);
% ylim([-0.5 1])
% xlim([0 SIM_TIME])
% legend('$\left\Vert \vec{p_d} \right\Vert$', '$\left\Vert \vec{p} \right\Vert$', '$\left\Vert r \right\Vert$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Position [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/Constraint', '-depsc2')
% hold off
% %
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[50,50,1920,1080])
% set(gcf,"Renderer","painters")
% plot(time,plot_trans_gains(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time,plot_trans_gains(2, :), 'b','LineWidth',2.5);
% plot(time,plot_trans_gains(3, :), 'r','LineWidth',2.5);
% ylim([-100 40])
% xlim([0 25])
% legend('$kp_{x}$','$kp_{y}$','$kp_{z}$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% set(gca,"FontSize", 15);
% xlabel('Time [s]','FontSize',24);
% ylabel('Translational kp','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/tkp', '-depsc2')
% hold off
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% set(gcf,"Renderer","painters")
% plot(time,plot_trans_kd(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time,plot_trans_kd(2, :), 'b','LineWidth',2.5);
% plot(time,plot_trans_kd(3, :), 'r','LineWidth',2.5);
% ylim([5.5 6.5])
% legend('$kd_{x}$','$kd_{y}$','$kd_{z}$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% xlabel('Time [s]','FontSize',24);
% ylabel('Trans kd [m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/tkd', '-depsc2')
% hold off
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% plot(time,plot_torques(1, :), 'k','LineWidth',2.5);
% hold on
% plot(time,plot_torques(2, :), 'b','LineWidth',2.5);
% plot(time,plot_torques(3, :), 'r','LineWidth',2.5);
% ylim([-0.05 0.05])
% xlim([15 SIM_TIME])
% legend('$\tau_x$','$\tau_y$','$\tau_z$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% xlabel('Time [s]','FontSize',24);
% ylabel('Torques [N/m]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/torques', '-depsc2')
% hold off
%
% figure;
% set(gcf,"Color",[1,1,1])
% set(gcf,"Position",[80,220,1850,525])
% plot(time,plot_thrust(1, :), 'k','LineWidth',2.5);
% hold on
% ylim([0 1])
% legend('$F_{th}$', ...
%     'FontSize',24, 'interpreter', 'latex', ...
%     'Color', [1,1,1], 'EdgeColor', [1,1,1], ...
%     'Position', [0.92,0.65,0.05,0.25]);
% xlabel('Time [s]','FontSize',24);
% ylabel('Thrust [N]','FontSize',24);
% grid off;
% box("off")
% print('../Plots/restricted_control/thrust', '-depsc2')
% hold off