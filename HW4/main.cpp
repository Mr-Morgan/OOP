#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <set>
#include <cmath>

/*
1.  Добавить в контейнерный класс, который был написан в этом уроке, методы:

    - для добавления нового элемента в произвольное место
    - для добавления нового элемента на последнее место
    - для удаления последнего элемента массива (аналог функции pop_back() в векторах)
    - для сортировки массива.

2.  Дан вектор чисел (числа вводятся с клавиатуры), требуется выяснить, сколько среди них различных.
    Постараться использовать максимально быстрый алгоритм.

3.  Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле: вектор указателей карт
    (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты
    класса Card). Также в классе Hand должно быть 3 метода:

    - метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
    - метод Clear, который очищает руку от карт
    - метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).

4.  Разработать функцию, принимающую два числа в виде списка (вектора) цифр в одной системе счисления, и возвращающую число — результат
    сложения.в виде списка (вектора) цифр в другой системе счисления. Входные данные <ситема_A>: <цифра_A1>, <цифра_A2>, ... <цифра_AN>
    <ситема_B>: <цифра_B1>, <цифра_B2>, ... <цифра_BM> <ситема_C> система A, B — системы счисления входных чисел, цифра A1..AN и цифра
    B1..BN — запись входных чисел в виде набора цифр от старшего разряда к младшему система C — система счисления результата сложения
    Пример: сложить FF в 16 системе счисления и HELLO в 36 системе счисления, результат вывести в двоичной системе счисления 16: 15, 15
    36: 17, 14, 21, 21, 24 2 По сути задача сводится к тому, чтобы реализовать функцию: std::vector<int> plus(const std::vector<int> &A,
    int baseA, const std::vector<int> &B, int baseB, int baseResult); реализующую сложение чисел в различных системах счисления, и возвращающую
    результат в требуемой системе счисления.
*/

using namespace std;

inline void mySwap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}//inline void mySwap(int *a, int *b)

/*********************** Ex. 1 ****************************/
class ArrayInt
{
    int* data;
    int length;
public:
    ArrayInt() : length(0), data(nullptr) {}
    ArrayInt(int len);
    ~ArrayInt() { delete [] data; }
    void erase();
    int getLength() const { return length; }
    int &operator[] (int index);
    void resize(int newLen);

    void push(int d, int index);
    void pushBack(int d);
    void popBack() { resize(length-1); }
    void sort();
    void print();
};//class ArrayInt

ArrayInt::ArrayInt(int len) : length(len)
{
    assert(len >= 0);
    if (length > 0) data = new int[length];
    else data = nullptr;
}//ArrayInt::ArrayInt(int len) : length(len)

void ArrayInt::erase()
{
    delete [] data;
    data = nullptr;
    length = 0;
}//void ArrayInt::erase()

int &ArrayInt::operator[](int index)
{
    assert(index >= 0 && index < length);
    return data[index];
}//int &ArrayInt::operator[](int index)

void ArrayInt::resize(int newLen)
{
    if (newLen == length) return;
    if (newLen <= 0) {
        erase();
        return;
    }//if (newLen <= 0)

    int* newData = new int[newLen];
    if (length > 0)
        for (int i = 0; i < ((newLen > length)? length:newLen); ++i)
            newData[i] = data[i];

    delete [] data;
    data = newData;
    length = newLen;
}//void ArrayInt::resize(int newLen)

void ArrayInt::push(int d, int index)
{// index [0...]
    if (index < 0) return;
    if (index >= length) {
        pushBack(d);
        return;
    } else {
        resize(length + 1);
        for (int i = length - 2; i >= index; --i) //начиная с предпоследнего элемента
            data[i+1] = data[i];
        data[index] = d;
    }//if (index >= length)
}//void ArrayInt::push(int index)

void ArrayInt::pushBack(int d)
{
    resize(length + 1);
    data[length-1] = d;
}//void ArrayInt::pushBack()

void ArrayInt::sort()
{
    for(int L = 0, R = length - 1; L < R; L++, R--) {
        for(int j = L; j <= R; ++j) {
            if (data[j] > data[R]) mySwap(&data[R], &data[j]);
            if (data[j] < data[L]) mySwap(&data[L], &data[j]);
        }//for(int j = L; j <= R; ++j)
    }//for(int L = 0, R = length - 1; L < R; L++, R--)
}//void ArrayInt::sort()

