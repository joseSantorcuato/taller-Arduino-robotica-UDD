/*
Compara cadenas de texto
José Santorcuato Tapia
 */

String input;
 
String texto = "amarillo";


void setup() {

Serial.begin(9600); // abre puerto serial

Serial.println("Esta es la historia de un elefante amarillo, a continuación escribe el color del elefante");

}

void loop() {

while(Serial.available()) {
input = Serial.readString();// leemos la cadena de texto ingresada desde terminal



if (input == texto){
  
  Serial.println("Correcto");

  }
  else{
  Serial.println("Incorrecto, vuelve a intentarlo ;)");

  
  }


}
}
