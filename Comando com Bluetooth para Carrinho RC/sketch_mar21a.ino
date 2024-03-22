#include <SoftwareSerial.h>

const int botao_avancar=5;
const int botao_stop=6;
const int botao_matras=7;
const int botao_esq=8;
const int botao_centro=9;
const int botao_dta=10;

void setup() {
pinMode (botao_avancar, INPUT_PULLUP);
pinMode (botao_stop, INPUT_PULLUP);
pinMode (botao_matras, INPUT_PULLUP);
pinMode (botao_esq, INPUT_PULLUP);
pinMode (botao_centro, INPUT_PULLUP);
pinMode (botao_dta, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  if (digitalRead(botao_avancar) == LOW){
    Serial.write('A');
  }
  
  if (digitalRead(botao_stop) == LOW){
    Serial.write('F');
  }

  if (digitalRead(botao_matras) == LOW){
    Serial.write('E');
  }

  if (digitalRead(botao_esq) == LOW){
    Serial.write('D');
  }

  if (digitalRead(botao_centro) == LOW){
    Serial.write('B');
  }

  if (digitalRead(botao_dta) == LOW){
    Serial.write('C');
  }

  if (digitalRead(botao_avancar) == LOW && digitalRead(botao_centro) == LOW){
    do {
      Serial.write('G');
    } while (digitalRead(botao_avancar) == LOW && digitalRead(botao_centro) == LOW);
  }

  if (digitalRead(botao_avancar) == LOW && digitalRead(botao_dta) == LOW){
    do {
      Serial.write('H');
    } while (digitalRead(botao_avancar) == LOW && digitalRead(botao_dta) == LOW);
  }

  if (digitalRead(botao_avancar) == LOW && digitalRead(botao_esq) == LOW){
    do {
      Serial.write('I');
    } while (digitalRead(botao_avancar) == LOW && digitalRead(botao_esq) == LOW);
  }

  if (digitalRead(botao_matras) == LOW && digitalRead(botao_dta) == LOW){
    do {
      Serial.write('J');
    } while (digitalRead(botao_matras) == LOW && digitalRead(botao_dta) == LOW);
  }

  if (digitalRead(botao_matras) == LOW && digitalRead(botao_esq) == LOW){
    do {
      Serial.write('K');
    } while (digitalRead(botao_matras) == LOW && digitalRead(botao_esq) == LOW);
  }

  if (digitalRead(botao_matras) == LOW && digitalRead(botao_centro) == LOW){
    do {
      Serial.write('L');
    } while (digitalRead(botao_matras) == LOW && digitalRead(botao_centro) == LOW);
  }

  if (digitalRead(botao_stop) == LOW && digitalRead(botao_dta) == LOW){
    do {
      Serial.write('M');
    } while (digitalRead(botao_stop) == LOW && digitalRead(botao_dta) == LOW);
  }

  if (digitalRead(botao_stop) == LOW && digitalRead(botao_esq) == LOW){
    do {
      Serial.write('N');
    } while (digitalRead(botao_stop) == LOW && digitalRead(botao_esq) == LOW);
  }

  if (digitalRead(botao_stop) == LOW && digitalRead(botao_centro) == LOW){
    do {
      Serial.write('O');
    } while (digitalRead(botao_stop) == LOW && digitalRead(botao_centro) == LOW);
  }

}
