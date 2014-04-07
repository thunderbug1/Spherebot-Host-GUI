/*
 * PINS
 */
 
   /*  ms1  |  ms2
    ----------------
      L    |  L        ->  Full Step
      H    |  L        ->  Half Step 
      L    |  H        ->  Quarter Step
      H    |  H        ->  Sixteenth Step
  */
  
#define XAXIS_VMS1 HIGH
#define XAXIS_VMS2 HIGH
#define YAXIS_VMS1 HIGH
#define YAXIS_VMS2 HIGH
 
#define YAXIS_DIR_PIN 14
#define YAXIS_STEP_PIN 15
#define YAXIS_ENABLE_PIN 21
#define YAXIS_MS1_PIN 19      //don´t make this connection!! ADC6 and ADC7 can not be used as a digital pin ( I made the pull up connection manually)
#define YAXIS_MS2_PIN 28
//#define YAXIS_MS3_PIN 18
#define YAXIS_ENDSTOP_PIN -1    //13    

#define XAXIS_DIR_PIN 10
#define XAXIS_STEP_PIN 8
#define XAXIS_ENABLE_PIN 2
#define XAXIS_MS1_PIN 3
#define XAXIS_MS2_PIN 4
#define XAXIS_ENDSTOP_PIN -1 // <0 0> No Endstop!

#define SERVO_PIN 13

/*
 * Other Configuration
 */

#define DEFAULT_PEN_UP_POSITION 35
#define XAXIS_MIN_STEPCOUNT -5.6*230000
#define XAXIS_MAX_STEPCOUNT 5*230000
#define DEFAULT_ZOOM_FACTOR 0.1808 // With a Zoom-Faktor of .65, I can print gcode for Makerbot Unicorn without changes. 
                               // The zoom factor can be also manipulated by the propretiary code M402

