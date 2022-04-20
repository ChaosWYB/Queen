#include<iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;

int error();
void solve();
void print();

int N = 0, n = 0, m = 0;
int* board = nullptr;
int err_1 = 0, err_min = 0;

int main()
{
	solve();
	print();
	return 0;
}

int error()
{
	int err = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (j - i == abs(board[i] - board[j]))
				++err;
		}
	}
	return err;
}

void solve()
{
	srand(unsigned(time(NULL)));
	cout << "ÇëÊäÈëÆåÅÌ½×Êý" << endl;
	cin >> N;
	board = new int[N];
	err_min = N;
	for (int i = 0; i < N; ++i)
	{
		board[i] = i;
	}
	err_min = error();
	do
	{
		m = rand() % N;
		do
		{
			n = rand() % N;
		} while (m == n);
		swap(board[m], board[n]);
		err_1=error();
		if (err_1 <= err_min)
		{
			err_min = err_1;
		}
		else
		{
			swap(board[m],board[n]);
		}
	} while (err_min != 0);
}

void print()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i] == j)
				cout << "¡ï";
			else
				cout << "¨€";
		}
		cout << endl;
	}
	delete[] board;
}