void ArrayInt::print()
{
    cout << "Array (" << length << "):\n";
    for (int i = 0; i < length; ++i) cout << data[i] << " ";
    cout << endl;
}//void ArrayInt::print()

/*********************** Ex. 2 ****************************/

int RandomNumber () { return (rand()%30); }

void generateVector(vector<int>& v)
{
    generate(v.begin(), v.end(), RandomNumber);
}//void generateVector(vector<int>& v)

void printVector(const vector<int>& v)
{
    for (int num : v) cout << num << " ";
    cout << endl;
}//void printVector(const vector<int>& v)

unsigned long variousNumbers(const vector<int>& v)
{
    set <int> my_set(v.begin(), v.end());
    return my_set.size();
}//unsigned long variousNumbers(const vector<int>& v)

/*********************** Ex. 3 ****************************/
enum Suit { clubs, diamonds, hearts, spades };
enum Value { ace = 1, two, three, four, five, six, seven, eight, nine, ten = 10, jack = 10, queen = 10, king = 10 };
class Card
{
    Suit s;
    Value v;
    bool visible;
public:
    Card(Suit st, Value vl): s(st), v(vl), visible(false) {}
    bool flip() { return visible?false:true; }
    int getValue() const { return v; }
};//class Card

class Hand
{
    vector<Card*> hand;
public:
    Hand() {}
    void Add(Card* card) { hand.push_back(card); }
    void Clear() { hand.clear(); }
    int GetValue() const;
};//class Hand

int Hand::GetValue() const
{
    int score = 0, ace_count = 0;
    for (Card* card : hand)
        if(card->getValue() == 1) ace_count++;
        else score += card->getValue();
    for (int i = 0; i < ace_count; ++i)
        if (score <= 10) score += 11;
        else score++;
    return score;
}//int Hand::GetValue()

/*********************** Ex. 4 ****************************/
int toDec(const vector<int> &A, int base)
{
    int dec = 0;
    for (unsigned i = 0; i < A.size(); ++i)
        dec += A[i] * static_cast<int>(pow(base, A.size() - 1 - i));
    return dec;
}//U toDec(const vector<int> &A, int base)

unsigned numberOfCategories(int numb, int base)
{
    unsigned i = 0;
    for (; numb > 0; numb /= base) i++;
    return i;
}//unsigned numberOfCategories(int numb, int base)

vector<int> decTo(int numb, int base)
{
    vector<int> result(numberOfCategories(numb,base));
    for (unsigned i = 0; numb > 0; numb /= base, ++i)
        result[result.size() - 1 - i] = numb % base;
    return result;
}//vector<int> decTo(int numb, int base)

vector<int> plusVector(const vector<int> &A, int baseA, const vector<int> &B, int baseB, int baseResult)
{
    int summ = toDec(A, baseA) + toDec(B, baseB);
    return decTo(summ, baseResult);
}//vector<int> plusVector(const vector<int> &A, int baseA, const vector<int> &B, int baseB, int baseResult)

int main()
{
    cout << "********************** Ex. 1 ***************************\n\n";
        ArrayInt arr;
        for (int i = 10; i > 0; --i) arr.pushBack(i);
        arr.print();
        arr.push(15, 5);
        arr.print();
        for (int i = 0; i < 5; ++i) arr.popBack();
        arr.print();
        arr.sort();
        arr.print();
    cout << "\n\n";

    cout << "********************** Ex. 2 ***************************\n\n";
        const unsigned size = 20;
        vector<int> vect(size);
        generateVector(vect);
        printVector(vect);
        cout << "Различных чисел: " << variousNumbers(vect) << endl;
    cout << "\n\n";

    cout << "********************** Ex. 3 ***************************\n\n";
    cout << "\n\n";

    cout << "********************** Ex. 4 ***************************\n\n";
        vector<int> numb_1;
        numb_1.push_back(1);
        numb_1.push_back(4);
        numb_1.push_back(0);
        numb_1.push_back(12);
        printVector(numb_1);
        vector<int> numb_2;
        numb_2.push_back(2);
        numb_2.push_back(3);
        numb_2.push_back(2);
        numb_2.push_back(4);
        printVector(numb_2);
        vector<int> rez = plusVector(numb_1, 16, numb_2, 8, 2);
        printVector(rez);
    cout << "\n\n";

    return 0;
}//int main()


