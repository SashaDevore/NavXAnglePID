// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES


#include "WPILib.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<AnalogGyro> RobotMap::driveBasePIDFakeGyro;
std::shared_ptr<SpeedController> RobotMap::driveBasePIDLeftMotor1;
std::shared_ptr<PIDController> RobotMap::driveBasePIDControllerPID;
std::shared_ptr<SpeedController> RobotMap::driveBasePIDLeftMotor2;
std::shared_ptr<SpeedController> RobotMap::driveBasePIDRightMotor1;
std::shared_ptr<SpeedController> RobotMap::driveBasePIDRightMotor2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION


AHRS* RobotMap::ahrs = NULL;



void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    ahrs = new AHRS(SPI::Port::kMXP);

    driveBasePIDFakeGyro.reset(new AnalogGyro(0));
    lw->AddSensor("DriveBasePID", "FakeGyro", driveBasePIDFakeGyro);
    driveBasePIDFakeGyro->SetSensitivity(0.007);
    driveBasePIDLeftMotor1.reset(new Jaguar(2));
    lw->AddActuator("DriveBasePID", "LeftMotor1", std::static_pointer_cast<Jaguar>(driveBasePIDLeftMotor1));
    
    driveBasePIDControllerPID.reset(new PIDController(1.0, 0.0, 0.0,/* F: 0.0, */ ahrs, driveBasePIDLeftMotor1.get(), 0.02));
    lw->AddActuator("DriveBasePID", "ControllerPID", driveBasePIDControllerPID);
    driveBasePIDControllerPID->SetContinuous(false); driveBasePIDControllerPID->SetAbsoluteTolerance(0.2); 
        driveBasePIDControllerPID->SetOutputRange(-1.0, 1.0);
    driveBasePIDLeftMotor2.reset(new Jaguar(3));
    lw->AddActuator("DriveBasePID", "LeftMotor2", std::static_pointer_cast<Jaguar>(driveBasePIDLeftMotor2));
    
    driveBasePIDRightMotor1.reset(new Jaguar(0));
    lw->AddActuator("DriveBasePID", "RightMotor1", std::static_pointer_cast<Jaguar>(driveBasePIDRightMotor1));
    
    driveBasePIDRightMotor2.reset(new Jaguar(1));
    lw->AddActuator("DriveBasePID", "RightMotor2", std::static_pointer_cast<Jaguar>(driveBasePIDRightMotor2));
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS


}

