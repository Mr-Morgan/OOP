#include "hand.h"

void Hand::Clear()
{
    for (Card* c : hand) delete c;
    hand.clear();
}//void Hand::Clear()

int Hand::GetValue() const
{
    int score = 0, ace_count = 0;
    for (Card* card : hand)
        if(card->GetValue() == Value::ace) ace_count++;
        else score += card->GetValue();
    for (int i = 0; i < ace_count; ++i)
        if (score <= 10) score += 11;
        else score++;
    return score;
}//int Hand::GetValue() const

void Hand::GetCardsData(std::ostream *os) const
{
        for (Card* c : hand) *os << (*c);
        *os << std::endl;
}//void Hand::GetCardsData(std::ostream *os) const
