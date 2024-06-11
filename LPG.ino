#include <LiquidCrystal.h>
#include <Servo.h>

const int gasSensorPin = A0; // Analog pin for gas sensor
const int redLedPin = 2;     // Pin for red LED
const int greenLedPin = 3;   // Pin for green LED
const int buzzerPin = 4;     // Pin for buzzer
const int servoPin = 5;      // Pin for servo motor

Servo myServo;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.begin(16, 2);
  Serial.print("Gas Leakage");
  lcd.print("Gas Leakage");  
  myServo.attach(servoPin);
}
void loop() {
  int gasValue = analogRead(gasSensorPin);
  if (gasValue > 300) { // if gas threshold value crosses 300 then system will start
    int cnt =0 ;
    lcd.clear();
    Serial.print("Leakage Detected");
    lcd.print("Leakage Detected");
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    myServo.write(90);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  } else { // if gas leakage not detected
    lcd.clear();
    lcd.print("No Leakage"); 
    Serial.print("Leakage Detected");
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    myServo.write(0);
  }

  delay(1000);
}
             
