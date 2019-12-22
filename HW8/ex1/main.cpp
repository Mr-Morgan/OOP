#include <iostream>
#include <stdexcept>

/*
1.  Написать функцию ​ div​ , которая должна вычислять результат деления двух целых чисел и
    запускать исключение ​ DivisionByZero​ , если делитель равен 0. В функции main ввести два
    целых числа и вывести их неполное частное, если делитель не равен нулю, и сообщение об
    ошибке, если равен.
*/


using namespace std;

[[noreturn]] inline void error(const string& s)
{
        throw runtime_error(s);
}//inline void error(const string& s)

/*********************** Ex. 1 ****************************/
int myDiv(int &dividend, int &divider)
{
    if(divider == 0) error("Division by zero - in function myDiv()​");
    return dividend/divider;
}//int div(int &dividend, int &divider)

int main()
{
    try
    {
        cout << "********************** Ex. 1 ***************************\n\n";
            int a = 5, b = 4;
            cout << myDiv(a,b) << endl;
            b = 0;
            cout << myDiv(a,b);
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
