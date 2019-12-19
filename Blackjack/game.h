#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "house.h"
#include "player.h"

class Game
{
    Deck deck;
    House house;
    std::vector<Player> players;
public:
    Game(const std::vector<std::string> &p_names);
    ~Game();
    void Play();
};//class Game

#endif // GAME_H
