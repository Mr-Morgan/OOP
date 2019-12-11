#include "genericplayer.h"

void GenericPlayer::Bust()
{
    std::cout << "Player " << name << " is bust!\n";
}//void GenericPlayer::Bust()

std::ostream& operator<<(std::ostream& os, GenericPlayer &gpl)
{
    os << "Cards of the player " << gpl.name << ":\n";
    gpl.GetCardsData(&os);
    os << "Score: " << gpl.GetValue();
    return os;
}//std::ostream& operator<<(std::ostream& os, GenericPlayer &gpl)



