// Driver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*---------------------------------------------------------------------
                  Driver program to test the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "Staque.cpp"
#include "Staque.h"
#define nums 7

using namespace std;

void print(Staque st)
{
    st.display(cout);
}

int main()
{
    Staque s;
    cout << "Staque created.  Empty? " << boolalpha << s.empty() << endl;

    cout << "Insert integer numbers to be added to the staque(on different lines)" << endl;
    int numbers[nums];
    int i=0;
    for (i = 0; i < nums; ++i) {
        cin >> numbers[i];
        if (numbers[i] % 2 == 0) s.push(numbers[i]);
        else if (numbers[i] % 2 != 0) s.enstaque(numbers[i]);
    }
  

    cout << "Contents of Staque s (via  print):\n";
    print(s); cout << endl;

    

    cout << "do you want to delete elements specified even or odd or in general? \n";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "Type G for general deletion in LIFO structure(last in first out)\n";
    cout << "Type C to choose to delete even or odd\n";
    char c; int top, back, elNum;
    int f = s.frontTs();
    int b = s.backTs();
    cin >> c;
    switch (c) {
        case 'C':
        case 'c':
            cout<< "enter num of elements to delete\n";
            cout << "even: ";
            cin >> top;
            for(i=1; i<=top;++i) s.pop();
            cout << "odd: ";
            cin >> back;
            for (i = 1; i <= back; ++i) s.destaque(); break;

        case 'G':
        case 'g':
            cout << "enter num of elements to delete\n";
            cin >> elNum;
            while (i != elNum) {
                if (f > b) s.pop();
                else s.destaque();
                i++;
            } break;
    }

    cout << "\n\nContents of Staque s (via  print):\n";
    print(s); cout << endl;




    //check = operator
    Staque t;
    t = s;
    cout << "\nContents of stacks t after t = s (via  print):\n";
    cout << "t:\n"; print(t); cout << endl;

}
