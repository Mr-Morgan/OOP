#include <iostream>

/*
1.  Первые три задачи по теме "Шаблоны" взять из методички. (Не стал их копировать сюда, так как может форматирование испортиться).

2.  Написать перегрузку оператора вывода для класса Card. Если карта повернута рубашкой вверх (мы ее не видим), вывести ХХ, если мы
    ее видим, вывести масть и номинал карты.

3.  Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который
    обощенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который
    добавить поле name - имя игрока. Также добавить 3 метода:

    - IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
    - IsBoosted() - возвращает bool значение, есть ли у игрока перебор
    - Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

    Также для класса GenericPlayer написать перегрузку оператора вывода, который должен отображать имя игрока и его карты, а также
    общую сумму очков его карт.
*/

using namespace std;

/*********************** Ex. 1 ****************************/
template <typename T>
class Pair1
{
    T fir, sec;
public:
    Pair1(T f, T s) : fir(f), sec(s) {}
    T first() const { return fir; }
    T second() const { return sec; }
};//template <typename T> class Pair1

template <typename T, typename S>
class Pair
{
    T fir;
    S sec;
public:
    Pair(T f, S s) : fir(f), sec(s) {}
    T first() const { return fir; }
    S second() const { return sec; }
};//template <typename T, typename S> class Pair

template <typename U>
class Pair<string, U>
{
    string fir;
    U sec;
public:
    Pair(string f, U s) : fir(f), sec(s) {}
    string first() const { return fir; }
    U second() const { return sec; }
};//template <typename U> class Pair<string, U>

template <typename U>
class StringValuePair : public Pair<string, U>
{
public:
    StringValuePair(string f, U s) : Pair<string, U>(f, s) {}
};//template <typename U> class StringValuePair : public Pair<string, U>

/*********************** Ex. 2 ****************************/

int main()
{
    cout << "********************** Ex. 1 ***************************\n\n";
        Pair1<int> p1(6, 9);
        cout << "Pair: " << p1.first() << ' ' << p1.second() << endl;
        const Pair1<double> p2(3.4, 7.8);
        cout << "Pair: " << p2.first() << ' ' << p2.second() << endl;

        Pair<int, double> p3(6, 7.8);
        cout << "Pair: " << p3.first() << ' ' << p3.second() << endl;
        const Pair<double, int> p4(3.4, 5);
        cout << "Pair: " << p4.first() << ' ' << p4.second() << endl;

        StringValuePair<int> svp("Amazing", 7);
        cout << "Pair: " << svp.first() << ' ' << svp.second() << endl;
    cout << "\n\n";




    return 0;
}//int main()
