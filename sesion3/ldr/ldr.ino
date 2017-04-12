/*
 Modificación entrada análoga
 Santorcuato 2017
 Recomiendo Resistencia de 1 k
 */

int ldr = 0;    
int led = 13;      
int valorLectura = 0;  

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);// seteamos 13 como salida
}

void loop() {
  valorLectura = analogRead(ldr); //contendra lectura analogica de sensor

  digitalWrite(led, HIGH);// prende led
 
  delay(valorLectura);
  // apaga led con velocidad de acuerdo a lectura de ldr
  digitalWrite(led, LOW);
  
  delay(valorLectura);
  Serial.println(valorLectura);// imprime valor ldr
}
