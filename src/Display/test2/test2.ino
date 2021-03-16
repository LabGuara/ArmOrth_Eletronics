#include "Adafruit_SSD1306.h"

Adafruit_SSD1306 screen(0x3C, 5, 4);

#define PINO_POTENCIOMETRO 15

int percProgress = 0;

int valor=0;

void setup() {
  // put your setup code here, to run once:
  screen.begin();

  screen.setFont(ArialMT_Plain_10);

  pinMode(PINO_POTENCIOMETRO, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  percProgress = map(analogRead(PINO_POTENCIOMETRO), 0, 4095, 0, 100);
  
  screen.clear();

  desenhaBarraProgresso();

  screen.display();

  delay(10);
}

void desenhaBarraProgresso(){
  screen.drawProgressBar(0,32,100,20, percProgress);
  
  screen.setTextAlignment(TEXT_ALIGN_CENTER);

  if(percProgress == 0){
    screen.drawString(64, 45, "Valor Mínimo");  
  }

  else if(percProgress == 100){
    screen.drawString(64, 45, "Valor Mínimo");  
  }


  
}
