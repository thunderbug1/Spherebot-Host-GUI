/*
 * Copyright 2011 by Eberhard Rensch <http://pleasantsoftware.com/developer/3d>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */
 
#ifndef STEPPERMODEL
#define STEPPERMODEL

// Uncomment if You have Autohoming:
//#define AUTO_HOMING 

class StepperModel
{
private:
  
  int dirPin;
  int stepPin;
  int enablePin;
  int ms1Pin;
  int ms2Pin;
  int ms3Pin;
  
  int endStopPin;
  
  long minStepCount;
  long maxStepCount;
  double steps_per_mm;

  double kStepsPerRevolution;
  int kMicroStepping;

  volatile long currentStepcount;
  volatile long targetStepcount;

  volatile bool direction;
 
  long getStepsForMM(double mm);
 
public:
  volatile long delta;
  volatile long counter;
  double targetPosition;
  
 StepperModel(int inDirPin, int inStepPin, int inEnablePin, int inEndStopPin,int inMs1Pin, int inMs2Pin, int inMs3Pin, bool vms1, bool vms2, bool vms3,
        long minSC, long maxSC,
        double in_kStepsPerRevolution, int in_kMicroStepping);
  
  void resetSteppersForObjectDiameter(double diameter);
  
#ifdef AUTO_HOMING
  void autoHoming();
#endif

  
  void setTargetPosition(double pos);
  double getCurrentPosition();
  
  void enableStepper(bool enabled);
  
  void resetStepper();
  
  void doStep(long intervals);
};

#endif
