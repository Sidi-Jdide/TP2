#pragma once

#include <Arduino.h>

class Bouton
{

public:
    int ObtenirEtatBoutonPistolet();
    int ObtenirEtatBoutonSimulation();
    Bouton(const unsigned  &p_pinBoutonPistolet,const unsigned  &p_pinBoutonSimulation );

private:
volatile mutable unsigned pinBoutonPistolet ;
volatile mutable unsigned pinBoutonSimulation;
};
