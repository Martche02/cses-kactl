#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXM = 1000005;

array<int, MAXM> crivo()
{
	array<int, MAXM> tb{0};
	for (int i = 1; i < MAXM; i++)
	{
		int j = i;
		while (j < MAXM)
		{
			tb[j]++;
			j += i;
		}
	}
	return tb;
}

array<int, MAXM> tb = crivo();


int main()
{
	ll q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		cout << tb[x] << '\n';
	}
	
	return 0;
}