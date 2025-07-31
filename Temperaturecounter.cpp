#include <LiquidCrystal.h>

const int buttonPin = 8;
const int tempPin = A0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int counter = 0;
int lastButton = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.begin(16, 2);
}

void loop() {
  int btn = digitalRead(buttonPin);
  if (btn == LOW && lastButton == HIGH) {
    counter++;
    delay(50);  // basic debounce
  }
  lastButton = btn;
  float sum = 0;
  const int N = 5;
  for (int i = 0; i < N; i++) { sum += analogRead(tempPin); delay(10); }
  float raw = sum / N;
  float voltage = (raw / 1023.0) * 5.0;
  float c = voltage * 100.0;  // LM35: 10 mV per °C
  float f = c * 1.8 + 32;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Count: ");
  lcd.print(counter);
  lcd.setCursor(0, 1);
  lcd.print(c, 1); lcd.write(223); lcd.print("C ");
  lcd.print(f, 1); lcd.write(223); lcd.print("F ");
  delay(500);
}
