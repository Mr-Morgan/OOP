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

std::ostream &operator<<(std::ostream &os, Card &c)
{
    return c.GetVisible()? os << printSuit(c.GetSuit()) + ' ' << c.GetValue() << "; " : os << "XX; ";
}//std::ostream &operator<<(std::ostream &os, Card &c)
