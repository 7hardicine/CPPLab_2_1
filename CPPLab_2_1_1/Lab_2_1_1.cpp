#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
#define MIN -20
#define MAX 20
using namespace std;

/* Даны 4 одномерных массива. Подсчитать количество всех,
непрерывных последовательностей положительных чисел,
длина которых больше 3.
Массив заполню при помощи функции rand() */

double* GiveMemory(double* arr_start, int arr_size);
void FillArr(double* arr_start, int arr_size);
void ShowArr(double* arr_start, int arr_size, string arr_name);
double* FreeMemory(double* arr_start);
int CountNumberOfSeq(double* arr_start, int arr_size);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	double* arr = 0;
	char IsNotExit = 0;
	int size = 0;
	string name;
	int number = 0;

	do
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "Введите размер массива: ";
			cin >> size;
			cout << "Введите имя массива: ";
			cin >> name;

			arr = GiveMemory(arr, size);
			FillArr(arr, size);
			ShowArr(arr, size, name);
			number += CountNumberOfSeq(arr, size);
			arr = FreeMemory(arr);
		}

		cout << "Количество последовательностей: " << number << endl;
		cout << "Вы желаете продолжить программу ?" << endl << \
			"Продолжить (1). Закончить (0)" << endl;
		cin >> IsNotExit;
	} while (IsNotExit != '0');

	return 1;
}

double* GiveMemory(double* arr_start, int arr_size)
{
	arr_start = new double[arr_size];
	return arr_start;
}

void FillArr(double* arr_start, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		*(arr_start + i) = rand() % (MAX - MIN + 1) + MIN;
	}
}

void ShowArr(double* arr_start, int arr_size, string arr_name)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr_name << "[" << i + 1 << "] = " << *(arr_start + i) << endl;
	}
}

double* FreeMemory(double* arr_start)
{
	delete[] arr_start;
	arr_start = 0;
	return arr_start;
}

int CountNumberOfSeq(double* arr_start, int arr_size)
{
	int k1 = 1;
	int IsOverThree1 = 0;
	int NumOfSeq = 0;
	for (int i = 1; i < arr_size; i++)
	{
		*(arr_start + i - 1) > 0 && *(arr_start + i - 1) <= *(arr_start + i) ? k1++ : k1 = -1;
		k1 >= 3 ? IsOverThree1 = 1 : IsOverThree1;
		k1 == -1 && IsOverThree1 == 1 ? NumOfSeq++, k1 = 1, IsOverThree1 = 0 : NumOfSeq;
		k1 == -1 ? k1 = 1 : k1;
	}
	return NumOfSeq;
}