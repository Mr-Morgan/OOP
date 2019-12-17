#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"

class Hand
{
protected:
    std::vector<Card*> hand;
public:
    Hand();
    void Add(Card* card);
    void Clear();
    int GetValue() const;
    void GetCardsData(std::ostream *os) const;
    virtual ~Hand();
};//class Hand

#endif // HAND_H
