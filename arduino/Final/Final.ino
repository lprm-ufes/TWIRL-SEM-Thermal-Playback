#include <Wire.h>
int IN1 = 3;                             // pino IN1 conectado porta D2 Arduino
int IN2 = 2;                             // pino IN2 conectado porta D3 Arduino
int IN3 = 4;                             // pino IN1 conectado porta D4 Arduino
int IN4 = 5;                             // pino IN2 conectado porta D5 Arduino
boolean cmdComplete = false;
String command = "";



void setup()
{
  Serial.begin(9600);                    // console serial 9600 Bps 
  pinMode(IN1, OUTPUT);                  // definições das portas IN1 ate IN4 como portas de saidas 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);  
  
  digitalWrite(IN1, HIGH);               // desativa porta IN1 
  digitalWrite(IN2, HIGH);               // desativa porta IN2 
  digitalWrite(IN3, HIGH);               // desativa porta IN3 
  digitalWrite(IN4, HIGH);               // desativa porta IN4
}
 
void loop(){  
  if (cmdComplete){
    switch(command[0]) {    
      case 'L':
        fog();
       break;
      case 'V': 
        hot();
      break;
      default : break;
    }
    cmdComplete = false;
    command = "";
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    if (inChar == '.') {
      cmdComplete = true;
    } else {
      command += inChar;
    }
  }
}


  // V* vibration control (hot wind)
  // VIX. vibrator device I with intensity X (0 until 255)
void hot(){
  int intensity = 0; 
  intensity = command[2];
  if (intensity < 0)
    intensity = intensity + 256;
  if(intensity > 0){
            digitalWrite(IN1, LOW); 
			digitalWrite(IN2, LOW);                // acionamento relé K1 e K2 
    }
  if(intensity == 0){
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, HIGH); 			  // desativa K1 e K2        
    }
	   
}	   


  // L* LED control (cold fog)
  // LICRGB. turn on LED at index I, until C, where R = red, G = green, B = blue
void fog(){
  if (command.length() == 6){
    int ledIndex, count, red, green, blue = 0; 
    ledIndex = command[1]; 
    count = command[2];
    red = command[3];
    green = command[4];
    blue = command[5];
    if (red < 0)
      red = red + 256;
    if (green < 0)
      green = green + 256;
    if (blue < 0)
      blue = blue + 256;
	if(blue > 0){
		digitalWrite(IN3, LOW);             
		digitalWrite(IN4, LOW);               // acionamento relé K3 e K4     
	}
	if(blue == 0){
		digitalWrite(IN3, HIGH);
		digitalWrite(IN4, HIGH);              // desativa porta K3 e K4         
	}

  }
}