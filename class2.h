#include <iostream>
using namespace std;

template<class T>
class rational 
{
public:
	T p, q;

	rational()
	{
		cout << "������� ��������� ";
		cin >> p;
		cout << "������� ����������� ";
		cin >> q;
	}

	rational(T p1, T q1)
	{
		p = p1;
		q = q1;
	}

	void div(T  p1, T q1)
	{
		p *= q1;
		q *= p1;
	}

	void mul(T  p1, T q1)
	{
		p *= p1;
		q *= q1;
	}

	void plu(T  p1, T q1)
	{
		p *= q1;
		p1 *= q;
		p += p1;
		q *= q1;
	}

	void mun(T  p1, T q1)
	{
		p *= q1;
		p1 *= q;
		p -= p1;
		q *= q1;
	}

	void compar(T  p1, T q1)
	{
		if (p1 == p && q1 == q) cout << "��������� ==" << endl;
		else cout << "��������� !=" << endl;
	}

	void relation()
	{
		float rel, rtl;
		rtl = q;
		rel = p / rtl;
		cout << "��������� ������������� �����" << endl;
		cout << rel << endl;

	}

	void print()
	{
		cout << "������������ �����" << endl;
		cout << p << "/" << q << endl;
	}
};

template<typename T>
class List
{
public:



	List()
	{
		Size = 0;
		head = nullptr;
	}

	~List()
	{
		clear();
	}

	//�������� ������� �������� � ������
	void push_front(T data)
	{
			head = new Node<T>(data, head);
			Size++;
	}

	//���������� �������� � ����� ������
	void push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);

		}
		Size++;
	}

		// �������� ������
		void clear()
		{
			while (Size)
			{
				pop_front();
			}
		}

		// �������� ���������� ��������� � ������
		int GetSize() { return Size; }

		// ������������� �������� [] 
		T& operator[](const int index)
		{
			int counter = 0;

			Node<T>* current = this->head;

			while (current != nullptr)
			{
				if (counter == index)
				{
					return current->data;
				}
				current = current->pNext;
				counter++;
			}
		}

			//���������� �������� � ������ �� ���������� �������
			void insert(T data, int index)
			{

				if (index == 0)
				{
					push_front(data);
				}
				else
				{
					Node<T>* previous = this->head;

					for (int i = 0; i < index - 1; i++)
					{
						previous = previous->pNext;
					}

					Node<T>* newNode = new Node<T>(data, previous->pNext);

					previous->pNext = newNode;

					Size++;
				}

			}

			//�������� �������� � ������ �� ���������� �������
			void removeAt(int index)
			{
				if (index == 0)
				{
					pop_front();
				}
				else
				{
					Node<T>* previous = this->head;
					for (int i = 0; i < index - 1; i++)
					{
						previous = previous->pNext;
					}


					Node<T>* toDelete = previous->pNext;

					previous->pNext = toDelete->pNext;

					delete toDelete;

					Size--;
				}

			}

			//�������� ���������� �������� � ������
			void pop_back()
			{
				removeAt(Size - 1);
			}

			void pop_front()
			{
				Node<T>* temp = head;

				head = head->pNext;

				delete temp;

				Size--;

			}

			

		private:

			template<typename T>
			class Node
			{
			public:
				Node* pNext;
				T data;

				Node(T data = T(), Node* pNext = nullptr)
				{
					this->data = data;
					this->pNext = pNext;
				}
			};
			int Size;
			Node<T>* head;

		};

