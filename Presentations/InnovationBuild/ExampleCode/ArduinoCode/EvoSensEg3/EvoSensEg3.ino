/* Using EvoSens Board to measure battery voltage & current
 * By Duleepa J Thrimawithana
 * Revision 1.0
 * 21 June 2019 
 */
 
void setup() {
  // Setup serial communication with a PC via USB connection
  Serial.begin(9600);
  Serial.println("Serial Coms with PC Initiated");
  Serial.println("");
}

void loop() {
  
  // Read voltage on A0 and convert to actual voltage
  float Voltage = (7.8*5)*analogRead(A0)/1024;

  // Read the current sensor output at 0 A as it may 
  // be slightly differrent to 2.5 V 
  float ZeroCurrentV = 5.0*analogRead(A2)/1024;
  
  // Read current on A1 and convert to actual current
  float Current = 25*((5.0)*analogRead(A1)/1024 - ZeroCurrentV);

  // Display both voltage and current on the PC
  Serial.print("Voltage: ");
  Serial.println(Voltage);
  Serial.print("Current: ");
  Serial.println(Current);

  // Re-do the above operations every 1000 ms
  delay(1000);
  
}
