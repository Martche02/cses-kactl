#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	int k;
	cin >> n >> k;
	
	vector<ll> a(k);
	
	for (auto& i : a)
		cin >> i;
	
	ll ans = 0;
	
	for (int mask = 1; mask < 1 << k; mask++)
	{
		ll divisores = 1;
		for (int i = 0; i < k; i++)
		{
			if ((1 << i) & mask)
			{
				if ((n / a[i]) >= divisores)
					divisores = divisores * a[i];
				else
					divisores = 0;
			}
		}
		if (divisores)
			ans += (__builtin_parity(mask) ? (n / divisores) : -(n / divisores));	
	}
	
	cout << ans << '\n';
	
	
	return 0;
}