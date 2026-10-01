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
		bool impar = false;
		while (s--)
		{
			int n;
			cin >> n;
			if (n%2)
				impar = true;
		}
		
		cout << (impar ? "first\n" : "second\n");
	}
	
	return 0;
}