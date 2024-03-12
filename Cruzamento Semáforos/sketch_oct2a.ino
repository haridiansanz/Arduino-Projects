/********************************************
*                                           *
*        Trabalho Prático - Semáforo        *
*            Haridian Sanz Lopes            *
*                                           *
********************************************/

// Entrada 1
int ledvermelho=3;
int ledamarelo=4;
int ledverde=5;
int ledvermelhowalk=10;
int ledverdewalk=9;
int botao=2;

// Entrada 3
int xledvermelho=3;
int xledamarelo=4;
int xledverde=5;
int xledvermelhowalk=10;
int xledverdewalk=9;
int xbotao=2;

// Entrada 2
int doisledvermelho=6;
int doisledamarelo=7;
int doisledverde=8;
int doisledvermelhowalk=11;
int doisledverdewalk=12;
int doisbotao=13;

// Entrada 4
int quatroledvermelho=6;
int quatroledamarelo=7;
int quatroledverde=8;
int quatroledvermelhowalk=11;
int quatroledverdewalk=12;
int quatrobotao=13;

int tempo=0;

void setup()
{
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledamarelo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledvermelhowalk, OUTPUT);
  pinMode(ledverdewalk, OUTPUT); 
  pinMode(botao, INPUT_PULLUP);
  
  pinMode(xledvermelho, OUTPUT);
  pinMode(xledamarelo, OUTPUT);
  pinMode(xledverde, OUTPUT);
  pinMode(xledvermelhowalk, OUTPUT);
  pinMode(xledverdewalk, OUTPUT); 
  pinMode(xbotao, INPUT_PULLUP);

  pinMode(doisledvermelho, OUTPUT);
  pinMode(doisledamarelo, OUTPUT);
  pinMode(doisledverde, OUTPUT);
  pinMode(doisledvermelhowalk, OUTPUT);
  pinMode(doisledverdewalk, OUTPUT); 
  pinMode(doisbotao, INPUT_PULLUP);

  pinMode(quatroledvermelho, OUTPUT);
  pinMode(quatroledamarelo, OUTPUT);
  pinMode(quatroledverde, OUTPUT); 
  pinMode(quatroledvermelhowalk, OUTPUT);
  pinMode(quatroledverdewalk, OUTPUT);
  pinMode(quatrobotao, INPUT_PULLUP);
}

