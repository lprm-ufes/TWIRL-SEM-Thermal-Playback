#include "dht.h" //INCLUSÃO DE BIBLIOTECA
#include <Wire.h>
int IN1 = 4;                             // pino IN1 conectado porta D4 Arduino
int IN2 = 5;                             // pino IN2 conectado porta D5 Arduino
const int pinoDHT11 = A2; //PINO ANALÓGICO UTILIZADO PELO DHT11
dht DHT; //VARIÁVEL DO TIPO DHT

void setup()
{
  Wire.begin();
  Serial.begin(9600);                    // console serial 9600 Bps 
  pinMode(IN1, OUTPUT);                  // definições das portas IN1 e IN2 como portas de saidas 
  pinMode(IN2, OUTPUT);  
  digitalWrite(IN1, HIGH);               // desativa porta IN1 
  digitalWrite(IN2, HIGH);               // desativa porta IN2 
  delay(2000); //INTERVALO DE 2 SEGUNDO ANTES DE INICIAR
}
 
void loop()
{  
 // digitalWrite(IN2, HIGH);               // desativa porta IN2 
//  digitalWrite(IN1, LOW);                // acionamento relé K1 
//  Serial.println("Rele K1 acionado");    // print mensagem 
  //delay (30000);                          // atraso de 30 segundos
  digitalWrite(IN1, HIGH);               // desativa porta IN1
  digitalWrite(IN2, LOW);                // acionamento relé K2 
 // Serial.println("Rele K2 acionado");    // print mensagem
 // delay (30000);                          // atraso de 30 segundos  
  
  DHT.read11(pinoDHT11); //LÊ AS INFORMAÇÕES DO SENSOR
  Serial.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
  Serial.print("%"); //ESCREVE O TEXTO EM SEGUIDA
  Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.temperature,2); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
  Serial.println("°C"); //IMPRIME O TEXTO NA SERIAL
  delay(2000); 
}
