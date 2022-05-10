#include <iostream>
#include <string>
using namespace std;

class COne
{
	long l;
	string s;
public:

	COne() // умолчание
	{
		cout << "Введите параметры для COne:" << endl;
		cout << "s=";
		cin >> s;
		cout << "l=";
		cin >> l;
	}

	COne(string j, long u) // параметры
	{
		s = j;
		l = u;
	}

	COne(const COne& ty) // копирование 
	{
		s = ty.s;
		l = ty.l;
	}

	void operator=(const COne& ty) // перегрузка 
	{
		s = ty.s;
		l = ty.l;
	}

	void Print() // ввывод
	{
		cout << "COne" << endl << s << endl << l << endl << endl;
	}

	long& getValue() // доступ l
	{
		return l;
	}

	string& getString() // доступ s
	{
		return s;
	}

	~COne() // деструктор 
	{
		cout << "COne Деструктор" << endl;
	}
};

class CTwo
{
public:

	CTwo() // умолчание
	{
		string r;
		long f;
		cout << "Введите параметры для CTwo:" << endl;
		cout << "s=";
		cin >> r;
		cout << "l=";
		cin >> f;
		p = new COne(r, f);
		cout << "Введите число:" << endl;
		cin >> d;
	}

	CTwo(const CTwo& ty) //копиравоние 
	{
		p = new COne (*ty.p);
		d = ty.d;
	}

	CTwo(const COne& ty, double u) // параметры
	{
		p = new COne(ty);
		d = u;
	}

	void operator=(const CTwo& ty) // перегрузка
	{
		p = new COne (*ty.p);
		d = ty.d;
	}

	virtual void Print() // ввывод
	{
		cout << "CTwo" << endl << d << endl;
		p->Print();
		
	}

	COne* getOne() // доступ p
	{
		return p;
	}

	double& getString() // доступ d
	{
		return d;
	}

	~CTwo() // декструктор 
	{
		delete p;
		cout << "CTwo Деструктор" << endl;
	}

private:
	COne* p;
	double d;
};

class CThree : public CTwo
{
public:

	CThree() : CTwo() // умолчание
		{
		d = 0;
	}

	CThree(const CThree& ty) : CTwo(ty) //копиравоние 
	{
		d = ty.d;
	}

	CThree(double u,const COne& ty) : CTwo(ty, u) // параметры
	{
		d = u;
	}

	virtual void Print() // ввывод
	{
		cout << "CThree" << endl << d << endl;
		CTwo::Print();
	}

	double& getString() // доступ d
	{
		return d;
	}

	~CThree() // декструктор 
	{
		cout << "CThree Деструктор" << endl;
	}

private:
	double d;
};

class CFour : public CThree
{
public:

	CFour() : CThree()// умолчание
	{
		d = 0;
	}

	CFour(const CFour& ty) : CThree(ty)//копиравоние 
	{
		d = ty.d;
	}

	CFour(double u, const COne& ty) : CThree(u,ty)// параметры
	{
		d = u;
	}

	void Print() override // ввывод
	{
		
		cout << "CFour" << endl << d << endl;
		CTwo::Print();
		CThree::Print();
	}

	double& getString() // доступ d
	{
		return d;
	}

	~CFour() // декструктор 
	{
		cout << "CFour Деструктор" << endl;
	}

private:
	double d;
};

void PrintAll(CTwo** t, int n)
{
	for (int i = 0; i < n; ++i)
	{
		t[i]->Print();
		cout << endl;
	}
}

