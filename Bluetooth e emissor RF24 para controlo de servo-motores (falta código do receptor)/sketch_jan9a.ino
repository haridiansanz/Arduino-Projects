/*********************************************************
*                                                        *
*      Trabalho Prático - Controlo de Servo-Motores      *
*                                                        *
*                                                        *
*                Haridian Sanz Lopes                     *
*                                                        *
*********************************************************/

/* Lógica: Utilizamos uma app no nosso telemóvel Android,
que envia uma letra para um módulo Bluetooth,
o Bluetooth recebe a letra e esta é enviada através de um emissor RF24.
Até aqui temos uma placa Arduino ligada ao Bluetooth e ao emissor,
O código apresentado é para esta parte.
É necessário mais um sketch e mais uma placa com o recetor e os servo-motores */

/* As aplicações para Android podem ser feitas em App MIT Inventor */

#include <SoftwareSerial.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

char letra;

RF24 radio(8, 9); // CE, CSN
const byte address[6] = "10101"; // Aqui inserimos o nosso endereço para conectar com o recetor
int vetor[2]; // Posição 0 para o servo 0 e posição 1 para o servo 2

SoftwareSerial mySerial (2,3); // 3=Rx e 2=Tx do Arduino. Depois é ao contrário no Bluetooth

void setup() {
  // put your setup code here, to run once:

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();

  Serial.begin (9600);
  mySerial.begin(9600); // já não que temos que desligar o Bluetooth para fazer o upload

}

void loop() {
  // put your main code here, to run repeatedly:
 if (mySerial.available ())
  {
    letra=mySerial.read(); //o que está a ler do Bluetooth
    Serial.println(vetor[0]);
    Serial.println(vetor[1]);
  }

  if (letra=='A')
  {
    if (vetor[0]>0)
    {
      vetor[0]--;
    }
  }
  
  if (letra=='B')
  {
    if (vetor[0]<180)
    {
      vetor[0]++;
    }
  }

  if (letra=='C')
  {
    if (vetor[0]<180)
    if (vetor[1]<180)
    {
      vetor[0]++;
      vetor[1]++;
    }
  }

  if (letra=='D')
  {
    if (vetor[1]>0)
    {
      vetor[1]--;
    }
  }

  if (letra=='E')
  {
    if (vetor[1]<180)
    {
      vetor[1]++;
    }
  }

  if (letra=='F')
  {
    if (vetor[0]>0)
    if (vetor[1]>0)    
    {
      vetor[0]--;
      vetor[1]--;
    }
  }

  if (letra=='G')
  {
    if (vetor[0]>0)
    if (vetor[1]<180)    
    {
      vetor[0]--;
      vetor[1]++;
    }
  }

    if (letra=='H')
  {
    if (vetor[0]<180)
    if (vetor[1]>0)    
    {
      vetor[0]++;
      vetor[1]--;
    }
  }

  radio.stopListening();
  radio.write (&vetor, sizeof (vetor));
}