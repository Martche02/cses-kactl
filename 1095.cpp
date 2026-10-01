#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll base = 1e9+7;

#define MOD(v) ( ((v%base) + base)%base )

ll exp(ll a, ll b)
{
	ll res = 1;
	while (b > 0)
	{
		if (b&1)
			res = MOD(a*res);
		
		a = MOD(a*a);
		
		b >>= 1;
	}
	
	return res;
}


int main()
{
	ll q;
	cin >> q;
	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << exp(a, b) << '\n';
	}
	
	return 0;
}