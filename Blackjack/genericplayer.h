#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "hand.h"

class GenericPlayer : public Hand
{
protected:
    std::string name;
public:
    GenericPlayer();
    virtual ~GenericPlayer();
    virtual bool IsHitting() const = 0;
    bool IsBoosted();
    void Bust();
    friend std::ostream& operator<< (std::ostream& os, const GenericPlayer &gp);
};//class GenericPlayer : public Hand

#endif // GENERICPLAYER_H
