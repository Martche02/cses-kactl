#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll top = 1222+5;
ll grundy[top];


int main()
{
	
	for (int i = 0; i < top; i++)
	{
		vector<bool> mex(top, true);
		for (int j = 1; j <= i; j++)
		{
			if (j == i-j || i-j == 0)
				continue;
			mex[grundy[j] ^ grundy[i-j]] = false;			
		}
		
		
		ll valor;
		for (valor = 0; valor < i+1; valor++)
			if (mex[valor])
				break;
			
		grundy[i] = valor;		
	}
	
	
	
	int testes;
	cin >> testes;
	while (testes--)
	{
		int s;
		cin >> s;
		if (s >= top)
		{
			cout << "first\n";
			continue;
		}
		
		cout << ((grundy[s]) != 0 ? "first\n" : "second\n");
	}
	
	return 0;
}