void loop()
 {
  tempo++;
  delay (100);

   if (tempo > 0 && tempo < 150)
   {
     // de 0 a 15 segundos temos ligados: (15 segundos)
    digitalWrite(ledverde, HIGH);
    digitalWrite (xledverde, HIGH);
    digitalWrite (ledvermelhowalk, HIGH);
    digitalWrite (xledvermelhowalk, HIGH);
    digitalWrite (doisledvermelho, HIGH);
    digitalWrite (quatroledvermelho, HIGH);
    digitalWrite (doisledverdewalk, HIGH);
    digitalWrite (quatroledverdewalk, HIGH);

  // Nesta sequência temos desligados:
    digitalWrite(ledvermelho, LOW);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(xledvermelho, LOW);
    digitalWrite(xledamarelo, LOW);
    digitalWrite(ledverdewalk, LOW);
    digitalWrite(xledverdewalk, LOW);
    digitalWrite(doisledamarelo, LOW);
    digitalWrite(doisledverde, LOW);
    digitalWrite(doisledvermelhowalk, LOW);
    digitalWrite(quatroledamarelo, LOW);
    digitalWrite(quatroledverde, LOW);
    digitalWrite(quatroledvermelhowalk, LOW);
   }

  if (tempo>= 150 && tempo < 180)
  {
    // de 15 a 18 segundos temos ligados (3 segundos)
    digitalWrite(ledamarelo, HIGH);
    digitalWrite(xledamarelo, HIGH);
    digitalWrite(ledvermelhowalk, HIGH);
    digitalWrite(xledvermelhowalk, HIGH);
    digitalWrite(doisledvermelho, HIGH);
    digitalWrite(quatroledvermelho, HIGH);
    digitalWrite(doisledverdewalk, HIGH);
    digitalWrite(quatroledverdewalk, HIGH);

   // Nesta sequência temos desligados:
    digitalWrite(ledverde, LOW);
    digitalWrite(xledverde, LOW);
    digitalWrite(ledvermelho, LOW);
    digitalWrite(xledvermelho, LOW);
    digitalWrite(ledverdewalk, LOW);
    digitalWrite(xledverdewalk, LOW);
    digitalWrite(doisledamarelo, LOW);
    digitalWrite(doisledverde, LOW);
    digitalWrite(doisledvermelhowalk, LOW);
    digitalWrite(quatroledamarelo, LOW);
    digitalWrite(quatroledverde, LOW);
    digitalWrite(quatroledvermelhowalk, LOW);
  }

  if (tempo>= 180 && tempo < 200)
  {

  // de 18 a 20 segundos temos ligados: (2 segundos)
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(xledvermelho, HIGH);
    digitalWrite(doisledvermelho, HIGH);
    digitalWrite(quatroledvermelho, HIGH);
    digitalWrite(doisledvermelhowalk, HIGH);
    digitalWrite(quatroledvermelhowalk, HIGH);
    digitalWrite(ledvermelhowalk, HIGH);
    digitalWrite(xledvermelhowalk, HIGH);

  // Nesta sequência temos desligados:
    digitalWrite(ledverde, LOW);
    digitalWrite(xledverde, LOW);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(xledamarelo, LOW);
    digitalWrite(ledvermelhowalk, LOW);
    digitalWrite(xledvermelhowalk, LOW);
    digitalWrite(ledverdewalk, LOW);
    digitalWrite(xledverdewalk, LOW);
    digitalWrite(doisledamarelo, LOW);
    digitalWrite(doisledverde, LOW);
    digitalWrite(quatroledamarelo, LOW);
    digitalWrite(quatroledverde, LOW);
    digitalWrite(doisledverdewalk, LOW);
    digitalWrite(quatroledverdewalk, LOW);
  }

  if (tempo>= 200 && tempo < 350)
  {
  
  // de 20 a 35 segundos temos ligados:
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(xledvermelho, HIGH);
    digitalWrite(ledverdewalk, HIGH);
    digitalWrite(xledverdewalk, HIGH);
    digitalWrite(doisledverde, HIGH);
    digitalWrite(doisledvermelhowalk, HIGH);
    digitalWrite(quatroledverde, HIGH);
    digitalWrite(quatroledvermelhowalk, HIGH);

  // Nesta sequência temos desligados:
    digitalWrite(ledverde, LOW);
    digitalWrite(xledverde, LOW);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(xledamarelo, LOW);
    digitalWrite(ledvermelhowalk, LOW);
    digitalWrite(xledvermelhowalk, LOW);
    digitalWrite(doisledvermelho, LOW);
    digitalWrite(doisledamarelo, LOW);
    digitalWrite(doisledverdewalk, LOW);
    digitalWrite(quatroledvermelho, LOW);
    digitalWrite(quatroledamarelo, LOW);
    digitalWrite(quatroledverdewalk, LOW);

  }

  if (tempo>= 350 && tempo < 380)
  {

  // de 35 a 38 segundos temos ligados:
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(xledvermelho, HIGH);
    digitalWrite(ledverdewalk, HIGH);
    digitalWrite(xledverdewalk, HIGH);
    digitalWrite(doisledamarelo, HIGH);
    digitalWrite(doisledvermelhowalk, HIGH);
    digitalWrite(quatroledamarelo, HIGH);
    digitalWrite(quatroledvermelhowalk, HIGH);

  // Nesta sequência temos desligados:
    digitalWrite(ledverde, LOW);
    digitalWrite(xledverde, LOW);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(xledamarelo, LOW);
    digitalWrite(ledvermelhowalk, LOW);
    digitalWrite(xledvermelhowalk, LOW);
    digitalWrite(doisledvermelho, LOW);
    digitalWrite(doisledverde, LOW);
    digitalWrite(doisledverdewalk, LOW);
    digitalWrite(quatroledvermelho, LOW);
    digitalWrite(quatroledverde, LOW);
    digitalWrite(quatroledverdewalk, LOW);

  }

  if (tempo>= 380 && tempo <= 400)
  {
  
  // de 38 a 40 segundos temos ligados:
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(xledvermelho, HIGH);
    digitalWrite(doisledvermelho, HIGH);
    digitalWrite(quatroledvermelho, HIGH);
    digitalWrite(quatroledvermelhowalk, HIGH);
    digitalWrite(doisledvermelhowalk, HIGH);
    digitalWrite(ledvermelhowalk, HIGH);
    digitalWrite(xledvermelhowalk, HIGH);

  // Nesta sequência temos desligados:
    digitalWrite(ledverde, LOW);
    digitalWrite(xledverde, LOW);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(xledamarelo, LOW);
    digitalWrite(ledvermelhowalk, LOW);
    digitalWrite(xledvermelhowalk, LOW);
    digitalWrite(doisledamarelo, LOW);
    digitalWrite(doisledverde, LOW);
    digitalWrite(quatroledamarelo, LOW);
    digitalWrite(quatroledverde, LOW);
    digitalWrite(doisledverdewalk, LOW);
    digitalWrite(quatroledverdewalk, LOW);
    digitalWrite(ledverdewalk, LOW);
    digitalWrite(xledverdewalk, LOW);

  }

  if (tempo ==400)
  {
  tempo=0;
  }

  // Código para mudar a sequência ao carregar os botoes das passadeiras
  if (digitalRead(botao) == LOW)
    {
      if (tempo>0 && tempo <= 130) 
        {
        tempo = 130;
        }
    }

  if (digitalRead(xbotao) == LOW)
    {
      if (tempo>0 && tempo <= 130) 
      {
      tempo = 130;
      }
    }

  if (digitalRead(doisbotao) == LOW)
    {
      if (tempo>=200 && tempo <= 330) 
        {
        tempo = 330;
        }
    }

  if (digitalRead(quatrobotao) == LOW)
    {
      if (tempo>=200 && tempo <= 330) 
      {
      tempo = 330;
      }
    }
 }