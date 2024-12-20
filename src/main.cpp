#include <Arduino.h>

const int potPin = 36;  // ขา 36 สำหรับ Potentiometer
const int ledPins[] = {23, 19, 18, 5, 17, 16, 4, 0}; // ขา LED 8 หลอด

void setup() {
  for (int i = 0; i < 8; i++) pinMode(ledPins[i], OUTPUT); // ตั้งค่า LED เป็น OUTPUT
}

void loop() {
  int potValue = analogRead(potPin);  // อ่านค่าจาก potentiometer
  int mappedValue = map(potValue, 0, 4095, 0, 100);  // แปลงค่าจาก 0-4095 เป็น 0-100

  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], i < mappedValue / 12 ? HIGH : LOW);  // เปิด LED ตามค่าที่แปลง
  }

  delay(50);  // หน่วงเวลาเล็กน้อย
}