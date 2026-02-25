#include <LiquidCrystal.h>
#include <DFRobot_DHT11.h>

// Create DHT object
DFRobot_DHT11 DHT;
#define DHT11_PIN A1

// LCD Pins
const int rs = 8;
const int en = 9;
const int d4 = 10;
const int d5 = 11;
const int d6 = 12;
const int d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pump Pins
int pmp = 6;
int pmp1 = 7;

// Moisture Sensor Pin
int moi = A0;

// Variables
int mval, hval, tval;
int cnt = 0;

void setup() {
  Serial.begin(9600);
  delay(200);

  pinMode(pmp, OUTPUT);
  pinMode(pmp1, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("WELCOME");
  delay(1000);

  digitalWrite(pmp, LOW);
  digitalWrite(pmp1, LOW);
}

void loop() {

  // Read Moisture Value (Convert to Percentage)
  mval = 100 - analogRead(moi) / 10.23;

  // Read DHT11
  DHT.read(DHT11_PIN);
  tval = DHT.temperature;
  hval = DHT.humidity;

  // Display on LCD
  lcd.clear();
  lcd.print("T:");
  lcd.print(tval);
  lcd.print(" H:");
  lcd.print(hval);

  lcd.setCursor(0, 1);
  lcd.print("M:");
  lcd.print(mval);
  lcd.print(" P:");
  lcd.print(digitalRead(pmp));

  // Moisture Condition
  if (mval < 30) {
    digitalWrite(pmp, HIGH);   // Turn ON pump
  } else {
    digitalWrite(pmp, LOW);    // Turn OFF pump
  }

  delay(1000);

  // Send Data to Serial Every 15 Seconds
  cnt++;
  if (cnt > 15) {
    cnt = 0;

    Serial.print("Moisture: ");
    Serial.print(mval);
    Serial.print(" Temperature: ");
    Serial.print(tval);
    Serial.print(" Humidity: ");
    Serial.print(hval);
    Serial.print(" Pump: ");
    Serial.println(digitalRead(pmp));
  }
}
