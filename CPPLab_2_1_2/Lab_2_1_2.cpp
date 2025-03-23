#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

/* Даны 3 одномерных массива. Во всех последовательностях 
положительных чисел заменить значения элементов с 
максимальным и минимальным значением на среднее для этой 
последовательности 
Элементы массива ввожу с клавиатуры */

template <typename T>
T* GiveMemory(T* arr_start, int arr_size)
{
	arr_start = new T[arr_size];
	return arr_start;
}

template <typename T>
void FillArr(T* arr_start, int arr_size, string arr_name)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr_name << "[" << i + 1 << "] = ";
		cin >> *(arr_start + i);
	}
}

template <typename T>
void ShowArr(T* arr_start, int arr_size, string arr_name, string mess)
{
	cout << mess << endl;
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr_name << "[" << i + 1 << "] = " << *(arr_start + i) << endl;
	}
}

template <typename T>
T* FreeMemory(T* arr_start)
{
	delete[] arr_start;
	arr_start = 0;
	return arr_start;
}

template <typename T>
void TaskFunc(T* arr_start, int arr_size, string arr_name)
{
	int k = 0, kol = 0;
	int IsOverThree = 0;
	T summ_of_seq = 0;
	int max_el_index = 0, min_el_index = 0;
	double avg_value = 1;

	for (int i = 0; i < arr_size; i++)
	{
		*(arr_start + i) > 0 ? k++, kol++, summ_of_seq += *(arr_start + i), \
			* (arr_start + i) > * (arr_start + max_el_index) ? max_el_index = i : max_el_index, \
			* (arr_start + i) < *(arr_start + min_el_index) ? min_el_index = i : min_el_index \
			: k = -1;
		k > 3 ? IsOverThree = 1 : IsOverThree;
		(k == -1 && IsOverThree == 1) || (i == arr_size - 1 && IsOverThree == 1) ? \
			avg_value = summ_of_seq / kol, k = 0, kol = 0, IsOverThree = 0, \
			*(arr_start + max_el_index) = avg_value, *(arr_start + min_el_index) = avg_value : \
			avg_value;
		k == -1 ? k = 0, kol = 0, avg_value = 1, summ_of_seq = 0, max_el_index = i + 1, min_el_index = i + 1 : k;
	}

	ShowArr(arr_start, arr_size, arr_name, "Измененный массив");
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double* arr_double = 0;
	int* arr_int = 0;
	char IsNotExit = 0;
	int size = 0;
	string name;

	do
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Введите размер массива: ";
			cin >> size;
			cout << "Введите имя массива: ";
			cin >> name;

			int arr_var;
			cout << "Какой тип массива вы хотите создать ?" << endl << "int (1). double (2)" << endl;
			cin >> arr_var;

			switch (arr_var)
			{
			case 1:
			{
				arr_int = GiveMemory(arr_int, size);
				FillArr(arr_int, size, name);
				ShowArr(arr_int, size, name, "Исходный массив");
				TaskFunc(arr_int, size, name);
				arr_int = FreeMemory(arr_int);
				break;
			}
			default:
			{
				arr_double = GiveMemory(arr_double, size);
				FillArr(arr_double, size, name);
				ShowArr(arr_double, size, name, "Исходный массив");
				TaskFunc(arr_double, size, name);
				arr_double = FreeMemory(arr_double);
				break;
			}
			}
		}

		cout << "Вы желаете продолжить программу ?" << endl << \
			"Продолжить (1). Закончить (0)" << endl;
		cin >> IsNotExit;
	} while (IsNotExit != '0');

	return 1;
}