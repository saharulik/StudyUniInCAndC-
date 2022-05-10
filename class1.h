#include <iostream>
#include <string>
using namespace std;

class COne
{
	long l;
	string s;
public:

	COne() // ���������
	{
		cout << "������� ��������� ��� COne:" << endl;
		cout << "s=";
		cin >> s;
		cout << "l=";
		cin >> l;
	}

	COne(string j, long u) // ���������
	{
		s = j;
		l = u;
	}

	COne(const COne& ty) // ����������� 
	{
		s = ty.s;
		l = ty.l;
	}

	void operator=(const COne& ty) // ���������� 
	{
		s = ty.s;
		l = ty.l;
	}

	void Print() // ������
	{
		cout << "COne" << endl << s << endl << l << endl << endl;
	}

	long& getValue() // ������ l
	{
		return l;
	}

	string& getString() // ������ s
	{
		return s;
	}

	~COne() // ���������� 
	{
		cout << "COne ����������" << endl;
	}
};

class CTwo
{
public:

	CTwo() // ���������
	{
		string r;
		long f;
		cout << "������� ��������� ��� CTwo:" << endl;
		cout << "s=";
		cin >> r;
		cout << "l=";
		cin >> f;
		p = new COne(r, f);
		cout << "������� �����:" << endl;
		cin >> d;
	}

	CTwo(const CTwo& ty) //����������� 
	{
		p = new COne (*ty.p);
		d = ty.d;
	}

	CTwo(const COne& ty, double u) // ���������
	{
		p = new COne(ty);
		d = u;
	}

	void operator=(const CTwo& ty) // ����������
	{
		p = new COne (*ty.p);
		d = ty.d;
	}

	virtual void Print() // ������
	{
		cout << "CTwo" << endl << d << endl;
		p->Print();
		
	}

	COne* getOne() // ������ p
	{
		return p;
	}

	double& getString() // ������ d
	{
		return d;
	}

	~CTwo() // ����������� 
	{
		delete p;
		cout << "CTwo ����������" << endl;
	}

private:
	COne* p;
	double d;
};

class CThree : public CTwo
{
public:

	CThree() : CTwo() // ���������
		{
		d = 0;
	}

	CThree(const CThree& ty) : CTwo(ty) //����������� 
	{
		d = ty.d;
	}

	CThree(double u,const COne& ty) : CTwo(ty, u) // ���������
	{
		d = u;
	}

	virtual void Print() // ������
	{
		cout << "CThree" << endl << d << endl;
		CTwo::Print();
	}

	double& getString() // ������ d
	{
		return d;
	}

	~CThree() // ����������� 
	{
		cout << "CThree ����������" << endl;
	}

private:
	double d;
};

class CFour : public CThree
{
public:

	CFour() : CThree()// ���������
	{
		d = 0;
	}

	CFour(const CFour& ty) : CThree(ty)//����������� 
	{
		d = ty.d;
	}

	CFour(double u, const COne& ty) : CThree(u,ty)// ���������
	{
		d = u;
	}

	void Print() override // ������
	{
		
		cout << "CFour" << endl << d << endl;
		CTwo::Print();
		CThree::Print();
	}

	double& getString() // ������ d
	{
		return d;
	}

	~CFour() // ����������� 
	{
		cout << "CFour ����������" << endl;
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

