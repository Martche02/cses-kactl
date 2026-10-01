#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll base = 1e9+7;
using u128 = __uint128_t;


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

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<ll>> a(n, vector<ll>(m+1));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m+1; j++)
			cin >> a[i][j];
		
	
	int c = -1;
	
	for (int atual = 0; atual < n; atual++)
	{
		bool hit = false;
		
		while (!hit && c < m-1)
		{
			c++;
			for (int j = atual; j < n; j++)
				if (a[j][c] != 0)
				{
					swap(a[atual], a[j]);
					hit = true;
					break;
				}
		}
		
		if (c == m) break;
		if (!hit) break;
		ll pivot = a[atual][c];
		
		ll ipivot = binpow(pivot, base-2, base);
		for (auto& i : a[atual])
			i = (i * ipivot) % base;
		
		for (int i = 0; i<n; i++)
		{
			if (i == atual) continue;
			auto& l = a[i];
			ll fator = l[c];
			for (int d = 0; d < m+1; d++)
				l[d] = (l[d] - (fator * a[atual][d])%base + base) % base;
		}
	}
	
	for (const auto& l : a)
	{
		bool blank = true;
		
		for (int j = 0; j < m; j++)
			if (l[j] != 0)
				blank = false;
		
		if (blank && l[m] != 0)
		{
			cout << -1 << endl;
			return 0;
		}
		
	}
	
	ll ans[m] = {};
	
	
	for (const auto& l : a)
	{
		for (int j = 0; j < m; j++)
			if (l[j] != 0)
			{
				ans[j] = l[m];
				break;
			}
		
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << (i == m ? '\n' : ' ');
	return 0;
}