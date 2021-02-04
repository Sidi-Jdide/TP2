
#include "PompeEssence.h"

PompeEssence::PompeEssence(const int &p_pinSegmentA, const int &p_pinSegmentB, const int &p_pinSegmentC, const int &p_pinSegmentD,
                                               const int &p_pinSegmentE, const int &p_pinSegmentF, const int &p_pinSegmentG, const int &p_pinSegmentDP,
                                               const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4,Bouton p_bouton)
    :PompeEssenceBase(p_pinD1, p_pinD2,  p_pinD3, p_pinD4,p_bouton),
      m_pinSegments{p_pinSegmentA, p_pinSegmentB, p_pinSegmentC, p_pinSegmentD,
                    p_pinSegmentE, p_pinSegmentF, p_pinSegmentG, p_pinSegmentDP}
{
    for (size_t segmentIndex = 0; segmentIndex < 8; ++segmentIndex)
    {
        pinMode(this->m_pinSegments[segmentIndex], OUTPUT);
    }
}


