#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>

/*
1.  Создать программу, которая бы запрашивала у пользователя строки до тех пор, пока он не введет пустую строку. После
    этого программа должна вывести список введенных строк в два столбца, первый из которых выровнен по левому краю, а
    второй — по правому краю.

2.  Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь вводит
    что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз.
    Пример неправильных введенных строк:
        rbtrb
        nj34njkn
        1n

3.  Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает
    буфер.

4.  Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:

    - `virtual bool IsHitting() const` - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя,
      нужна ли ему еще одна карта и возвращает ответ пользователя в виде `true` или `false`.
    - `void Win() const` - выводит на экран имя игрока и сообщение, что он выиграл.
    - `void Lose() const` - выводит на экран имя игрока и сообщение, что он проиграл.
    - `void Push() const` - выводит на экран имя игрока и сообщение, что он сыграл вничью.

5.  Реализовать класс `House`, который представляет дилера. Этот класс наследует от класса `GenericPlayer`. У него есть 2 метода:

    - virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он
      берет еще одну карту.
    - void FlipFirstCard() - метод переворачивает первую карту дилера.
*/

using namespace std;

/*********************** Ex. 1 ****************************/
#define MAX_STR_SIZE 20

void scanStrArr(vector<string> *str, istream &is)
{
    for(string s = "???"; getline(is, s) && s.size();)
        str->push_back(s);
}//vector<string> &scanStrArr(vector<string> &str, istream &is)

void printStrInTwoColumns(vector<string> &str, ostream &os)
{
    for(unsigned i = 0; i < str.size(); ++i)
            os << setw(MAX_STR_SIZE) << ((i%2)?right:left)
               << str[i] << ((i%2)?'\n':'\t');
}//void printStrInTwoColumns(vector<string> &str, ostream &os)

/*********************** Ex. 2 ****************************/
bool isIntNumber(string &s)
{
    cmatch res;
    regex reg("([\\d-]+)");
    return regex_match(s.c_str(), res, reg)?true:false;
}//bool isIntNumber(string &s)

/*********************** Ex. 3 ****************************/
ostream &endll(ostream &os)
{
    return os << '\n' << endl;
}//ostream &endll(ostream &os)

int main()
{
    /*  TEST data
virtual bool
IsHitting() const
void Lose()
rbtrb
nj34njkn
1n

    */

    cout << "********************** Ex. 1 ***************************\n\n";
        vector<string> str_arr;
        scanStrArr(&str_arr, cin);
        printStrInTwoColumns(str_arr, cout);
    cout << "\n\n";

    cout << "********************** Ex. 2 ***************************\n\n";
        int numb = 0;
        string str = "???";
        for(;;){
            cout << "Enter number: ";
            cin >> str;
            if(isIntNumber(str)){
                numb = (str == "-")?0:stoi(str);
                break;
            }//if(isIntNumber(str))
        }//for(;;)
        cout << "Integer number: " << numb;
    cout << "\n\n";

    cout << "********************** Ex. 3 ***************************\n\n";
        cout << "Some" << endll << "text";
    cout << "\n\n";

    return 0;
}//int main()
