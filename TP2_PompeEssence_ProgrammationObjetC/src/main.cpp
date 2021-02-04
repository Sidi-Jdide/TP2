#include <Arduino.h>
#include "Bouton.h"
#include "PompeEssence.h"


const int pinD1 = 2;
const int pinD2 = 3;
const int pinD3 = 4;
const int pinD4 = 5;
const unsigned pinPoutonPistolet = A0;
const unsigned pinPoutonSimulation = A1;


Bouton btn(pinPoutonPistolet,pinPoutonSimulation);

PompeEssence pompeEssence(6, 7, 8, 9,
                           10, 11, 12, 13,
                           pinD1, pinD2, pinD3, pinD4,btn);


void setup()
{
  Serial.begin(9600);


}

void loop()
{

  pompeEssence.Executer();

}
