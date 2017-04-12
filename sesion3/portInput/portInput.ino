/*
Modificación sobre cadenas de texto
José Santorcuato Tapia
 */
int miLetra;
void setup() {
  // Abrir puerto serial, usaremos el monitor:
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera mientras se conecte el puerto serial
  }

  // Envia una "alerta":
  Serial.println("Escribe una letra:  ");
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
