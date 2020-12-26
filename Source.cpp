//Лабораторна робота 7.3
//Щепітки Соломії
//Варіант 23

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void H(int** a, int rowCount, int colCount)
{
	int count = 0;
	for (int i = 0; i < colCount; i++)
	{
		for (int j = 0; j < rowCount; j++)
		{
			if (a[j][i] == 0)
				count++;
		}
	}
	cout << count << endl;
}
void M(int** a, int rowCount, int colCount)
{
	int count = 0;
	int maxcnt = 0;
	int ipos = -1;
	int icnt = -1;
	for (int i = 0; i < rowCount; i++)
	{
		int cnt = 0;
		for (int j = 1; j < rowCount; j++)
		{
			if (a[i][j] == a[i][j - 1])
				cnt++;
			else
			{
				if (cnt > maxcnt)
				{
					maxcnt = cnt;
					ipos = i;
					icnt++;
				}
				cnt = 0;
			}
		}
		if (cnt > maxcnt)
		{
			maxcnt = cnt;
			ipos = i;
			icnt++;
		}
	}
	if (-1 == icnt)cout << ("Немає рядків з однаковими елементами!") << endl;
	else cout << ("Номер радка в якому є найдовша серія однакових чисел ") << (ipos + 1);
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 15;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, n, Low, High);
	//Input(a, rowCount, colCount);
	Print(a, n, n);
	H(a, n, n);
	M(a, n, n);
	cout << endl;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}