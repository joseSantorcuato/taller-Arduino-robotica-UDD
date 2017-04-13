 /*
 Juego de preguntas
 Santorcuato 2017
*/
 
 String texto;
 
 void setup() {
     pinMode(11, OUTPUT);// para led verde
     pinMode(12, OUTPUT);// para led rojo
     Serial.begin(9600);
     Serial.println("bienvenid@s!");
     Serial.println("Primera pregunta, amarillo:");


   }

   void loop(){
     if(Serial.available()){

      
       texto = Serial.readString();
       texto.trim();




       if(texto =="amarillo"||texto =="AMARILLO"){
         digitalWrite(11, HIGH);
         delay(1000);
         digitalWrite(11, LOW);
         delay(1000);
         Serial.println("Segunda pregunta, verde");
       }

       

      

       if(texto =="verde"||texto =="VERDE"){
         digitalWrite(11, HIGH);
         delay(1000);
         digitalWrite(11, LOW);
           delay(1000);
         Serial.println("Tercera pregunta, rojo");
       }

     
       if(texto=="rojo"||texto=="ROJO"){
         digitalWrite(11, HIGH);
         delay(1000);
         digitalWrite(11, LOW);
           delay(1000);
           Serial.println("FIN, MISION COMPLETADA");
       }

      if(texto != "amarillo" && texto != "verde" && texto != "rojo"){
        Serial.println("ERROR, respuesta incorrecta vuelve a intentarlo.");
        digitalWrite(12, HIGH);
         delay(1000);
         digitalWrite(12, LOW);
         delay(1000);
        }
        

     }
   }

