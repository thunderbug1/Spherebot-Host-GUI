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
 
#include "StepperModel.h"
#include "Arduino.h"


/*
 * inEnablePin < 0 => No Endstop
 */
StepperModel::StepperModel(int inDirPin, int inStepPin, int inEnablePin, int inEndStopPin,int inMs1Pin, int inMs2Pin, bool vms1,bool vms2,
        long minSC, long maxSC,
        double in_kStepsPerRevolution, int in_kMicroStepping)
{
  kStepsPerRevolution=in_kStepsPerRevolution;
  kMicroStepping=in_kMicroStepping;

  dirPin = inDirPin;
  stepPin = inStepPin;
  enablePin = inEnablePin;
  endStopPin = inEndStopPin;
  ms1Pin = inMs1Pin;
  ms2Pin = inMs2Pin;
    
  minStepCount=minSC;
  maxStepCount=maxSC;
  
  pinMode(dirPin, OUTPUT);  
  pinMode(stepPin, OUTPUT);  
  pinMode(enablePin, OUTPUT);  
  if(endStopPin>=0)
    pinMode(endStopPin, INPUT); 
  if((ms1Pin >=0) && (ms2Pin >=0))
  {
	  pinMode(ms1Pin, OUTPUT);  
	  pinMode(ms2Pin, OUTPUT); 	
	  digitalWrite(ms1Pin, vms1);    
	  digitalWrite(ms2Pin, vms2);
  }

  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, LOW);
 
  currentStepcount=0;
  targetStepcount=0;

  steps_per_mm = (int)((kStepsPerRevolution/(45.*M_PI))*kMicroStepping+0.5); // default value for a "normal" egg (45 mm diameter)
  enableStepper(false);
}

void StepperModel::resetSteppersForObjectDiameter(double diameter)
{
  // Calculate the motor steps required to move per mm.
  steps_per_mm = (int)((kStepsPerRevolution/(diameter*M_PI))*kMicroStepping+0.5);
  if(endStopPin>=0)
  {
#ifdef AUTO_HOMING
    autoHoming();
#endif
    enableStepper(false);
  }
  else
    resetStepper();    
}

long StepperModel::getStepsForMM(double mm)
{
  long steps = (long)(steps_per_mm*mm);
  
//  Serial.print("steps for ");
//  Serial.print(mm);
//  Serial.print(" mm: ");
//  Serial.println(steps);
  
  return steps;
}

/* Currently unused */
/*
void StepperModel::setTargetStepcount(long tsc)
{
   targetPosition = (double)tsc/steps_per_mm;
   targetStepcount = tsc;
   delta = targetStepcount-currentStepcount;
   direction = true;
   if (delta != 0) {
     enableStepper(true);
   }
   if (delta < 0) {
	delta = -delta;
	direction = false;
   }
}*/

void StepperModel::setTargetPosition(double pos)
{
   targetPosition = pos;
   targetStepcount = getStepsForMM(targetPosition);
   //Serial.println(targetStepcount);
   delta = targetStepcount-currentStepcount;
   direction = true;
   if (delta != 0) {
     enableStepper(true);
   }
   if (delta < 0) {
	delta = -delta;
	direction = false;
   }
}

double StepperModel::getCurrentPosition()
{
    return (double)currentStepcount/steps_per_mm;
}

void StepperModel::enableStepper(bool enabled)
{
  digitalWrite(enablePin, !enabled);
}

void StepperModel::resetStepper()
{
  enableStepper(false);
  currentStepcount=0;
  targetStepcount=0;
  delta=0;  
}

void StepperModel::doStep(long intervals)
{
  counter += delta;
  if (counter >= 0) {
    digitalWrite(dirPin, direction?HIGH:LOW);
    counter -= intervals;
    if (direction) {
      if(maxStepCount==0 || currentStepcount<=maxStepCount)
      {
        digitalWrite(stepPin, HIGH);
        currentStepcount++;
      }
    } else {
      if(minStepCount==0 || currentStepcount>=minStepCount)
      {
        digitalWrite(stepPin, HIGH);
        currentStepcount--;
      }
    }
    digitalWrite(stepPin, LOW);
  }
}  

#ifdef AUTO_HOMING
void StepperModel::autoHoming()
{
  enableStepper(true);
  digitalWrite(dirPin, LOW);
 
  while(digitalRead(endStopPin))
  {
        digitalWrite(stepPin, HIGH);
        digitalWrite(stepPin, LOW);
        delay(1);
  }

  currentStepcount= minStepCount-16;
}
#endif
