#include "player.h"

Player::Player(const std::string &n)
{
    name = n;
}//Player::Player()

Player::~Player()
{

}//Player::~Player()

bool Player::IsHitting() const
{
    std::cout << name << ", do you need another card?(y/n): ";
    char answer = '?';
    std::cin >> answer;
    return (answer == 'y' || answer == 'Y');
}//bool Player::IsHitting() const

void Player::Win() const
{
    std::cout << "The player " << name << " won!\n";
}//void Player::Win() const

void Player::Lose() const
{
    std::cout << "The player " << name << " lost!\n";
}//void Player::Lose() const

void Player::Push() const
{
    std::cout << "Player " << name << " played a draw!\n";
}//void Player::Push() const
