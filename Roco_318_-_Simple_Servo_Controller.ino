
/*-----------------------------------------------------------------------------------------------------
  ----------------------------------------------------------------------------------------------------
  ---------------------------------------------------------------------------------------------------

            _____   ____   _____ ____ ____  __  ___
           |  __ \ / __ \ / ____/ __ \___ \/_ |/ _ \
           | |__) | |  | | |   | |  | |__) || | (_) |
           |  _  /| |  | | |   | |  | |__ < | |> _ <
           | | \ \| |__| | |___| |__| |__) || | (_) |
           |_|  \_\\____/ \_____\____/____/ |_|\___/
                    SIMPLE SERVO CONTROLLER

  This is some super simple code for controlling servos via id and angle values.
  This has been made for the Arduino Nano with a PCA9685 16 channel i2c PWM breakout board.

                         -:Wiring:-
                ARDUINO NANO --->    PCA9685
                     A5      --->      SCL
                     A4      --->      SDA
                    GND      --->      GND
                     5V      --->      VCC

  THIS CODE UTILISES THE ADAFRUIT PWM SERVO DRIVER LIBRARY, TO ADD IT TO YOUR ARDUINO IDE:
  - Click on; Sketch
  - Click on; Include Library
  - Click on; Manage Libraries...
  - In the search bar that appears, type in "Adafruit PWM Servo Driver" and click install on the one that appears with the same name.
  Now you have the neccessary libraries to run the following code.

                     -:USING THE CODE:-
                      ----------------
  When uploaded you can then send simple commands to the board to control your servos.
  It must be in the following format:
    ServoNumber,ServoAngle

    So for example:

    UpdateServo(6, 90);

    This will move servo number 6 to an angle of 90 degrees.

  That is everything you need to know to use the board

  Debugging:

  If you send your servo an angle value and it does not line up, then you may need to calibrate the servo minimum and maximum pulse lengths
  Currently they have been calibrated for a range of 0 to 180 degrees for the Towerpro MG996R
  #define SERVOMIN  135 // This is the 'minimum' pulse length count (out of 4096) For the MG996R this wants to be 135
  #define SERVOMAX  482 // this is the 'maximum' pulse length count (out of 4096) For the MG996R this wants to be 482

  ------------------------------------------------------------------------------------------------
  -------------------------------------------------------------------------------------------------
*/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  135 // This is the 'minimum' pulse length count (out of 4096) For the MG996R this wants to be 135
#define SERVOMAX  482 // this is the 'maximum' pulse length count (out of 4096) For the MG996R this wants to be 482

Adafruit_PWMServoDriver PCA9685 = Adafruit_PWMServoDriver();

int ServoPositions[16][5]; //you can use this to make a 2D array of values for your 16 servos positions for each point of your walking gait

//----------------------------------------------------------------------------//
void setup() {
  Serial.begin(115200); //Nice faster speed
  PCA9685.begin();
  PCA9685.setPWMFreq(50); //Maximum speed this can be set to is 1600
  Wire.setClock(400000); // Fast 400khz I2C Mode
  Serial.println("PCA9685 Servo Controller Connected & Ready");
   for (int ServoNumber = 1; ServoNumber <= 16; ServoNumber++) // set all servos to 90 degrees
 
  {            UpdateServo(1, 120);
        UpdateServo(2, 140);
        UpdateServo(3, 120);
        UpdateServo(4, 160);
        UpdateServo(5, 80);
        UpdateServo(6, 60);
        UpdateServo(7, 20);
        UpdateServo(8, 60);
        UpdateServo(9, 50);
        UpdateServo(10, 90);
        UpdateServo(11, 120);
        UpdateServo(12, 0);
        
       

}

}


/*----------------------------------------------------------------------------
   __  __          _____ _   _
  |  \/  |   /\   |_   _| \ | |
  | \  / |  /  \    | | |  \| |
  | |\/| | / /\ \   | | | . ` |
  | |  | |/ ____ \ _| |_| |\  |
  |_|  |_/_/    \_\_____|_| \_|
//  ----------------------------------------------------------------------------*/


  



void loop() {
   
  delay(2000);
  
 for (int ServoNumber = 1; ServoNumber <= 16; ServoNumber++) //leg one
  
 {

  UpdateServo(12, 100);
  delay(200);
  UpdateServo(10, 150);
  delay(200);
  UpdateServo(12,0);
  delay(200);
  UpdateServo(9, 150);
  delay(200);
  UpdateServo(7,80);
  delay(200);
  UpdateServo(9,50);
  delay(350);
  UpdateServo(10,90);
  UpdateServo(7,20);
  delay(400);
  UpdateServo(3,200);
  delay(200);
  UpdateServo(1,60);
  delay(200);
  UpdateServo(3,120);
  delay(200);
  UpdateServo(6,150);
  delay(200);
  UpdateServo(4,90);
  delay(200);
  UpdateServo(6,60);
  delay(350);
  UpdateServo(1,120);
  UpdateServo(4,160);
  delay(400);
  



       
 }
//       UpdateServo(3, 200); 
//       delay(1000);   
//       UpdateServo(1,30);
//      delay(1000);
//      UpdateServo(3,120);
//      delay(1000);
//      UpdateServo(9,150);
//      delay(1000);
//      UpdateServo(7,50);
//      delay(1000);
//      UpdateServo(9,70);
//      delay(1000);
//      UpdateServo(12,100);
//      delay(1000);
//      UpdateServo(10,120);
//      delay(1000);
//      UpdateServo(12,10);
//       delay(1000);
//      UpdateServo(6,150);
//      delay(1000);
//      UpdateServo(4,10);
//      delay(1000);
//      UpdateServo(6,60);
//delay(1000);
//UpdateServo(1,120);
//UpdateServo(7,0);
//UpdateServo(10,30);
//UpdateServo(4,90);


      
       }

      

 


//End of Main
//----------------------------------------------------------------------------//






/*----------------------------------------------------------------------------
   ______ _    _ _   _  _____ _______ _____ ____  _   _  _____
  |  ____| |  | | \ | |/ ____|__   __|_   _/ __ \| \ | |/ ____|
  | |__  | |  | |  \| | |       | |    | || |  | |  \| | (___
  |  __| | |  | | . ` | |       | |    | || |  | | . ` |\___ \
  | |    | |__| | |\  | |____   | |   _| || |__| | |\  |____) |
  |_|     \____/|_| \_|\_____|  |_|  |_____\____/|_| \_|_____/
  ----------------------------------------------------------------------------*/
void UpdateServo (int Id, int Angle) {

  double pulselength = map(Angle, 0, 180, SERVOMIN, SERVOMAX); //map the degree value to pulselength value
  PCA9685.setPWM(Id, 0, pulselength); //Send the angle to the appropiate servo

}
