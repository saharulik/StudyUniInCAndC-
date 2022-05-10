#include "class2.h"

void test1()
{
    rational<int> ty(20.5,23.8);
    ty.div(2.1, 3.4);
    ty.mul(2.9, 4.8);
    // ty.mun(10, 23);
    ty.compar(10, 23);
    ty.relation();
    ty.print();
}

void test2() 
{
    List<int> lst;
    List<char> lsr;
    lst.push_front(11);
    lst.push_front(99);
    lst.push_front(88);


    for (int i = 0; i < lst.GetSize(); i++) // вывод данных
    {
        cout << lst[i] << endl;
    }

    cout << endl << "pop_back " << endl << endl;

    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "insert " << endl << endl;

    lst.insert(44, 2);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    lst.removeAt(2);

        cout << endl << "removeAt " << endl << endl;

        for (int i = 0; i < lst.GetSize(); i++)
        {
            cout << lst[i] << endl;
        }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    test2();
    cout << "Error" << endl;
    return 0;
}

