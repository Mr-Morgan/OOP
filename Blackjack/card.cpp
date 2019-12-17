#include "card.h"

std::string printSuit(Suit s)
{
    switch (s) {
    case clubs:     return "Clubs";
    case diamonds:  return "Diamonds";
    case hearts:    return "Hearts";
    case spades:    return "Spades";
    }//switch (s)
}//std::string printSuit(Suit s)

std::ostream &operator<<(std::ostream &os, const Card &c)
{
    return c.GetVisible()? os << printSuit(c.s) + ' ' << c.v << "; " : os << "XX; ";
}//std::ostream &Card::operator<<(std::ostream &os, const Card &c)

void Card::Flip()
{
    visible = (!visible);
}//void Card::Flip()

int Card::GetValue() const
{
    return v;
}//int Card::GetValue() const

Suit Card::GetSuit() const
{
    return s;
}//Suit Card::GetSuit() const

bool Card::GetVisible() const
{
    return visible;
}//bool Card::GetVisible() const
