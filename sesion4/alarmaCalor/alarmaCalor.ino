// Modificacion libreria adafruit DHT11
//Alarma calor
// santorcuato2017

#include "DHT.h"

#include "pitches.h"// incluir alturas para alarma

#define DHTPIN 2     //pin digital

#define DHTTYPE DHT11   // DHT 11 depende del sensor que se tenga
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

int sirena[] = {
  NOTE_A4, NOTE_B4
};


void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx prueba!");

  dht.begin();
}

void loop() {
  delay(2000);// espera 2 segundos para comenzar


  float h = dht.readHumidity();// humedad
  //Lectura grados celsius por defecto
  float t = dht.readTemperature();
  // farenheit
  float f = dht.readTemperature(true);
  //checkea que se lean los valors de c,f,h
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Ha fallado la lectura del sensor!");
    return;
  }

  if (t > 26){
  noTone(8);
  tone(8, 440, 500);// funcion tono, frecuencia, duracion
  delay(200);

  noTone(8);
  tone(8, 494, 500);
  delay(500);

    
    
  }
  //indice de calor f
  float hif = dht.computeHeatIndex(f, h);
  //indice de calor c
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Indice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
