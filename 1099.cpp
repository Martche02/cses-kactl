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
		bool usefull = false;
		while (s--)
		{
			int n;
			cin >> n;
			if (usefull)
				acc ^= n;
			
			usefull = !usefull;
		}
		
		cout << (acc ? "first\n" : "second\n");
	}
	
	return 0;
}