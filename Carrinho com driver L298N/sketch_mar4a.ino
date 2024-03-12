/*********************************************************
*                                                        *
*           Controlo Remoto Carrinho STEAM               *
*                                                        *
*                                                        *
*                Haridian Sanz Lopes                     *
*                                                        *
*********************************************************/
#include <SoftwareSerial.h>
#include <Servo.h>

const int pinENB = 11;
const int pinIN3=9;
const int pinIN4=12;
const int pinMotorB[3] = { pinIN3, pinIN4, pinENB };

const int speed=100;    //velocidade de giro 80% (200/255)

const int servoPin=3;
Servo servoMotor;

char letra;

void moveForward(const int pinMotorB[3])
{
digitalWrite(pinMotorB[0], HIGH);
digitalWrite(pinMotorB[1], LOW);
analogWrite(pinMotorB[2], speed);
}
void moveBackward(const int pinMotorB[3])
{
digitalWrite(pinMotorB[0], LOW);
digitalWrite(pinMotorB[1], HIGH);
analogWrite(pinMotorB[2], speed);
}
void fullStop(const int pinMotorB[3])
{
digitalWrite(pinMotorB[0], LOW);
digitalWrite(pinMotorB[1], LOW);
analogWrite(pinMotorB[2], 0);
}

void setup() {
  pinMode(pinENB, OUTPUT);
  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  servoMotor.attach(servoPin); // Inicializar o microservomotor
  Serial.begin (9600);
}

void loop() {
  if (Serial.available ())
  {
    letra=Serial.read(); //o que está a ler do Bluetooth
    Serial.println(servoPin);
    Serial.println(pinIN3);
    Serial.println(pinIN4);
  }
// Primeiro processamos os movimentos do servo
  if (letra=='B') // C em valor 1 com o resto de botões a 0: Centraliza o carrinho.
  {
    servoMotor.write(90);
  }
  if (letra=='C') // D em valor 1 com o resto de botões a 0: Vira o carrinho para a direita.
  {
    servoMotor.write(95);
  }
  if (letra=='D') // E em valor 1 com o resto de botões a 0: Vira o carrinho para a esquerda.
  {
    servoMotor.write(80);
  }
// Depois processamos os movimentos do motor
  if (letra=='A') // Avançar em valor 1 com o resto de botões a 0: Movimenta o carrinho para frente.
  {
      moveForward(pinMotorB);
  }
  if (letra=='E') // Marcha-atrás em valor 1 com o resto de botões a 0: Faz o carrinho mover-se para trás.
  {
      moveBackward(pinMotorB);
  }
  if (letra=='F') // Stop em 1 com o resto de botões a 0: Interrompe qualquer movimento do carrinho.
  {
      fullStop(pinMotorB);
  }
// Movimentos com servomotor e motor ao mesmo tempo
  if (letra=='G') // Avançar e C com valor 1. Resto de botões a 0: Movimenta o carrinho para frente e centraliza.
  {
      servoMotor.write(90);
      moveForward(pinMotorB);
  }
  if (letra=='H') // Avançar e D com valor 1. Resto de botões a 0: Movimenta o carrinho para frente e gira para a direita.
  {
      servoMotor.write(95);
      moveForward(pinMotorB);
  }
  if (letra=='I') // Avançar e E em 1 com o resto de botões a 0: Movimenta o carrinho para frente e gira para a esquerda.
  {
      servoMotor.write(80);
      moveForward(pinMotorB);
  }
  if (letra=='J') // Marcha-atrás e D em 1 com o resto de botões a 0: Move o carrinho para trás e gira para a direita.
  {
      servoMotor.write(95);
      moveBackward(pinMotorB);
  }
  if (letra=='K') // Marcha-atrás e E em 1 com o resto de botões a 0: Move o carrinho para trás e gira para a esquerda.
  {
      servoMotor.write(80);
      moveBackward(pinMotorB);
  }
  if (letra=='L') // Marcha-atrás e C em 1 com o resto de botões a 0: Move o carrinho para trás e centraliza.
  {
      servoMotor.write(90);
      moveBackward(pinMotorB);
  }
  if (letra=='M') // Stop e D em 1 com o resto de botões a 0: Interrompe o movimento e vira o carrinho para a direita.
  {
      servoMotor.write(95);
      fullStop(pinMotorB);
  }
  if (letra=='N') // Stop e E em 1 com o resto de botões a 0: Interrompe o movimento e vira o carrinho para a esquerda.
  {
      servoMotor.write(80);
      fullStop(pinMotorB);
  }
  if (letra=='O') // Stop e C em 1 com o resto de botões a 0: Interrompe o movimento e centraliza o carrinho.
  {
      servoMotor.write(90);
      fullStop(pinMotorB);
  }
      }