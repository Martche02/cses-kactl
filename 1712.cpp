#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll bb = 1e9+7;

#define MOD(v, base) ( ((v%base) + base)%base )

ll exp(ll a, ll b, ll base)
{
	ll res = 1;
	while (b > 0)
	{
		if (b&1)
			res = MOD(a*res, base);
		
		a = MOD(a*a, base);
		
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
		ll a, b, c;
		cin >> a >> b >> c;
		cout << exp(a, exp(b, c, bb-1), bb) << '\n';
	}
	
	return 0;
}