#include <iostream>
#include "game.h"

/*
                                                    *******
                                                    * HW7 *
                                                    *******

3.  Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт. Класс Deck имеет 4 метода:

    - void Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
    - void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL `random_shuffle`
    - void Deal (Hand& aHand) - метод, который раздает в руку одну карту
    - void AdditionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет
      их получать

    ** Обратите внимание на применение полиморфизма. В каких методах применяется этот принцип ООП?

4.  Реализовать класс Game, который представляет собой основной процесс игры. У этого класса будет 3 поля:

    - колода карт,
    - рука дилера,
    - вектор игроков.

    Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков. В конструкторе должна
    создаться колода карт и перемешаться.

    Также класс имеет один метод play(). В этом методе раздаются каждому игроку по две стартовые карты, а первая карта дилера прячется.
    Далее выводится на экран информация о картах каждого игра, в т.ч. и для дилера. Затем раздаются игрокам дополнительные карты. Потом
    показывается первая карта дилера и дилер набирает карты, если ему надо. После этого выводится сообщение, кто победил, а кто проиграл.
    В конце руки всех игроков очищаются.

5.  Написать функцию main() к игре Блекджек. В этой функции вводятся имена игроков. Создается объект класса Game и запускается игровой
    процесс. Предусмотреть возможность повторной игры.
*/

using namespace std;

vector<string> setNamesOfPlayers(istream &is, ostream &os)
{
    vector<string> n;
    os << "Please enter the number of players: ";
    unsigned numb = 0;
    is >> numb;
    n.reserve(numb);
    string name = "???";
    for (unsigned i = 0; i < numb; ++i) {
        os << "Please enter a player name (" << i+1 << "): ";
        is >> name;
        n.push_back(name);
    }//for (unsigned i = 0; i < numb; ++i)
    return n;
}//vector<string> &setNamesOfPlayers(istream &is, ostream &os)

int main()
{
    cout << "\tWelcome to the game BlackJack!\n\n";
    vector<string> names = setNamesOfPlayers(cin, cout);
    Game game(names);

    for (char a = 'y'; (a == 'y' || a == 'Y'); cin >> a) {
        cout << "\n\tGame begins!\n\n";
        game.Play();
        cout << "The game is over, do you want to repeat? (y/n): ";
    }//for (char a = 'y'; (a == 'y' && a == 'Y'); cin >> a)

    return 0;
}//int main()

