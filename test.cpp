#include <iostream>
using namespace std;
class base
{
public:
    void display()
    {
        cout << "Displaying base class";
    }

    virtual void show()
    {
        cout << "Showing base class";
    }
};

class derived : public base
{
public:
    void display()
    {
        cout << "Displaying derived class";
    }

    void show()
    {
        cout << "Showing derived class";
    }
};

int main()
{
    base b1;
    derived d1;
    base *bptr;
    bptr = &b1;
    bptr->display();
    cout << endl;
    bptr->show();
    cout << endl;
    cout << endl;
    bptr = &d1;
    bptr->display();
    cout << endl;
    bptr->show();
    cout << endl;
}