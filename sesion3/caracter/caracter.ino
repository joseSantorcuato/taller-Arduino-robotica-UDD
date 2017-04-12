/*
Modificación sobre cadenas de texto
José Santorcuato Tapia

Chile 2017
 */
int miLetra;
int led = 11;
void setup() {
  // Abrir puerto serial, usaremos el monitor:
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera mientras se conecte el puerto serial
  }

  pinMode(led,OUTPUT);// set de 13 para salida led
  // Envia una "alerta":
  Serial.println("Adivina una letra:  ");
  Serial.println();
}

void loop() {
     

  // se disponibiliza el puerto serial:
  if (Serial.available() > 0) {
    miLetra = Serial.read();

    //Imprimir lo enviado
    Serial.print("Escribiste: \'");
    Serial.write(miLetra);
    Serial.print("\'  Valor ASCII: ");

   
    Serial.println(miLetra);

  
 
}
}
