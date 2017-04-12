/*
Modificación de ejemplo arduino_input
Santorcuato 2017
*/

import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

color off = color(255,255,255);
color on = color(84, 145, 158);

void setup() {
  size(470, 280);

  println(Arduino.list());

  //arduino = new Arduino(this, Arduino.list()[0], 57600);

 arduino = new Arduino(this, "/dev/cu.usbmodem1411", 57600); // en mi caso es el puerto cu
 
  
}

void draw() {
  background(off);
  stroke(on);
  
  

  noFill();
  for (int i = 0; i <= 5; i++) {
    ellipse(100 + i * 30, 100, arduino.analogRead(i) / 16, arduino.analogRead(i) / 16);
  }
}