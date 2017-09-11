#include <iostream>
using namespace std;

class Sterling{
private:
    long pounds;
    int shillings;
    int pence;

public:
    Sterling()
    {

    }

    Sterling(double po)
    {
        pounds = po;
    }

    Sterling(long po, int sh, int pe)
    {
        pounds = po;
        shillings = sh;
        pence = pe;
    }

    void getSterling()
    {

    }

};


class Counter{
private:
    unsigned int count;            //count
public:
    Counter():count(0)               //Constructor
    {

    }
    Counter(int c): count(c)        //Constructor, one argument
    {
    }
    unsigned int getCount()        //return count
    {
        return count;
    }
    void operator ++ ()            //Increment prefix
    {
        ++count;
    }
    Counter operator ++ (int)         //Increment count prefix
    {
        //Increment the count and then return an unnamed temporary object initialized to this count
        return Counter(++count);
    }

};

class Counter1{
private:
    unsigned int count;            //count
public:
    Counter1():count(0)               //Constructor
    {

    }
    Counter1(int c): count(c)        //Constructor, one argument
    {
    }
    unsigned int getCount()        //return count
    {
        return count;
    }
    Counter1 operator ++ ()         //Increment count prefix
    {
        //Increment the count and then return an unnamed temporary object initialized to this count
        return Counter1(++count);
    }

};

int main(){
    Counter c1, c2;                //define and initialize
    cout << "\nc1=" << c1.getCount();  //display
    cout << "\nc2=" << c2.getCount();  //display
    ++c1;
    ++c2;
    ++c2;
    cout << "\nc1=" << c1.getCount();  //display again
    cout << "\nc2=" << c2.getCount();  //display again

    Counter1 c3, c4;                //define and initialize
    cout << "\nc3=" << c3.getCount();  //display
    cout << "\nc4=" << c4.getCount();  //display
    ++c3;
    c4 = ++c3;
    ++c4;
    cout << "\nc3=" << c3.getCount();  //display again
    cout << "\nc4=" << c4.getCount();  //display again
    return 0;

}


