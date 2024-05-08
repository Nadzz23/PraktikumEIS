#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Setelkan alamat LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definisikan pin yang digunakan untuk mengkoneksikan sensor LDR
const int sensorPin = A0;

// Definisikan batasan nilai cahaya yang diinginkan
const int minCahaya = 200; // nilai minimum cahaya yang diinginkan untuk tanaman anggrek
const int maxCahaya = 1000; // nilai maksimum cahaya yang diinginkan untuk tanaman anggrek

void setup() {
  // Inisialisasi serial monitor
  Serial.begin(9600);

  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();

  // Set pin sensor LDR sebagai input
  pinMode(sensorPin, INPUT);
}

void loop() {
  // Baca nilai dari pin input sensor LDR
  int sensorValue = analogRead(sensorPin);

  // Hitung nilai cahaya berdasarkan nilai dari sensor LDR
  float cahaya = sensorValue / 10.24;

  // Tampilkan hasil pembacaan sensor LDR pada serial monitor
  Serial.print("Nilai sensor LDR: ");
  Serial.println(sensorValue);
  Serial.print("Cahaya: ");
  Serial.println(cahaya);

  // Periksa apakah nilai cahaya masuk dalam batasan yang diinginkan
  if (cahaya >= minCahaya && cahaya <= maxCahaya) {
    Serial.println("Cahaya bagus untuk tanaman anggrek");
    lcd.setCursor(0, 1);
    lcd.print("Cahaya bagus");
  } else {
    Serial.println("Cahaya tidak sesuai untuk tanaman anggrek");
    lcd.setCursor(0, 1);
    lcd.print("Cahaya tidak sesuai");
  }

  // Tampilkan hasil pembacaan sensor LDR pada LCD
  lcd.setCursor(0, 0);
  lcd.print("Cahaya: ");
  lcd.print(cahaya);
  lcd.print(" lux");

  // Tunggu 1 detik sebelum melakukan pembacaan kembali
  delay(1000);

  // Clear LCD setelah 5 detik
  if (millis() > 5000) {
    lcd.clear();
  }
}
