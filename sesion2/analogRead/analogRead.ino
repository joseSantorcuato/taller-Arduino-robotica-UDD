/*
Ejemplo modificacion analogRead e impresion en terminal/monitor
*/
int valorSensor = 0; //incializamos una variable que guardara el valor del pote
int pote = 0;// incializamos una variable para conectar el pote

void setup() {
  Serial.begin(9600); // 9600 baudios, o bytes por segundo
}

void loop() {
  int valorSensor = analogRead(pote);
  
  float voltaje = valorSensor * (5.0 / 1023.0);// arduino entrega 5v y la lectura es lineal a 1023
  Serial.println("voltaje:"); // permite imprimir en monitor una cadena de texto
  Serial.println(voltaje); //imprime el valor del voltaje
  Serial.println("");// le dejo un esapcio
  Serial.println("Valor lineal sensor:");//
  Serial.println(valorSensor);
  Serial.println("");
  
  delay(1000);
}
