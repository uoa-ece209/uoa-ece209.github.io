/* Serial communication example
 * By Duleepa J Thrimawithana
 * Revision 1.1
 * 21 June 2019 
 */

void setup() {
  // Setup serial communication with a PC via USB connection
  Serial.begin(9600);
}

void loop() {
  
  // Display you name on the PC
  Serial.print("I am Duleepa");
  
  // Re-do the above operation every 1s
  delay(1000);
  
}
