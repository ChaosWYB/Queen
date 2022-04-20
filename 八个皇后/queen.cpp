//作者 61619113王彦博  61619201陈家辉
#include<iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;
int N = 0;
int err_min = 0, err = 0;
int a = 0, b = 0;
int* board = nullptr;
void creat();
bool judge();
void exchange();
void print();
int main()
{
	creat();
	unsigned long long t1 = GetTickCount64();
	while (!judge())
	{
		exchange();
	}
	unsigned long long t2 = GetTickCount64();
	print();
	cout << "计算用时：" << (t2 - t1) * 1.0 / 1000 << "s" << endl;
	return 0;
}
void creat()
{
	srand(unsigned(time(NULL)));
	cout << "请输入棋盘阶数" << endl;
	cin >> N;
	err_min = N;
	board = new int[N];
	for (int i = 0; i < N; ++i)
	{
		board[i] = i;
	}
	return;
}
bool judge()
{
	bool ok = true;
	err = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (abs(j - i) == abs(board[i] - board[j]))
			{
				++err;
				a = i;
				ok = false;
			}
		}
	}
	return ok;
}
void exchange()
{
	int temp = 0, m = 0, n = 0;
	for (;;)
	{
		for (;;)
		{
			//m = rand() % N;
			n = rand() % N;
			if (a != n)
				break;
		}
		temp = board[a];
		board[a] = board[n];
		board[n] = temp;
		judge();
		if (err < err_min || err_min == 0)
		{
			err_min = err;
			break;
		}
		else
		{
			temp = board[a];
			board[a] = board[n];
			board[n] = temp;
		}
	}
	return;
}
void print()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i] == j)
				cout << "★";
			else
				cout << "█";
		}
		cout << endl;
	}
	delete[] board;
}