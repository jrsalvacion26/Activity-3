int potPin = A0; // Potentiometer connected to A0
int thermistorPin = A1; // Thermistor connected to A1
int ldrPin = A2; // Photoresistor connected to A2
int buzzerPin = 9; // Piezo buzzer connected to digital pin 9

int potValue = 0;
int tempValue = 0;
int lightValue = 0;
int temperatureThreshold = 0;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  // Read values from the sensors
  potValue = analogRead(potPin); // Read potentiometer value
  tempValue = analogRead(thermistorPin); // Read thermistor value
  lightValue = analogRead(ldrPin); // Read photoresistor value

  // Map the potentiometer value to a temperature threshold (example: 0-100°C)
  temperatureThreshold = map(potValue, 0, 1023, 0, 100);

  // Convert thermistor value to a temperature (example mapping for demonstration)
  int temperature = map(tempValue, 0, 1023, -40, 125); // Example mapping for temperature range

  // Print values to the serial monitor for debugging
  Serial.print("Potentiometer Value (Threshold): ");
  Serial.println(temperatureThreshold);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Light Level: ");
  Serial.println(lightValue);

  // If the temperature is above the threshold, activate the piezo buzzer
  if (temperature >= temperatureThreshold) {
    // Map the light value to control the buzzer frequency (example: 100-2000 Hz)
    int buzzerFrequency = map(lightValue, 0, 1023, 100, 2000);
    tone(buzzerPin, buzzerFrequency); // Set the buzzer frequency
  } else {
    noTone(buzzerPin); // Turn off the buzzer if temperature is below threshold
  }

  delay(500); // Delay for stability
}
