#include <iostream>
#include <stdexcept>
#include <sstream>

/*
3.  Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть
    метод, означающий задание переместиться на соседнюю позицию. Эти методы должны
    запускать исключение ​ OffTheField​ , если робот должен уйти с сетки, и ​ IllegalCommand​ , если
    подана неверная команда (направление не находится в нужном диапазоне). Объект
    исключения должен содержать всю необходимую информацию — текущую позицию и
    направление движения. Написать функцию ​ main​ , пользующуюся этим классом и
    перехватывающую все исключения от его методов, а также выводящую подробную
    информацию о всех возникающих ошибках.
*/

using namespace std;

[[noreturn]] inline void error(const string& s)
{
        throw runtime_error(s);
}//inline void error(const string& s)

class Robot;

[[noreturn]] inline void error(const string& s, Robot &r);

[[noreturn]] inline void error(const string& s, int i)
{
        ostringstream os;
        os << s <<": " << i;
        error(os.str());
}//inline void error(const string& s, int i)

/*********************** Ex. 3 ****************************/
#define MAX_X 10
#define MAX_Y 10
#define MIN_XY 0
#define STOP 0

enum Direction { North = 1, East, South, West };

#define OTF "Off the field - in function move"
#define IC "Illegal Command - in function move()"

class Robot
{
    int x,y;
public:
    Robot(int x = 0, int y = 0) : x(x), y(y) {}
    friend ostream &operator<< (ostream &os, Robot &r);
    void move(int &d)
    {
        switch (d) {
        case North:
            if (y+1 > MAX_Y) error(OTF"(North)", *this);
            else y++;
            break;
        case East:
            if (x-1 < MIN_XY) error(OTF"(East)", *this);
            else x--;
            break;
        case South:
            if (y-1 < MIN_XY) error(OTF"(South)", *this);
            else y--;
            break;
        case West:
            if (x+1 > MAX_X) error(OTF"(West)", *this);
            else x++;
            break;
        default: error(IC, d);
        }//switch (d)
        cout << *this;
    }//void move(int &d))
};//class Robot

ostream &operator<< (ostream &os, Robot &r)
{
    return os << "current position (" << r.x << ", " << r.y << ").\n";
}//ostream &operator<< (ostream &os, Robot &r)

[[noreturn]] inline void error(const string& s, Robot &r)
{
        ostringstream os;
        os << s <<": " << r;
        error(os.str());
}//inline void error(const string& s, Robot &r)

inline void prompt(int &c)
{
    cout << "> ";
    cin >> c;
}//inline void prompt(int &c)

int main()
{
    try
    {
        cout << "********************** Ex. 3  ***************************\n\n";
            cout << "\tRobot control program."
                    "\nEnter 1 to lift the robot one cell north."
                    "\n2 to the cell east."
                    "\n3 to the cell south."
                    "\n4 to the cell west."
                    "\n0 to exit the program.\n\n";
            Robot r;
            cout << r << endl;
            int a = 1;
            for (prompt(a); a != STOP; prompt(a)) r.move(a);
        cout << "\n\n";
        return 0;
    }// try
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }// catch (exception& e)
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }// catch (...)
}//int main()
