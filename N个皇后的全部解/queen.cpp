//方法：穷举法
//61619113王彦博 //61619201陈家辉
//王彦博：两个检查函数+change函数
//陈家辉：初始化函数和打印函数

#include<iostream>
#include<iomanip>

using namespace std;

int N = 0, num = 0;
int* board = nullptr;
bool* save = nullptr;
void initialize();
bool check_1();
bool check_2();
void change();
void print();
void free();

int main()
{
	initialize();
	for (;;)
	{
		change();
		if (check_2())
			break;
		if (check_1())
		{
			print();
		}
	}
	free();
	return 0;
}

void initialize()
{
	cout << "请输入棋盘阶数" << endl;
	cin >> N;
	//创建动态数组,用于记录棋子位置
	board = new int[N];
	//数组初始化
	for (int i = 0;i < N;++i)
	{
		board[i] = i;
	}
	//创建动态数组，用于记录行上是否有棋子
	save = new bool[N];
	int temp = 0;
	temp = board[N - 2];
	board[N - 2] = board[N - 1];
	board[N - 1] = temp;
	return;
}

bool check_1()
{
	for (int i = 0;i < N;++i)
	{
		for (int j = i + 1;j < N;++j)
		{
			if (abs(j - i) == abs(board[i] - board[j]))
				return false;
		}
	}
	++num;
	return true;
}

bool check_2()
{
	if (board[0] > N - 1)
		return true;
	else
		return false;
}

void change()
{
	for (;;)
	{
		++board[N - 1];
		for (int i = N - 1;i > 0;--i)
		{
			if (board[i] > N - 1)
			{
				++board[i - 1];
				board[i] = 0;
			}
		}
		if (board[0] > N - 1)
		{
			return;
		}
		for (int i = 0;i < N;++i)
		{
			save[i] = false;
		}
		for (int i = 0;i < N;++i)
		{
			save[board[i]] = true;
		}
		bool ok = true;
		for (int i = 0;i < N;++i)
		{
			if (!save[i])
			{
				ok = false;
				break;
			}
		}
		if (ok)
			break;
	}
}

void print()
{
	cout << "第" << num << "个解：" << endl;
	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;++j)
		{
			if (board[i] == j)
				cout << "★";
			else
				cout << "█";
		}
		cout << endl;
	}
}

void free()
{
	delete[] board;
	delete[] save;
}