#include "PompeEssenceBase.h"
#include "Bouton.h"
byte valeurSegements[] = {
  0b11111100,//0
  0b01100000,//1
  0b11011010,//2
  0b11110010,//3
  0b01100110,//4
  0b10110110,//5
  0b10111110,//6
  0b11100000,//7
  0b11111110,//8
  0b11110110,//9
  0b11101110,//A
  0b00111110,//B
  0b10011100,//C
  0b01111010,//D
  0b10011110,//E
  0b10001110,//F
};


PompeEssenceBase::PompeEssenceBase(const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4,Bouton p_bouton)
    : m_pinD{p_pinD1, p_pinD2, p_pinD3, p_pinD4},m_bouton{p_bouton}
{
    
  this->m_bouton=p_bouton;
    for (size_t digitIndex = 0; digitIndex < 4; digitIndex++)
    {
        pinMode(this->m_pinD[digitIndex], OUTPUT);
    }
}

void PompeEssenceBase::Executer() 
{
    if(m_bouton.ObtenirEtatBoutonPistolet() == LOW && compteurLitreEssence < 9999 && prixEssence < 9999){
    PompeEnFonction();
  }
  this->AfficherNombreSurSegment(compteurLitreEssence);
  
  PompeEnArret();
}
void PompeEssenceBase::Afficher(int p_valeur, int p_digit) const
{
     byte valeursSegments = valeurSegements[p_valeur];
  
  if(p_digit == 1){
    //placer le bite à 1.
    valeursSegments |= 1;
  }
  
    for (int i = 0; i < 8; ++i) {
      digitalWrite(i + 6,
      (valeursSegments >> (7 - i)) & 1 ? HIGH : LOW);
    }
}


void PompeEssenceBase::PompeEnFonction() const
{
    ++this->compteurLitreEssence;
  	this->CalculPrixEssence();
}

void PompeEssenceBase::PompeEnArret() 
{
   
}
void PompeEssenceBase::GererTemps() 
{
   
}
void PompeEssenceBase::CalculPrixEssence() const
{
    this->compteurPrixEssence = compteurLitreEssence * 1.07;
  
  this->prixEssence = compteurPrixEssence + 0.5;
  Serial.println(prixEssence);

  if(compteurPrixEssence >= 9999){
  	this->prixEssence = 9999;
  }
}

void PompeEssenceBase::choixDigit(int p_digit) const
{
  for (size_t i = 0; i < 4; i++)
  {
    digitalWrite(this->m_pinD[i], HIGH);
  }
  digitalWrite(this->m_pinD[p_digit], LOW);
}
void PompeEssenceBase::AfficherNombreSurSegment(int p_nombre)
{

   unsigned int millier  = (p_nombre/1000);
  unsigned int centaine = ((p_nombre/100)%10);
  unsigned int dizaine  = ((p_nombre/10)%10);
  unsigned int unite    = (p_nombre%10);
  
  
  this->choixDigit(0);
  	this->Afficher(millier, 0);
	delay(time);
  
  choixDigit(1);
  	this->Afficher(centaine, 1);
	delay(time);
  
  this->choixDigit(2);
  	this->Afficher(dizaine, 2);
	delay(time);
  
  this->choixDigit(3);
  	this->Afficher(unite, 3);
	delay(time);
}

void PompeEssenceBase::reset(){
  for (size_t pin = 2; pin <= 5; ++pin) {
  	digitalWrite(pin, HIGH);
  }

  for (size_t pin = 6; pin <= 13; ++pin) {
  	digitalWrite(pin, LOW);
  }
}

void PompeEssenceBase::VerifierEtatBoutonBouton2()
{
    if(m_bouton.ObtenirEtatBoutonSimulation() == LOW){
  	this->compteurLitreEssence = 0;
    this->compteurPrixEssence  = 0;
    this->prixEssence = 0;
  }
}