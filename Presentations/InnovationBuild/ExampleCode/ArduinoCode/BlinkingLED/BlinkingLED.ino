/* Blinking LED Example
 * By Duleepa J Thrimawithana
 * Revision 1.1
 * 21 June 2019 
 */


void setup() {
  pinMode(6, OUTPUT);        //Setup pin 6 (LED) as output
}

void loop() {
  
  //Turn the LED on by writing a 'logic HIGH' (5V) to pin 6
  digitalWrite(6, HIGH);     
  delay(1000);                //Wait for 1s
  
  //Turn the LED on by writing a 'logic LOW' (0V) to pin 6
  digitalWrite(6, LOW);      
  delay(1000);                //Wait for 1s and repeat  
  
}
