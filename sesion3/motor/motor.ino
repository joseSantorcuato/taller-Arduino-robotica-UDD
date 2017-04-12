/*
Modificación de ejemplo stepper
 */

#include <Stepper.h>


const int pasosPorVuelta = 60;  // cantidad de radians, hahahaha, cortes por vuelta, en lenguaje sencillo

int pasos;

// puertos de salida que servirán para conexión
Stepper miMotor(pasosPorVuelta, 8, 9, 10, 11);

void setup() {

  miMotor.setSpeed(60); // setea velocidad
 Serial.begin(9600);
}

void loop() {

  Serial.println("Segundos transcurridos:");
 miMotor.step(pasosPorVuelta);
 delay(1000);
 pasos++;
  Serial.println(pasos);



}
