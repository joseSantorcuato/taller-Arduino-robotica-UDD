int miLed = 13; // He creado una variable global de tipo entero con valor 13,

void setup() {

pinMode(miLed, OUTPUT);//los pines son de entrada y salida, ahora es salida
}


void loop() {
digitalWrite(miLed, HIGH);   // 1 para salida 13, prende
delay(1000);                       // espera 1 segundo, 2000 = 2 segundos, etc
digitalWrite(miLed, LOW);    // 0 para salida 13, apaga
delay(1000);                       // espera un segundo
}
