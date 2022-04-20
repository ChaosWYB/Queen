//��������ٷ�
//61619113���岩 //61619201�¼һ�
//���岩��������麯��+change����
//�¼һԣ���ʼ�������ʹ�ӡ����

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
	cout << "���������̽���" << endl;
	cin >> N;
	//������̬����,���ڼ�¼����λ��
	board = new int[N];
	//�����ʼ��
	for (int i = 0;i < N;++i)
	{
		board[i] = i;
	}
	//������̬���飬���ڼ�¼�����Ƿ�������
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
	cout << "��" << num << "���⣺" << endl;
	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;++j)
		{
			if (board[i] == j)
				cout << "��";
			else
				cout << "��";
		}
		cout << endl;
	}
}

void free()
{
	delete[] board;
	delete[] save;
}