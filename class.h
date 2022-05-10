#include <iostream>
using namespace std;

class DynmMass {
    int* data,po;

public:

    DynmMass(int yui)
    {
    po = yui;
    data = new int[po]; 
    }

    void enter()
    {  
        cout << "Ввод элементов массива" << endl;
        for (int i = 0; i < po; i++)
        {
            data[i] = i+1;
        }
    }

    void print()
    {
     for (int i = 0; i < po; i++)
     {
         cout << i << "./-" << data[i] << endl;
     }
     cout << "Вывод" << endl;
    }

    void add()
    {   
        int *datas = new int[po + 1];
        for (int i = 0; i < po; i++)
        {
            datas[i] = data[i];
        }
        cout << "." << po << "-";
        cin >> datas[po];
        delete[] data;
        data = datas;
        po++;
        cout << "Добаваление" << endl;
    }

    void delet(int ko,int lo)
    {
        int p=ko+lo;
        if (p > po) p = po;
        for (; ko < p ; ko++)
        {
         data[ko]=0;
        }
        cout << "Удаление" << endl;
    }

    void mul()
    {
        int kl=1;
        for (int i = 0; i < po; i++)
        {
            kl *= data[i];
        }
        cout << "mul = " << kl << endl;
        cout << "Умножение" << endl;
    }

    void copy(const DynmMass &value)
    {
        po = value.po;
        data = new int[value.po];

        for (int i = 0; i < value.po; i++)
        {
            data[i] = value.data[i];
        }
        cout << "Копирование" << endl;
    }

    ~DynmMass()
    {
        delete[] data;
        cout << "Декструктор" << endl;
    }
};

class rational {
  
void dgs(int& pe, int& qe)
{
    if (pe % 3 == 0 && qe % 3 == 0)
    {
        pe /= 3;
        qe /= 3;
        dgs(pe, qe);
    }
    else if (pe % 2 == 0 && qe % 2 == 0)
    {
        pe /= 2;
        qe /= 2;
        dgs(pe, qe);
    }
    else if (pe % qe == 0)
    {
        pe /= qe;
        qe /= qe;
        dgs(pe, qe);
    }
    else if (qe % pe == 0)
    {
        qe /= pe;
        pe /= pe;
        dgs(pe, qe);
    }
}

public:
  int p, q;

    rational()
    {
        cout << "Введите числитель ";
        cin >> p;
        cout << "Введите знаменатель ";
        cin >> q;
    }

    rational(int p1,int q1)
    {
        p = p1;
        q = q1;  
    }

    void div(int  p1,int q1)
    {
        p *= q1;
        q *= p1;
        dgs(p, q);
    }

    void mul(int  p1, int q1)
    {
        p *= p1;
        q *= q1;
        dgs(p, q);
    }

    void plu(int  p1, int q1)
    {
        p *= q1;
        p1 *= q;
        p += p1;
        q *= q1;
        dgs(p, q);
    }

    void mun(int  p1, int q1)
    {
        p *= q1;
        p1 *= q;
        p -= p1;
        q *= q1;
        dgs(p, q);
    }

    void compar(int  p1, int q1)
    {
        dgs(p1, q1);
        if (p1 == p && q1 == q) cout << "Равенство ==" << endl;
        else cout << "Равенство !=" << endl;
    }

    void relation()
    {
        float rel, rtl;
        rtl = q;
        rel =p / rtl;
        cout << "Отношение рационального числа" << endl;
        cout << rel << endl; 

    }

    void print()
    {
        cout << "Рациональное число" << endl;
        cout << p << "/" << q << endl;
    }
};

