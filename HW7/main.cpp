#include <iostream>
#include <iomanip>
#include <memory>

/*
1.  Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. Перегрузите оператор вывода для данного класса.
    Создайте два "умных" указателя today и date. Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы
    доступа к полям класса Date, а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. Затем
    переместите ресурс, которым владеет укзаатель today в указатель date. Проверьте, являются ли нулевыми указатели today и date и
    выведите соответствующую информацию об этом в консоль.

2.  По условию предыдущей задачи создайте два умных указателя date1 и date2.
    ** Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой (сравнение
       происходит по датам). Функция должна вернуть более позднюю дату.
    ** Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
    Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.

3.  Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт. Класс Deck имеет 4 метода:

    - vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
    - void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL `random_shuffle`
    - vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
    - void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет
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

/*********************** Ex. 1 ****************************/
class Date
{
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 2019) : day(d), month(m), year(y) {}
    void setDay  (int d) { day = d;   }
    void setMonth(int m) { month = m; }
    void setYear (int y) { year = y;  }
    int getDay  () { return day;   }
    int getMonth() { return month; }
    int getYear () { return year;  }
    friend ostream &operator<< (ostream &os, const Date &d);
};//class Date

ostream &operator<<(ostream &os, const Date &d)
{
    return os << setfill('0') << setw(2) << d.day << '.' << setw(2)
              << d.month << '.' << setw(4) << d.year << endl;
}//ostream &operator<<(ostream &os, const Date &d)

/*********************** Ex. 2 ****************************/
Date comparison(const unique_ptr<Date> &d1, const unique_ptr<Date> &d2)
{
   if((d1->getYear() > d2->getYear())) return *d1;
   else if (d1->getYear() < d2->getYear()) return *d2;

   if((d1->getMonth() > d2->getMonth())) return *d1;
   else if (d1->getMonth() < d2->getMonth()) return *d2;

   if((d1->getDay() > d2->getDay())) return *d1;
   else if (d1->getDay() < d2->getDay()) return *d2;

   // d1 == d2
   return *d1;
}//Date &comparison(unique_ptr<Date> d1, unique_ptr<Date> d2)

void swapUnPtrDate(unique_ptr<Date> &d1, unique_ptr<Date> &d2)
{
//    swap(d1, d2);                                                   //Читер
    unique_ptr<Date> tmp = move(d1);
    d1 = move(d2);
    d2 = move(tmp);
}//void swapUnPtrDate(unique_ptr<Date> d1, unique_ptr<Date> d2)

int main()
{
    cout << "********************** Ex. 1 ***************************\n\n";
        unique_ptr<Date> today = make_unique<Date>();                                   //make_unique начиная с c++14?
        unique_ptr<Date> date;
        today->setDay(18);
        today->setMonth(12);
        today->setYear(2019);
        cout << "Today (get()): " << today->getDay() << '.' << today->getMonth() << '.' << today->getYear() << endl;
        cout << "Today (operator<<): " << *today;
        date = move(today);
        if(today == nullptr) cout << "today == nullptr";
        if(date == nullptr) cout << "date == nullptr";
    cout << "\n\n";

    cout << "********************** Ex. 2 ***************************\n\n";
        unique_ptr<Date> date1 = make_unique<Date>();
        unique_ptr<Date> date2 = make_unique<Date>(18,12,2019);
        cout << "date1: " << *date1 << "date2: " << *date2 << endl << comparison(date1, date2) << endl;
        swapUnPtrDate(date1, date2);
        cout << "date1: " << *date1 << "date2: " << *date2 << endl;
    cout << "\n\n";

    return 0;
}//int main()


