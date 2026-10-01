#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_VAL = 1000005;
int spf[MAX_VAL];
int freq[MAX_VAL];
bool impar[MAX_VAL];


void crivo()
{
	for (int i = 0; i < MAX_VAL; i++)
		spf[i] = i;
	
	for (int i = 2; i*i < MAX_VAL; i++)
	{
		if (spf[i] != i)
			continue;
		for (int j = i * i; j < MAX_VAL; j+=i)
			if (spf[j] == j)
				spf[j] = i;
	}
}

vector<int> factorize(int n)
{
	vector<int> fac;
	while (n!=1)
	{
		int s = spf[n];
		fac.emplace_back(s);
		while (n % s == 0)
			n /= s;
	}
	
	return fac;
}


int main()
{
	crivo();
	int n;
	cin >> n;
	for (int idx = 0; idx < n; idx++)
	{
		int x;
		cin >> x;
		vector<int> a = factorize(x);
		
		int k = a.size();
		
		
		for (int mask = 1; mask < 1 << k; mask++)
		{
			ll divisores = 1;
			for (int i = 0; i < k; i++)
			{
				if ((1 << i) & mask)
					divisores *= a[i];
			}
			
			freq[divisores]++;
			
			impar[divisores] = __builtin_parity(mask);
		}
		
		
	}
	
	ll total_pares = 0;
	
	for (int i = 0; i < MAX_VAL; i++)
		total_pares += (impar[i] ? 1 : -1)*(ll)freq[i]*((ll)freq[i]-1)/2;
	
	cout << (ll)n*(n-1)/2 - total_pares << endl;

	return 0;
}