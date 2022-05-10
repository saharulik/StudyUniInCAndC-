#include <iostream>
#include <chrono>
using namespace std;

int RecurcieveFactorial(int number) {
	if (number == 0 || number == 1) {
		return 1;
	}
	else {
		return  number * RecurcieveFactorial(number - 1);
	}
}

int IteratieveFactorial(int number) {
	int answer = 1;
	for (int i = 1; i <= number; i++) {
		answer *= i;
	}
	return answer;
}

int RecursieveFibonachi(int number)
{
	if (number == 2) return 1;
	if (number == 1) return 0;
	return RecursieveFibonachi(number - 1) + RecursieveFibonachi(number - 2);
}

int IteratieveFibonachi(int number) {
	if (number == 1) return 1;
	if (number == 0) return 0;
	int answer = 0;
	int firstNumber = 0;
	int secondNumber = 1;
	for (int i = 0; i <= number; i++) {
		answer = firstNumber + secondNumber;
		firstNumber = secondNumber;
		secondNumber = answer;
	}
	return number;
}

int RecurcieveSumBetweenTwoNumbers(int n) {
	int sum = 0;
	int a = 0;
	if ((n - 1) == a)
		sum = n + a;
	else
		sum = n + RecurcieveSumBetweenTwoNumbers(n - 1);
	return sum;
}

int IteratieveSumBetweenTwoNumbers(int n) {
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}

void Times(int n, float T1,float T2) {
	cout << n << " " << (T1 / 10000) << " " << (T2 / 10000) << endl;
}

float call(int (*func)(int n), int n)
{
	auto start = chrono::high_resolution_clock::now();
	func(n);
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = finish - start;
	return duration.count();
}

void factorial()
{
	float T1, T2;
	cout << "Factorial" << endl;
	cout << "n Recurcieve Iteratieve" << endl;
	for (int i = 100; i <= 1000; i += 100) {
		T1 = T2 = 0;
		for (int j = 0; j < 10000; j++) {
			T1 += call(RecurcieveFactorial, i);
			T2 += call(IteratieveFactorial, i);
		}
		Times(i, T1, T2);
	}
	cout << endl;
}

void fibonachi()
{
	float T1, T2;
	cout << "Fibonachi" << endl;
	cout << "n Recurcieve Iteratieve" << endl;
	for (int i = 10; i <= 20; i += 1) {
		T1 = T2 = 0;
		for (int j = 0; j < 10000; j++) {
			T1 += call(RecursieveFibonachi, i);
			T2 += call(IteratieveFibonachi, i);
		}
		Times(i, T1, T2);
	}
	cout << endl;
}

void sumBetweenTwoNumbers()
{
	float T1, T2;
	cout << "Sum Between 0 and N" << endl;
	cout << "n Recurcieve Iteratieve" << endl;
	for (int i = 100; i <= 1000; i += 100) {
		T1 = T2 = 0;
		for (int j = 0; j < 10000; j++) {
			T1 += call(RecurcieveSumBetweenTwoNumbers, i);
			T2 += call(IteratieveSumBetweenTwoNumbers, i);
		}
		Times(i, T1, T2);
	}
	cout << endl;
}

void mais() {
	factorial();
	fibonachi();
	sumBetweenTwoNumbers();
}