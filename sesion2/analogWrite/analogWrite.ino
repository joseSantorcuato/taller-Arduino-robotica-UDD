int pinLed = 11;    // Led conectado a pin 9 ~
void setup() {
Serial.begin(9600);
}

void loop() {
  // fade de 0 a 255, efecto dimmer
 for (int miVariable = 0 ; miVariable <= 255; miVariable += 5) {
   // ciclo for, para variable x, si variable es menos o = a 255, incrementa en 5
   analogWrite(pinLed, miVariable);
  delay(100);
  }

 // fade de 255-0, efecto dimmer 
 for (int miVariable = 255 ; miVariable >= 0; miVariable -= 5) {

    analogWrite(pinLed, miVariable);
  delay(100);
 }
}
