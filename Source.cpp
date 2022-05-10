#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

#include "Header.h"

//вывод массива
void display(vector<int>& array) {
    size_t d = array.size();
    cout << endl << endl;
    for (int i = 0; i < d; i++)
    {
        cout << array[i] << " ";
    }

}

//пузырькова€ сортировка
void bubbleSort(vector<int>& array)
{
    int tmp = 0;
    size_t D = array.size();
    for (int i = 0; i < D; i++) {
        for (int j = (D - 1); j >= (i + 1); j--) {
            if (array[j] < array[j - 1]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
    //cout << endl << "ѕузырькова€ сортировка" << endl;
}

//сортировка вставками
void insertionSort(vector<int>& data)
{
    int lenD = data.size();
    int key = 0;
    int i = 0;
    for (int j = 1; j < lenD; j++) {
        key = data[j];
        i = j - 1;
        while (i >= 0 && data[i] > key) {
            data[i + 1] = data[i];
            i = i - 1;
            data[i + 1] = key;
        }
    }
    //cout << endl << "—ортировка выбором" << endl;
}

//сортировка выбором
void selectionSort(vector<int>& data)
{
    int lenD = data.size();
    int j = 0;
    int tmp = 0;
    for (int i = 0; i < lenD; i++) {
        j = i;
        for (int k = i; k < lenD; k++) {
            if (data[j] > data[k]) {
                j = k;
            }
        }
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
    //cout << endl << "—ортировка вставками" << endl;
}


//создание массива
void massive(vector<int>& array, int d)
{
    for (int i = 0; i < d; i++)
    {
        array[i] = rand() % d + 1;
    }
}

//вызов сортировки и врем€ 
int call(void (*func)(vector<int>& array), vector<int>& array, int c)
{
    int j;
    size_t d = array.size();
    massive(array, d);
    if (c == 1) { display(array); }
    auto start = chrono::steady_clock::now();
    func(array);
    auto finish = chrono::steady_clock::now();
    auto dur = finish - start;
    j = chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    if (c == 1) { display(array); }
    return j;
}

void mais()
{
    int d,c,g,n=100;
    cin >> d >> g >> c;
        for (; d < g; )
        {
            int j=0, k=0, l=0;
           
            cout << d << endl;
            for (int i = 0; i <= n;i++)
            {
                vector<int> array(d);
                j=j+call(selectionSort, array, c);
                k=k+call(bubbleSort, array, c);
                l=l+call(insertionSort, array, c);
            
            }
            j = j / n;
            cout << j << endl;
            k = k / n;
            cout << k  << endl;
            l = l / n;
            cout << l << endl;
            d = d + 100;
        }
}