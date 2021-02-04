#pragma once

#include <Arduino.h>
#include "PompeEssenceBase.h"

class PompeEssence : public PompeEssenceBase
{
private:
  int m_pinSegments[8];

public:
    PompeEssence(const int& p_pinSegmentA, const int& p_pinSegmentB, const int& p_pinSegmentC, const int& p_pinSegmentD,
                           const int& p_pinSegmentE, const int& p_pinSegmentF, const int& p_pinSegmentG, const int& p_pinSegmentDP,
                           const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4,Bouton p_bouton);

};
