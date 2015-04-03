//#define BAUDRATE 9600
#define BAUDRATE 57600
//#define BAUDRATE 115200
//#define BAUDRATE 256000

/*
 * PINS
 
 D0 - 0
 D1 - 1
 D2 - 2
 D3 - 3 
 D4 - 4
 D05 - 5
 D06 - 6
 D07 - 7
 D08 - 8
 D09 - 9
 D10 - 10 
 D11 - 11
 D12 - 12
 D13 - 13
 A00 - 14
 A01 - 15
 A02 - 16
 A03 - 17
 A04 - 18
 A05 - 19
 A06 - 20  //no digital pin
 A07 - 21  //no digital pin
 
 */
 
// Y-Axis -- Pen
#define YAXIS_DIR_PIN 8
#define YAXIS_STEP_PIN 9
#define YAXIS_ENABLE_PIN 2
#define YAXIS_RST_PIN 6
#define YAXIS_SLP_PIN 7
#define YAXIS_MS1_PIN 3
#define YAXIS_MS2_PIN 4
#define YAXIS_MS3_PIN 5
#define YAXIS_ENDSTOP_PIN -1     // -1 -> No Endstop
#define YAXIS_VMS1 LOW
#define YAXIS_VMS2 LOW
#define YAXIS_VMS3 LOW
#define YAXIS_MIN_STEPCOUNT 0    // Travel limits
#define YAXIS_MAX_STEPCOUNT 0
#define YAXIS_STEPS_PER_FULL_ROTATION 200.0
#define YAXIS_MICROSTEPPING 16

//X-Axis -- Egg
#define XAXIS_DIR_PIN 18
#define XAXIS_STEP_PIN 17
#define XAXIS_ENABLE_PIN 12
#define XAXIS_RST_PIN 15
#define XAXIS_SLP_PIN 16
#define XAXIS_MS1_PIN 11
#define XAXIS_MS2_PIN 10
#define XAXIS_MS3_PIN 14
#define XAXIS_ENDSTOP_PIN -1     // -1 -> No Endstop
#define XAXIS_VMS1 LOW
#define XAXIS_VMS2 LOW
#define XAXIS_VMS3 LOW
#define XAXIS_MIN_STEPCOUNT 0    // Travel limits
#define XAXIS_MAX_STEPCOUNT 0
#define XAXIS_STEPS_PER_FULL_ROTATION 200.0
#define XAXIS_MICROSTEPPING 16

#define SERVO_PIN_1 19
#define SERVO_PIN_2 13    //unused -- led on arduino board

/*
 * Other Configuration
 */

#define DEFAULT_PEN_UP_POSITION 35

#define DEFAULT_ZOOM_FACTOR 0.1808 // With a Zoom-Faktor of .65, I can print gcode for Makerbot Unicorn without changes. 
                               // The zoom factor can be also manipulated by the propretiary code M402
#define X_SCALING_FACTOR    1.65/2    //this factor is for correction to meet the unicorn coordinates 
#define Y_SCALING_FACTOR    1
/*
 * Microstepping Information
 */     
                               
//MS1, MS2 and MS3 are optional. You can also make these settings by hardwiring the pins to high or low
 
   /* MS1  |  MS2  |  MS3      Microstepping Resolution
    -----------------------
      L    |  L    |  L     ->  Full Step
      H    |  L    |  L     ->  Half Step 
      L    |  H    |  L     ->  Quarter Step
      H    |  H    |  L     ->  Eighth Step
      H    |  H    |  H     ->  Sixteenth Step
  */

