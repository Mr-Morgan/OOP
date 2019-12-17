#include "genericplayer.h"

GenericPlayer::GenericPlayer()
{

}//GenericPlayer::GenericPlayer()

GenericPlayer::~GenericPlayer()
{

}//GenericPlayer::~GenericPlayer()

bool GenericPlayer::IsBoosted()
{
    return (GetValue() > BlackJack)? true : false;
}//bool GenericPlayer::IsBoosted()

void GenericPlayer::Bust()
{
    std::cout << "Player " << name << " is bust!\n";
}//void GenericPlayer::Bust()

std::ostream &operator<<(std::ostream &os, const GenericPlayer &gp)
{
    os << "Cards of the player " << gp.name << ":\n";
    for (Card* c : gp.hand) os << (*c);
    os << std::endl << "Score: " << gp.GetValue();
    return os;
}//std::ostream &operator<<(std::ostream &os, const GenericPlayer &gp)
