#include <iostream>
#include <stdexcept>

/*
2.  Написать класс ​ Ex​, хранящий вещественное число ​ x и имеющий конструктор по
    вещественному числу, инициализирующий ​x значением параметра.
    Написать класс ​ Bar​, хранящий вещественное число​ y (конструктор по умолчанию инициализирует
    его нулем) и имеющий метод ​set с единственным вещественным параметром a. Если ​ y + a > 100​,
    возбуждается исключение типа Ex с данными ​ ay​ , иначе в y заносится значение ​ a​. В функции
    main завести переменную класса ​ Bar и в цикле в блоке ​ try вводить с клавиатуры целое ​n.
    Использовать его в качестве параметра метода ​ set до тех пор, пока не будет введено 0.
    В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
*/

using namespace std;

/*********************** Ex. 2 ****************************/
class Ex
{
    double x;
public:
    Ex(double x) : x(x) {}
    friend ostream &operator<<(ostream &os, const Ex &e);
};//class Ex​

ostream &operator<<(ostream &os, const Ex &e)
{
    return os << e.x;
}//ostream &operator<<(ostream &os, const Ex &e)

class Bar
{
    double y;
public:
    Bar(double y = 0) : y(y) {}
    void set(double a)
    {
        if (a + y >100) throw Ex(a*y);
        else y = a;
    }//void set(double &a)
};//class Bar

int main()
{
    try
    {
        cout << "********************** Ex. 2 ***************************\n\n";
            Bar b;
            for (int n = 1; n != 0; cin >> n) {
                cout << "Please, enter number: ";
                b.set(n);
            }//for (int n = 1; n != 0; cin >> n)
        cout << "\n\n";
        return 0;
    }// try
    catch (Ex& e) {
        cerr << "error: " << e << '\n';
        return 1;
    }// catch (Ex& e)
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }// catch (...)
}//int main()
