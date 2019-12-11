#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"

class Hand
{
    std::vector<Card*> hand;
public:
    Hand() {}
    void Add(Card* card) { hand.push_back(card); }
    void Clear();
    int GetValue() const;
    void GetCardsData(std::ostream *os) const;
    virtual ~Hand() { Clear(); }
};//class Hand

#endif // HAND_H
