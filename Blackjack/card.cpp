#include "card.h"

char printSuit(Suit s)
{
    switch (s) {
    case clubs:     return 'C';
    case diamonds:  return 'D';
    case hearts:    return 'H';
    case spades:    return 'S';
    }//switch (s)
}//char printSuit(Suit s)

char printValue(Value v)
{
    switch (v) {
    case ace:   return 'A';
    case jack:  return 'J';
    case queen: return 'Q';
    case king:  return 'K';
    default: break;
    }//switch (v)
}//char printValue(Value v)

std::ostream &operator<<(std::ostream &os, const Card &c)
{
    if (c.GetVisible()) {
        os << printSuit(c.s);
        if (c.v > ten || c.v == ace) os << printValue(c.v);
        else os << c.v;
        os << "; ";
    } else os << "XX; ";
    return os;
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
