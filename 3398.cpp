#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u128 = __uint128_t;

const int MAX_VAL = 2e5+5;
constexpr ll base = 1e9+7;
int spf[MAX_VAL];
int freq[MAX_VAL];


ll binpow(ll base, ll exp, ll mod)
{
	ll res = 1;
	base %= mod;
	while (exp > 0)
	{
		if (exp % 2 == 1) res = (u128)res * base % mod;
		base = (u128)base * base % mod;
		exp /= 2;
	}
	return res;
}

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

void factorize(int n)
{
	while (n!=1)
	{
		int s = spf[n];
		int p = 0;
		while (n % s == 0)
		{
			p++;
			n /= s;
		}
		
		
		freq[s] = max(p, freq[s]);	
	}
}


int main()
{
	crivo();
	int n;
	cin >> n;
	
	vector<int> p(n);
	for (auto& i : p)
		cin >> i;
	
	vector<bool> vis (n, false);
	
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue;

		int ciclo = 0;
		int j = i;
		
		while (!vis[j])
		{
			vis[j] = true;
			j = p[j]-1;
			ciclo++;			
		}
		
		factorize(ciclo);
	}
	
	ll ret = 1;
	
	for (int i = 0; i < MAX_VAL; i++)
		ret = ((u128)ret * binpow(i, freq[i], base))%base;
	
	cout << ret << endl;
	
	return 0;
}