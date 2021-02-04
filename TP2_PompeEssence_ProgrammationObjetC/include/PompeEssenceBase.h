#pragma once
#include "Bouton.h"
#include <Arduino.h>

class PompeEssenceBase
{

public:
    void Afficher(int p_valeur, int p_digit)const;
    void Executer() ;
    void choixDigit(int p_digit) const ;
    void PompeEnFonction()const;
    void CalculPrixEssence()const;
    void reset();
    void AfficherNombreSurSegment(int p_nombre);
    void PompeEnArret();
    void VerifierEtatBoutonBouton2();
    void GererTemps(int p_compteur);
protected:
    PompeEssenceBase(const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4,Bouton p_bouton);
private:
    int m_pinD[4];

volatile mutable int time = 12;
volatile mutable int compteurLitreEssence = 0;
volatile mutable float compteurPrixEssence = 0;
volatile mutable int prixEssence = 0;
Bouton m_bouton;
};
