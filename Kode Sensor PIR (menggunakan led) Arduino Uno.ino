#define PIR_PIN 2
#define LED_PIN 13

long int ledOn = 10000, lastTime = -ledOn;

void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}

void loop(){
  if(digitalRead(PIR_PIN) == HIGH){
    Serial.println("Gerakk Ter Deteksi");
    lastTime = millis();
    delay(1000);
  }
  else{
    Serial.println("Gerak Tidak Ter Deteksi");
    delay(3000);
  }

  if ((millis() - lastTime) < ledOn)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}
