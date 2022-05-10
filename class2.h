#include <iostream>
using namespace std;

template<class T>
class rational 
{
public:
	T p, q;

	rational()
	{
		cout << "Введите числитель ";
		cin >> p;
		cout << "Введите знаменатель ";
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
		if (p1 == p && q1 == q) cout << "Равенство ==" << endl;
		else cout << "Равенство !=" << endl;
	}

	void relation()
	{
		float rel, rtl;
		rtl = q;
		rel = p / rtl;
		cout << "Отношение рационального числа" << endl;
		cout << rel << endl;

	}

	void print()
	{
		cout << "Рациональное число" << endl;
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

	//удаление первого элемента в списке
	void push_front(T data)
	{
			head = new Node<T>(data, head);
			Size++;
	}

	//добавление элемента в конец списка
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

		// очистить список
		void clear()
		{
			while (Size)
			{
				pop_front();
			}
		}

		// получить количество елементов в списке
		int GetSize() { return Size; }

		// перегруженный оператор [] 
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

			//добавление элемента в список по указанному индексу
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

			//удаление элемента в списке по указанному индексу
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

			//удаление последнего элемента в списке
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

