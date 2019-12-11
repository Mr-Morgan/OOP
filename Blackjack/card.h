#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <strstream>

#define BlackJack 21

enum Suit { clubs, diamonds, hearts, spades };
enum Value { ace = 1, two, three, four, five, six, seven, eight, nine, ten = 10, jack = 10, queen = 10, king = 10 };

class Card
{
    Suit s;
    Value v;
    bool visible;
public:
    Card(Suit st, Value vl): s(st), v(vl), visible(false) {}
    void Flip() { visible = (!visible); }
    int GetValue() const { return v; }
    Suit GetSuit() const { return s; }
    bool GetVisible() const { return visible; }
};//class Card

std::ostream& operator<< (std::ostream& os, Card &c);


#endif // CARD_H
