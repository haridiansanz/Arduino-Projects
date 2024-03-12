#include <Servo.h>
#include <SoftwareSerial.h>

char letra;
int angulo=0;

SoftwareSerial mySerial (10,11); // 10 = Rx e 11=Tx do Arduino. Depois é ao contrário no Bluetooth
Servo motor;

void setup() {
  // put your setup code here, to run once:
  motor.attach(7);
  Serial.begin (9600);
  mySerial.begin(9600); // já não que temos que desligar o Bluetooth para fazer o upload
  //motor.write(90);
  //delay (1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available ())
  {
    letra=mySerial.read(); //o que está a ler do Bluetooth
    Serial.println(letra);
  }
  
  if (letra=='E')
  {
    if (angulo>0)
    {
      motor.write(angulo);
      angulo --;
      delay (100);
    }
  }
  
  if (letra=='D')
  {
    if (angulo<180)
    {
      motor.write(angulo);
      angulo ++;
      delay (100);
    }
  }

}
