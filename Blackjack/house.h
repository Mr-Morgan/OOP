#ifndef HOUSE_H
#define HOUSE_H

#include "genericplayer.h"

#define DEALER_MAX 16

class House : public GenericPlayer
{
public:
    House(const std::string &n = "Dealer");
    virtual ~House();
    virtual bool IsHitting() const;
    void FlipFirstCard();
};//class House : public GenericPlayer

#endif // HOUSE_H
