#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

#define BlackJack 21

enum Suit { clubs, diamonds, hearts, spades };
enum Value { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };

class Card
{
    Suit s;
    Value v;
    bool visible;
public:
    Card(Suit st, Value vl): s(st), v(vl), visible(true) {}
    void Flip();
    int GetValue() const;
    Suit GetSuit() const;
    bool GetVisible() const;
    friend std::ostream& operator<< (std::ostream& os, const Card &c);
};//class Card

#endif // CARD_H
