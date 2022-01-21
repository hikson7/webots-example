/**
 * Description: Simple Webots controller for a quadrupled robot.
 */

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

#define MAX_ANGLE_RAD   1.54
#define TIMESTEP_RAD    0.015
using namespace webots;

int main(int argc, char **argv) {

    Robot *robot = new Robot();

    int timeStep = (int)robot->getBasicTimeStep();

    Motor *motor_A0 = robot->getMotor("motor_A0");
    Motor *motor_A1 = robot->getMotor("motor_A1");
    Motor *motor_A2 = robot->getMotor("motor_A2");

    Motor *motor_B0 = robot->getMotor("motor_B0");
    Motor *motor_B1 = robot->getMotor("motor_B1");
    Motor *motor_B2 = robot->getMotor("motor_B2");

    Motor *motor_C0 = robot->getMotor("motor_C0");
    Motor *motor_C1 = robot->getMotor("motor_C1");
    Motor *motor_C2 = robot->getMotor("motor_C2");

    Motor *motor_D0 = robot->getMotor("motor_D0");
    Motor *motor_D1 = robot->getMotor("motor_D1");
    Motor *motor_D2 = robot->getMotor("motor_D2");

    float tmp_angle = 0.0;
    while (robot->step(timeStep) != -1) {
        if (tmp_angle < MAX_ANGLE_RAD)
            tmp_angle = tmp_angle + TIMESTEP_RAD;
        
        motor_A0->setPosition(tmp_angle);
        motor_A1->setPosition(tmp_angle);
        motor_A2->setPosition(tmp_angle);
        
        motor_B0->setPosition(-tmp_angle);
        motor_B1->setPosition(tmp_angle);
        motor_B2->setPosition(tmp_angle);
        
        motor_C0->setPosition(tmp_angle);
        motor_C1->setPosition(tmp_angle);
        motor_C2->setPosition(tmp_angle);
        
        motor_D0->setPosition(-tmp_angle);
        motor_D1->setPosition(tmp_angle);
        motor_D2->setPosition(tmp_angle);
    };

    delete robot;
    return 0;
}
