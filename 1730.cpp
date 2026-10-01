#include <bits/stdc++.h>
using namespace std;

int main()
{
	int testes;
	cin >> testes;
	while (testes--)
	{
		int s;
		cin >> s;
		int acc = 0;
		while (s--)
		{
			int n;
			cin >> n;
			acc ^= (n%4);
		}
		
		cout << (acc ? "first\n" : "second\n");
	}
	
	return 0;
}