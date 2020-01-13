int buzzerPin = 9;    // the number of the buzzer pin
float sinVal;         // Define a variable to save sine value
int toneVal;          // Define a variable to save sound frequency

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin to output mode
  Serial.begin(9600);                 // Initialize the serial port, set the baud rate into 9600
  Serial.println("UNO is ready!");    // Print the string "UNO is ready!"

}

void loop() {
  // Convert analog value of A0 port into digital value
  int adcVal = analogRead(A0);
  // Calculate voltage
  float v = adcVal * 5.0 / 1024;
  // Calculate resistance value of thermistor
  float Rt = 10 * v / (5 - v);
  // Calculate temperature (Kelvin)
  float tempK = 1 / (log(Rt / 10) / 3950 + 1 / (273.15 + 25));
  // Calculate temperature (Celsius)
  float tempC = tempK - 273.15;

  // Send the result to computer through serial port
  Serial.print("Current temperature is: ");
  Serial.print(tempC);
  Serial.println(" C");
  if( tempC > 25 && tempC < 30){
    tone(buzzerPin, 200);           // Output sound frequency to buzzerPin
    delay(1);
  
  }
  else 
  { 
    noTone(buzzerPin);    
  }

  delay(1000);
}
