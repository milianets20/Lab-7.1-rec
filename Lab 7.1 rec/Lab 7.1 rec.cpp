#include <iostream>
#include <Windows.h>

using namespace std;

void Create(int** C, const int HIGH, const int LOW, const int ROW_COUNT, const int COL_COUNT,
	int i, int j);
void Print(int** C, const int ROW_COUNT, const int COL_COUNT, int i, int j);
void Calc(int** C, const int ROW_COUNT, const int COL_COUNT, int& suma, int& count, int i, int j);
void Sort(int** C, const int ROW_COUNT, const int COL_COUNT, int j, int i0, int i1);
void Change(int** C, const int row1, const int row2, const int COL_COUNT, int j);

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int HIGH = 74;
	const int LOW = 11;
	const int ROW_COUNT = 8;
	const int COL_COUNT = 9;

	int** C = new int* [ROW_COUNT];
	for (int i = 0; i < ROW_COUNT; i++)
		C[i] = new int[COL_COUNT];

	cout << "F: " << "\n";
	int i = 0;
	int j = 0;
	int i0 = 1;
	int i1 = 1;
	Create(C, HIGH, LOW, ROW_COUNT, COL_COUNT, i, j);
	Print(C, ROW_COUNT, COL_COUNT, i, j);
	cout << "D: " << "\n";
	Sort(C, ROW_COUNT, COL_COUNT, j, i0, i1);
	Print(C, ROW_COUNT, COL_COUNT, i, j);

	int suma = 0;
	int count = 0;
	Calc(C, ROW_COUNT, COL_COUNT, suma, count, i, j);
	cout << "S: " << suma << "\n" << "\n";
	cout << "D: " << count << "\n" << "\n";
	cout << "N: " << "\n";
	Print(C, ROW_COUNT, COL_COUNT, i, j);
	for (int i = 0; i < ROW_COUNT; i++)
		delete[] C[i];
	delete[] C;

	system("pause");
	return 0;

}
void Create(int** C, const int HIGH, const int LOW, const int ROW_COUNT, const int COL_COUNT,
	int i, int j)
{
	C[i][j] = LOW + rand() % (HIGH - LOW + 1);
	if (j < COL_COUNT - 1)
		Create(C, HIGH, LOW, ROW_COUNT, COL_COUNT, i, j + 1);
	else
		if (i < ROW_COUNT - 1)
			Create(C, HIGH, LOW, ROW_COUNT, COL_COUNT, i + 1, 0);
}
void Print(int** C, const int ROW_COUNT, const int COL_COUNT, int i, int j)
{
	cout << C[i][j] << "\t";
	if (j < COL_COUNT - 1)
		Print(C, ROW_COUNT, COL_COUNT, i, j + 1);
	else
	{
		cout << "\n";
		if (i < ROW_COUNT - 1)
		{
			Print(C, ROW_COUNT, COL_COUNT, i + 1, 0);
			
		}
		else cout << "\n";
	}
}
void Calc(int** C, const int ROW_COUNT, const int COL_COUNT, int& suma, int& count, int i, int j)
{
	if (C[i][j] % 6 == 0 && (i + j) % 5 != 0)
	{
		suma += C[i][j];
		count++;
		C[i][j] = 0;
	}
	if (j < COL_COUNT - 1)
		Calc(C, ROW_COUNT, COL_COUNT, suma, count, i, j + 1);
	else
		if (i < ROW_COUNT - 1)
			Calc(C, ROW_COUNT, COL_COUNT, suma, count, i + 1, 0);
}
void Change(int** C, const int row1, const int row2, const int COL_COUNT, int j)
{
	int tmp = C[row1][j];
	C[row1][j] = C[row2][j];
	C[row2][j] = tmp;
	if (j < COL_COUNT - 1)
		Change(C, row1, row2, COL_COUNT, j + 1);
}
void Sort(int** C, const int ROW_COUNT, const int COL_COUNT, int j, int i0, int i1)
{
	if ((C[i1][0] < C[i1 + 1][0])
		||
		(C[i1][0] == C[i1 + 1][0] &&
			C[i1][1] < C[i1 + 1][1])
		||
		(C[i1][0] == C[i1 + 1][0] &&
			C[i1][1] == C[i1 + 1][1] &&
			C[i1][3] < C[i1 + 1][3]))
		Change(C, i1, i1 + 1, COL_COUNT, j);
	if (i1 < ROW_COUNT - i0 - 1)
		Sort(C, ROW_COUNT, COL_COUNT, j, i0, i1 + 1);
	else
		if (i0 < ROW_COUNT - 1)
			Sort(C, ROW_COUNT, COL_COUNT, j, i0 + 1, 0);
}