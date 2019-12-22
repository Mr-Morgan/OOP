#include "deck.h"

Deck::Deck()
{
    hand.reserve(SizeOfStandardPack);
    Populate();
}//Deck::Deck()

Deck::~Deck()
{

}//Deck::~Deck()

void Deck::Populate()
{
    Clear();
    for (int st = clubs; st <= spades; ++st)
        for (int vl = ace; vl <= king; ++vl)
            Add(new Card(static_cast<Suit>(st), static_cast<Value>(vl)));
}//void Deck::Populate()

void Deck::Shuffle()
{
    std::random_shuffle(hand.begin(), hand.end());
}//void Deck::Shuffle()

void Deck::Deal(Hand &h)
{
    if(hand.empty()) {
        Populate();
        Shuffle();
        Deal(h);
    } else {
        h.Add(hand.back());
        hand.pop_back();
    }//if(hand.empty())
}//void Deck::Deal(Hand &h)

void Deck::AdditionalCards(GenericPlayer &gp)
{
    while(gp.IsHitting() && !gp.IsBoosted()) {
        Deal(gp);
        std::cout << gp << std::endl;
    }//while(gp.IsHitting() && !gp.IsBoosted())
    if(gp.IsBoosted()) gp.Bust();
}//void Deck::AddltionalCards(GenericPlayer &gp)
