/* Using EvoSens Board to send data to phone via Bluetooth
 * By Duleepa J Thrimawithana
 * Revision 1.0
 * 21 June 2019
 */

#include <AltSoftSerial.h>
AltSoftSerial BTserial; 

// Setup a veriable to hold a count value for our counter
int counter = 0;
  
void setup() {
  // Setup serial communication with a PC via USB connection
  Serial.begin(9600);
  Serial.println("Serial Coms with PC Initiated");

  // Setup serial communication with BLE using AltSoftSerial
  BTserial.begin(9600);  
  Serial.println("Serial Coms with BLE Initiated");
  Serial.println("");
}

void loop() {

  // Display the value of counter on PC
  Serial.print("Counter Value: ");
  Serial.println(counter);

  // Transmit the value of counter via BLE to phone
  BTserial.write(counter);
  
  counter = counter+1; // Increment the counter by 1
  if (counter>10)  // When counter reach 10, reset it to 0
    counter=0;

  // Wait for 1s before repeating above steps
  delay(1000);
}
