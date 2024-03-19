#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Atur alamat LCD ke 0x27 untuk layar 16 karakter dan 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definisikan pin sensor gerak PIR
const int pirPin = 12;

// Definisikan variabel untuk menghitung deteksi gerak
int motionCount = 0;

void setup() {
  //inisialisasi LCD
  lcd.init();
  lcd.backlight();

  //inisialisasi pin sensor gerak PIR sebagai input
  pinMode(pirPin, INPUT);

  //inisialisasi serial monitor
  Serial.begin(9600);

  //tampilkan pesan awal di LCD
  lcd.setCursor(0, 0);
  lcd.print("Jumlah Deteksi:");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void loop() {
  //baca status sensor gerak PIR
  int state = digitalRead(pirPin);

  //periksa apakah gerak terdeteksi
  if (state == HIGH) {
    //tambahkan 1 ke variabel deteksi gerak
    motionCount++;

    //tampilkan jumlah deteksi gerak terbaru di LCD
    lcd.setCursor(12, 1);
    lcd.print(motionCount);

    //tampilkan pesan "Gerak Deteksi" di LCD
    lcd.setCursor(0, 0);
    lcd.print("Gerak Deteksi");

    //tampilkan pesan"Gerak Deteksi" di serial monitor
    Serial.println("Gerak Deteksi");

    //tunggu 3 detik
    delay(3000);

    //bersihkan LCD
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else {
    //tampilkan pesan "Tak Ter Deteksi" di LCD
    lcd.setCursor(0, 0);
    lcd.print("Tak Ter Deteksi");

    //tampilkan pesan "Tak Ter Deteksi" di serial monitor
    Serial.println("Tak Ter Deteksi");
  }

  //tunggu 1000 ms sebelum memeriksa kembali status sensor gerak PIR
  delay(1000);
}
