#ifndef PLAYER_H
#define PLAYER_H

#include "genericplayer.h"

class Player : public GenericPlayer
{
public:
    Player(const std::string &n = "");
    virtual ~Player();
    virtual bool IsHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};//class Player : public GenericPlayer

#endif // PLAYER_H
