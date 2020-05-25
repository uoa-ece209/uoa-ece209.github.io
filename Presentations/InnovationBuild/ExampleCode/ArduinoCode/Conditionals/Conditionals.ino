/* Conditionals Example
 * By Duleepa J Thrimawithana
 * Revision 1.0
 * 21 June 2017 
 */

const int LEDPin = 6;                            //LED is connected to pin 11
const int switchPin = 5;                         //Push button is connected to pin 12
int switchInput;                                  //Declare a variable to hold input from switch
int flagA = 0;                                    //Declare a variable as a flag and initialise to 0

void setup() {
  pinMode(LEDPin, OUTPUT);                        //Initialize LED pin as output
  pinMode(switchPin, INPUT);                      //Initialize push button pin as input
}

void loop() {
  switchInput = digitalRead(switchPin);           //Read the input from switch

  if (switchInput==1 && flagA==0){                //If push button pressed and flagA is 0
    digitalWrite(LEDPin, !digitalRead(LEDPin));   //Toggle LEDPin 
    flagA = 1;                                    //Set the flag to 1 to avoid toggling if button held-on
  }
  if (switchInput==0) {                           //If push button is released
    flagA = 0;                                    //Reset the flag to 0 and wait for a button press
  }
}
