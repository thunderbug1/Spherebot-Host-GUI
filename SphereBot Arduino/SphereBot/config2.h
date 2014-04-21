#define BAUDRATE 115200

/*
 * PINS
 */

// Y-Axis
#define YAXIS_DIR_PIN 14
#define YAXIS_STEP_PIN 15
#define YAXIS_ENABLE_PIN 21
#define YAXIS_MS1_PIN -1
#define YAXIS_MS2_PIN -1
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
#define XAXIS_STEP_PIN 8
#define XAXIS_ENABLE_PIN 2
#define XAXIS_MS1_PIN -1
#define XAXIS_MS2_PIN -1
#define XAXIS_ENDSTOP_PIN -1     // -1 -> No Endstop
#define XAXIS_VMS1 HIGH
#define XAXIS_VMS2 HIGH
#define XAXIS_VMS3 HIGH
#define XAXIS_MIN_STEPCOUNT 0    // Travel limits
#define XAXIS_MAX_STEPCOUNT 0
#define XAXIS_STEPS_PER_FULL_ROTATION 200.0
#define XAXIS_MICROSTEPPING 8

#define SERVO_PIN 13

/*
 * Other Configuration
 */

#define DEFAULT_PEN_UP_POSITION 35

#define DEFAULT_ZOOM_FACTOR 0.1808 // With a Zoom-Faktor of .65, I can print gcode for Makerbot Unicorn without changes. 
                               // The zoom factor can be also manipulated by the propretiary code M402
     
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

