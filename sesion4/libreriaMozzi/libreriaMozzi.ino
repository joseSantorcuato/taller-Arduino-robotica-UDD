
//Ejemplo inclusion librerias
//Santorcuato 2017.


#include <MozziGuts.h>
#include <Oscil.h> // 
#include <tables/phasor256_int8.h> // tablas con samples
#include <tables/cos256_int8.h> 

Oscil <PHASOR256_NUM_CELLS, AUDIO_RATE> aForma(PHASOR256_DATA); //se crea oscilador
Oscil<COS256_NUM_CELLS, AUDIO_RATE> aVibrato(COS256_DATA);



#define CONTROL_RATE 64 //definicion


const char poteUno = 0; // potes y entrada analogica
const char poteDos = 1; //

int valorPoteUno ;
int valorPoteDos ;


float lfo;




byte volume;
int frecuencia;


void setup(){
  Serial.begin(57600); // velocidad de conexion

  startMozzi(); // :))

}


void updateControl(){
  // lectura de potenciometros
  valorPoteUno = mozziAnalogRead(poteUno); // valor 0-1023
  valorPoteDos = mozziAnalogRead(poteDos); 


  
  volume = 255; 
  lfo = map(valorPoteUno, 0, 1023, 0, 20); //funcion map escala valor
  frecuencia =  map(valorPoteDos, 0, 1023, 20, 8000); 

  aVibrato.setFreq(lfo);


  
  int fq=frecuencia;
  
  Serial.print("volume = ");
  Serial.println((int)volume);
    aForma.setFreq(fq); // asigna frecuenca
    aVibrato.setFreq(lfo);


}


int updateAudio(){
 Q15n16 vibrato = (Q15n16) volume * aVibrato.next();
    return aForma.phMod(vibrato); // modulacion de fase
}


void loop(){
  audioHook(); // required here
}


