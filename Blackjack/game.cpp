#include "game.h"

Game::Game(const std::vector<std::string> &p_names)
{
    for (std::string name: p_names)
      players.push_back(Player(name));
    srand(static_cast<unsigned>(time(nullptr)));
    deck.Populate();
    deck.Shuffle();
}//Game::Game()

Game::~Game()
{

}//Game::~Game()

void Game::Play()
{
    for (int i = 0; i < 2; ++i) {
        for (Player &p : players) deck.Deal(p);
        deck.Deal(house);
    }//for (int i = 0; i < 2; ++i)
    house.FlipFirstCard();

    for (Player &p : players)
        std::cout << p << std::endl;
    std::cout << house << std::endl;

    for (Player &p : players)
        deck.AdditionalCards(p);
    house.FlipFirstCard();

    std::cout << house << std::endl;
    deck.AdditionalCards(house);

    if (house.IsBoosted()) {
        for (Player &p : players)
            if (!p.IsBoosted()) p.Win();
    } else {
        for (Player &p : players)
            if (!p.IsBoosted()) {
                if (p.GetValue() > house.GetValue()) p.Win();
                else if (p.GetValue() == house.GetValue()) p.Push();
                else p.Lose();
            }//if (!p.IsBoosted())
    }//if (house.IsBoosted())

    for (Player &p : players) p.Clear();
    house.Clear();
}//void Game::Play()
