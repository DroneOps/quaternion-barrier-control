#include "math3d.h"


// CONSTANTS
static float GRAVITY_MAGNITUDE = 9.81;
static float CF_MASS = 0.027;
static float DELTA_T = 0.01;

static struct mat33 CRAZYFLIE_INERTIA =
    {{{16.6e-6f, 0.83e-6f, 0.72e-6f},
      {0.83e-6f, 16.6e-6f, 1.8e-6f},
      {0.72e-6f, 1.8e-6f, 29.3e-6f}}};


static float THRUST_MIN = 1;
static float THRUST_MAX = 18;
static float ROTATION_MAX = 30;

// Static gains
static float TRANS_KP_FIXED[] = {4.0f,4.0f,4.0f};
static float TRANS_KD_FIXED[] = {3.75f,3.75f,3.75f};
static float ROT_KP_FIXED[] = {150.0f,150.0f,150.0f};
static float ROT_KD_FIXED[] = {50.0f,50.0f,50.0f};

// Dynamic gains
float trans_kp[] = {4.0f,4.0f,4.0f};
float trans_kd[] = {3.75f,3.75f,3.75f};
float rot_kp[] = {150.0f,150.0f,150.0f};
float rot_kd[] = {50.0f,50.0f,50.0f};


// Adaptive gains
static float LAMBDA[] = {1.5, 0.005, 0.05, 0.005};
static float ALPHA[] = {6, 0.005, 8, 0.005};

void main(){

    struct vec posError = vzero();
    struct vec posErrorArray[] = {}; 

    struct vec accDes = vzero();
    float thrustDes = 0;


    struct quat orientationError = qeye(); //init
    struct quat orientationDes = qeye(); //init

    // // Current attitude
    // struct quat attitude = mkquat(
    //   state->attitudeQuaternion.x,
    //   state->attitudeQuaternion.y,
    //   state->attitudeQuaternion.z,
    //   state->attitudeQuaternion.w);

    struct quat attitude = mkquat();

    // Errors
    struct vec posErrorPrev = posError; 
    // struct vec posError = mkvec(setpoint->position.x - state->position.x,
    //                             setpoint->position.y - state->position.y,
    //                             setpoint->position.z - state->position.z);
    // float posErrorArray[] = {posError.x, posError.y, posError.z};

    struct vec velError = vdiv(posError, DELTA_T);
    float velErrorArray[] = {velError.x, velError.y, velError.z};

    // ------- Translational control -------

    // Calculate gain adaptation
    for(int i = 0; i < 3; i++){
      //To do: add restrictions
      float trans_kp_dot = (LAMBDA[0])*(posErrorArray[i])*sgn(posErrorArray[i]) + LAMBDA[1]*(TRANS_KP_FIXED[i] - trans_kp[i]);
      float trans_kd_dot = LAMBDA[2]*(velErrorArray[i]) + LAMBDA[3]*(TRANS_KD_FIXED[i] - trans_kd[i]);

      trans_kp[i] = trans_kp[i] + trans_kp_dot * DELTA_T;
      trans_kd[i] = trans_kd[i] + trans_kd_dot * DELTA_T;
    }
    struct vec trans_kp_vec = mkvec(trans_kp[0], trans_kp[1], trans_kp[2]);
    struct vec trans_kd_vec = mkvec(trans_kd[0], trans_kd[1], trans_kd[2]);

    // Translational control law equation
    // -MASS*(trans_kp.*position_error + trans_kd.*(velocity_error) + (-GRAVITY)); 

    // trans_kp.*position_error + trans_kd.*(velocity_error)
    struct vec trans_control = vadd(
      veltmul(trans_kp_vec,posError),
      veltmul(trans_kd_vec,velError)) ;
    // -GRAVITY
    trans_control.z -= GRAVITY_MAGNITUDE;
    // *-MASS
    trans_control = vscl(-CF_MASS, trans_control);

    float norm_trans_control = vmag(trans_control);
    struct vec control_direction = vzero();

    if (norm_trans_control != 0){
      control_direction = vdiv(trans_control,norm_trans_control);
    }


}