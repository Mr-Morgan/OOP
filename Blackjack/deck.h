#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include "genericplayer.h"

#define SizeOfStandardPack 52

class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand &h);
    void AdditionalCards (GenericPlayer& gp);
};//class Deck : public Hand

#endif // DECK_H
