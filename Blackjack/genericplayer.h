#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "hand.h"

class GenericPlayer : public Hand
{
    std::string name;
public:
    GenericPlayer() {}
    virtual bool IsHitting() = 0;
    bool IsBoosted() { return (GetValue() > BlackJack)? true : false; }
    void Bust();
    friend std::ostream& operator<< (std::ostream& os, GenericPlayer &gpl);
};//class GenericPlayer : public Hand

#endif // GENERICPLAYER_H
