/************************************************************
*                                                           *
*   Trabalho Prático - Cancela de Parque de Estacionamento  *
*                                                           *
*                    Haridian Sanz Lopes                    *
*                                                           *
************************************************************/
#include <Servo.h>

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

int IR_DATA_IN = 4;
int flagsensor = 0;

int contadorLugares = 30;
int contadorOcupados = 0;
int memoriaLugares = 30;
int memoriaOcupados = 0;

const int Cancela=10; // Pino do servomotor
Servo Motor1;

const int R_LED_IN=6; // LED vermelho de entrada
const int G_LED_IN=7; // LED verde de entrada
const int G_LED_OUT=8; // LED verde de saída
const int R_LED_OUT=9; // LED vermelho de saída

int SW_IN=2; // Botão de pressão de entrada para abrir a cancela
int VALOR_SW_IN; // variável para o valor do pino de abrir a cancela na entrada

int SW_OUT=5; // Botão de pressão de saída para abrir a cancela
int VALOR_SW_OUT; // variável para o valor do pino de abrir a cancela na saída

int m_leds=0; // memoria dos leads

int tempo=0;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
  pinMode (Cancela, OUTPUT);

  pinMode (R_LED_IN, OUTPUT);
  pinMode (G_LED_IN, OUTPUT);
  pinMode (G_LED_OUT, OUTPUT);
  pinMode (R_LED_OUT, OUTPUT);
    
  pinMode (SW_IN, INPUT_PULLUP);

  pinMode (SW_OUT, INPUT_PULLUP);

  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.begin (16,2);
  lcd.clear();

  //Teste para abrir e fechar a cancela
  Motor1.attach(Cancela); 
  Motor1.write (90);
  delay (1000);
  Motor1.write (0);

  //Teste para verificar que funciona o LCD
  lcd.setCursor(0,0);
  lcd.print("Parque de");
  lcd.setCursor (0,1);
  lcd.print("Estacionamento");
  delay (1000);
  lcd.clear();

  //Teste para verificar que funcionam os leds
  digitalWrite(G_LED_IN, HIGH);
  digitalWrite(G_LED_OUT, HIGH);
  digitalWrite(R_LED_IN, HIGH);
  digitalWrite(R_LED_OUT, HIGH);
  delay (1000);
  digitalWrite(G_LED_IN, LOW);
  digitalWrite(G_LED_OUT, LOW);
  digitalWrite(R_LED_IN, LOW);
  digitalWrite(R_LED_OUT, LOW);

  Serial.begin(9600);
}

void loop() {

  if (digitalRead(SW_IN) == LOW) // loop para o botão de entrada
  {
    if (contadorLugares >= 1 && contadorLugares <= memoriaLugares) 
    {
      digitalWrite(G_LED_IN, HIGH);
      digitalWrite(G_LED_OUT, LOW);
      digitalWrite(R_LED_IN, LOW);
      digitalWrite(R_LED_OUT, HIGH);

      Motor1.write(90);

      do
      {
        tempo++;
        delay (100);

        if (digitalRead(IR_DATA_IN) == HIGH && flagsensor==0) 
        {
        contadorLugares--;
        contadorOcupados++;
        flagsensor=1;
        }

        if (digitalRead(IR_DATA_IN) == LOW  && flagsensor==1)
        {
        Motor1.write(0);
        flagsensor=0;
        }

        if (flagsensor==0 && tempo>=100)
        {
        Motor1.write(0);
        flagsensor=0;
        }
      } while (tempo <=100 || flagsensor==1);

      flagsensor=0;
      tempo=0;

    } 
  }
    
  if (digitalRead(SW_IN) == HIGH && digitalRead(SW_OUT) == HIGH) 
    {
      digitalWrite(G_LED_IN, LOW);
      digitalWrite(G_LED_OUT, LOW);
      digitalWrite(R_LED_IN, HIGH);
      digitalWrite(R_LED_OUT, HIGH);
    }

  if (digitalRead(SW_OUT) == LOW) // loop para o botão de saída
  {
    if (contadorLugares >= 1 && contadorLugares <= memoriaLugares) 
    {
      digitalWrite(G_LED_IN, LOW);
      digitalWrite(G_LED_OUT, HIGH);
      digitalWrite(R_LED_IN, LOW);
      digitalWrite(R_LED_OUT, LOW);
      Motor1.write(90);

      do
      {
        tempo++;
        delay (100);

        if (digitalRead(IR_DATA_IN) == HIGH && flagsensor==0) 
        {
        contadorLugares++;
        contadorOcupados--;
        flagsensor=1;
        }

        if (digitalRead(IR_DATA_IN) == LOW  && flagsensor==1)
        {
        Motor1.write(0);
        flagsensor=0;
        }

        if (flagsensor==0 && tempo>=100)
        {
        Motor1.write(0);
        flagsensor=0;
        }
      } while (tempo <=100 || flagsensor==1);

      flagsensor=0;
      tempo=0;
    } 
  }
  
  // Mostrar os lugares disponíveis no Serial Monitor. Código adicionado para facilitar a configuração e verificação do lcd.print
  Serial.print("Disponíveis: ");
  Serial.println(contadorLugares);
  Serial.print("Ocupados: ");
  Serial.println(contadorOcupados);

  // Mostrar os lugares disponíveis no LCD
  lcd.setCursor(0,0);
  lcd.print("Disponiveis: " + String(contadorLugares));
  lcd.setCursor (0,1);
  lcd.print("Ocupados: " + String(contadorOcupados));
  lcd.print("  ");
}