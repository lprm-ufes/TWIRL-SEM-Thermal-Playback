#include <Wire.h>
int IN1 = 3;                             // pino IN1 conectado porta D2 Arduino
int IN2 = 2;                             // pino IN2 conectado porta D3 Arduino
int IN3 = 4;                             // pino IN1 conectado porta D4 Arduino
int IN4 = 5;                             // pino IN2 conectado porta D5 Arduino
byte byteRead;
void setup()
{
  Wire.begin();
  Serial.begin(9600);                    // console serial 9600 Bps 
  pinMode(IN1, OUTPUT);                  // definições das portas IN1 ate IN4 como portas de saidas 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);  
  
  digitalWrite(IN1, HIGH);               // desativa porta IN1 
  digitalWrite(IN2, HIGH);               // desativa porta IN2 
  digitalWrite(IN3, HIGH);               // desativa porta IN3 
  digitalWrite(IN4, HIGH);               // desativa porta IN4
  delay(2000); //INTERVALO DE 2 SEGUNDO ANTES DE INICIAR
}
 
void loop(){  
if (Serial.available())  //verifica se tem dados diponível para leitura{
       byteRead = Serial.read(); //le bytwe mais recente no buffer da serial
       //Serial.println(byteRead);
       if(byteRead == '1'){
            Serial.println("Rele K1 acionado");
            digitalWrite(IN1, LOW);                // acionamento relé K1   
        }
       if(byteRead == '2'){
            Serial.println("Rele K2 acionado");
            digitalWrite(IN2, LOW);                // acionamento relé K2          
        }
       if(byteRead == '3'){
            Serial.println("Rele K3 acionado"); 
            digitalWrite(IN3, LOW);                // acionamento relé K3        
        }
       if(byteRead == '4'){
            Serial.println("Rele K4 acionado"); 
            digitalWrite(IN4, LOW);                // acionamento relé K4        
        }
       if(byteRead == '5'){
            Serial.println("Rele K1 desligado");
            digitalWrite(IN1, HIGH);               // desativa porta IN1        
        }
       if(byteRead == '6'){
            Serial.println("Rele K2 desligado");
            digitalWrite(IN2, HIGH);               // desativa porta IN2         
        }
       if(byteRead == '7'){
            Serial.println("Rele K3 desligado");
            digitalWrite(IN3, HIGH);               // desativa porta IN3         
        }
       if(byteRead == '8'){
            Serial.println("Rele K4 desligado");
            digitalWrite(IN4, HIGH);               // desativa porta IN4          
        }
    delay(2000); 
}
