#include <Arduino.h>
//#define Led 5

//bool estado = 0;
const byte PinDeInterrupcion = 16;
volatile byte ContadorDeInterrupciones = 0;
int NumeroDeInterrupciones = 0;

void ICACHE_RAM_ATTR InterrupcionExterna();

void InterrupcionExterna()
{
  ContadorDeInterrupciones++;
  //estado = !estado;
}

void setup()
{
  Serial.begin(9600);
  //pinMode(Led, OUTPUT);
  pinMode(PinDeInterrupcion, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PinDeInterrupcion), InterrupcionExterna, FALLING);
}

void loop()
{
  //digitalWrite(Led, estado);
  if (ContadorDeInterrupciones > 0)
  {
    ContadorDeInterrupciones--;
    NumeroDeInterrupciones++;
    Serial.print("Numero de interrupciones: ");
    Serial.println(NumeroDeInterrupciones);
  }
}