//Modificacion ejemplo boton
//Para trabajar fucniones digitalRead/digitalWrite

const int pinBoton = 2;     //pin a conectar boton
const int pinLed =  13;      //pin para led


int estadoBoton = 0;         //variable que gaurdara el estado del boton (HIGH,LOW,1,0)

void setup() {

  pinMode(pinLed, OUTPUT);// seteo de los pines, pueden ser entrada salida, aca, salida
 pinMode(pinBoton, INPUT);//seteo de los pines, pueden ser entrada salida, aca, entrada
 //funcion pinMode tiene 2 arg, numero y accion
 }

void loop() {
 //la variable ahora contendra la funcion digitalRead que tiene seteado el 2
  estadoBoton = digitalRead(pinBoton);

 //estructura de control
  //si el estado del boton es == a 1 prende el led
  if (estadoBoton == HIGH) {

  digitalWrite(pinLed, HIGH);

 } else { //si no esta presionado lo apaga

    digitalWrite(pinLed, LOW); //funcion digitalWrite tiene 2 arg, numero y accion
  }
}
