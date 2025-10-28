const int ledPin = 6; 
const int potPin = A1; 
const float refVoltage=3.3;


void setup() {
pinMode(ledPin, OUTPUT); 
Serial.begin(9600);
} 

void loop() {
int analogValue = analogRead(A1);

digitalWrite(ledPin, HIGH);
delay(500); 
digitalWrite(ledPin, LOW);
delay(500); 

float voltage = analogValue*(refVoltage);
Serial.print("Voltage: ");
Serial.print(voltage);
}
