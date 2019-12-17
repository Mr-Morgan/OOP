#include "house.h"

House::House(const std::string &n)
{
    name = n;
}//House::House()

House::~House()
{

}//House::~House()

bool House::IsHitting() const
{
    return (GetValue() <= DEALER_MAX);
}//bool House::IsHitting() const

void House::FlipFirstCard()
{
    if(hand.empty()) std::cout << "The dealer has no cards.\n";
    else hand[0]->Flip();
}//void House::FlipFirstCard()
