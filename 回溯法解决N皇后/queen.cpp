#include<iostream>
#define N 100

using namespace std;

int n, ans[N], m, sum = 0;
bool zh[N], xie1[N << 1], xie2[N << 1];

void pri()
{
	for (int i = 1; i <= n; putchar('\n'), ++i)
		for (int j = 1; j <= n; ++j)
			if (ans[i] == j)cout << "1 ";
			else cout << "0 ";
	cout << endl;
}
void dfs(int x)
{
	for (int i = 1; i <= n; ++i)
		if (!(zh[i] || xie1[x + i] || xie2[x - i + n]))
		{
			ans[x] = i;
			zh[i] = xie1[x + i] = xie2[x - i + n] = 1;
			if (x == n)
			{
				sum++;
				pri();
			}
			else dfs(x + 1);
			zh[i] = xie1[x + i] = xie2[x - i + n] = 0;
		}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << sum << endl;
	return 0;
}