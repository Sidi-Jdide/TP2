#include "Bouton.h"

Bouton::Bouton(const unsigned  &p_pinBoutonPistolet,const unsigned &p_pinBoutonSimulation )

{

    this->pinBoutonPistolet=p_pinBoutonPistolet;
    this->pinBoutonSimulation=p_pinBoutonSimulation;
}

int Bouton::ObtenirEtatBoutonPistolet()
{
  int etatBouton1 = analogRead(this->pinBoutonPistolet);
  return etatBouton1;
}

int Bouton::ObtenirEtatBoutonSimulation()
{
  int etatBouton2 = analogRead(this->pinBoutonSimulation);
  return etatBouton2;
}