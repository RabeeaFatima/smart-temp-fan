// Smart Temperature-Controlled Fan System
// Turns on fan (LED) if temp > 30.5°C

const int sensorPin = A0;  // TMP36 analog output
const int ledPin = 9;      // Fan simulation using LED

void setup() {
  Serial.begin(9600);             // Initialize serial monitor
  pinMode(ledPin, OUTPUT);        // Set LED pin as output
}

void loop() {
  int reading = analogRead(sensorPin);          // Read TMP36 analog value
  float voltage = reading * 5.0 / 1024.0;        // Convert to voltage
  float tempC = (voltage - 0.5) * 100.0;         // Convert to Celsius

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

  // Turn fan (LED) ON if temp > 30.5°C
  if (tempC > 30.5) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(2000); // Wait 2 seconds before next reading
}
