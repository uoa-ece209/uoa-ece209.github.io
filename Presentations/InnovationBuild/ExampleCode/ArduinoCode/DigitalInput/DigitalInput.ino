/* Reading Inputs Example
 * By Duleepa J Thrimawithana
 * Revision 1.0
 * 21 June 2017 
 */

const int LEDPin = 6;                  //LED is connected to pin 11
const int switchPin = 5;               //Push button is connected to pin 12
int switchInput;                        //Declare a variable to hold input from switch

void setup() {
  pinMode(LEDPin, OUTPUT);              //Initialize LED pin as output
  pinMode(switchPin, INPUT);            //Initialize push button pin as input
}

void loop() {
  switchInput = digitalRead(switchPin); //Read the input from switch
  digitalWrite(LEDPin, switchInput);    //Write the value in switchInput to LEDPin and repeat
}
