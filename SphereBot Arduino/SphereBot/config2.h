#define BAUDRATE 115200

/*
 * PINS
 */

// Y-Axis
#define YAXIS_DIR_PIN 9
#define YAXIS_STEP_PIN 8
#define YAXIS_ENABLE_PIN 7
#define YAXIS_MS1_PIN -1
#define YAXIS_MS2_PIN -1
#define YAXIS_MS3_PIN -1
#define YAXIS_ENDSTOP_PIN -1     // -1 -> No Endstop
#define YAXIS_VMS1 HIGH
#define YAXIS_VMS2 HIGH
#define YAXIS_VMS3 HIGH
#define YAXIS_MIN_STEPCOUNT 0    // Travel limits
#define YAXIS_MAX_STEPCOUNT 0
#define YAXIS_STEPS_PER_FULL_ROTATION 200.0
#define YAXIS_MICROSTEPPING 8

//X-Axis
#define XAXIS_DIR_PIN 10
#define XAXIS_STEP_PIN 11
#define XAXIS_ENABLE_PIN 12
#define XAXIS_MS1_PIN -1
#define XAXIS_MS2_PIN -1
#define XAXIS_MS3_PIN -1
#define XAXIS_ENDSTOP_PIN -1     // -1 -> No Endstop
#define XAXIS_VMS1 HIGH
#define XAXIS_VMS2 HIGH
#define XAXIS_VMS3 HIGH
#define XAXIS_MIN_STEPCOUNT 0    // Travel limits
#define XAXIS_MAX_STEPCOUNT 0
#define XAXIS_STEPS_PER_FULL_ROTATION 200.0
#define XAXIS_MICROSTEPPING 8

#define SERVO_PIN 2

/*
 * Other Configuration
 */

#define DEFAULT_PEN_UP_POSITION 90

#define DEFAULT_ZOOM_FACTOR 0.1808//0.65        //0.1808 // // With a Zoom-Faktor of .65, I can print gcode for Makerbot Unicorn without changes. 
                                       // The zoom factor can be also manipulated by the propretiary code M402
#define X_SCALING_FACTOR    1.71/2    //this factor is for correction to meet the unicorn coordinates 
#define Y_SCALING_FACTOR    1.0    
/*
 * Microstepping Information
 */     
                               
//MS1, MS2 and MS3 are optional. You can simply make these settings by hardwiring the pins to high or low
 
   /* MS1  |  MS2  |  MS3      Microstepping Resolution
    -----------------------
      L    |  L    |  L     ->  Full Step
      H    |  L    |  L     ->  Half Step 
      L    |  H    |  L     ->  Quarter Step
      H    |  H    |  L     ->  Eighth Step
      H    |  H    |  H     ->  Sixteenth Step
  */

