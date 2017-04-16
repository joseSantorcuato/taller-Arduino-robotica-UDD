// Modificacion libreria adafruit DHT11
// santorcuato2017

#include "DHT.h"

#define DHTPIN 2     //pin digital

#define DHTTYPE DHT11   // DHT 11 depende del sensor que se tenga
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

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
