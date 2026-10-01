#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u128 = __uint128_t;

// Exponenciação modular rápida (base^exp % mod)
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

bool is_prime(ll n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	
	ll s,d;
	s = __builtin_ctzll(n-1);
	d = (n-1) >> s;
	
	const ll primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
	
	for (auto p : primes)
	{
		if (n <= p) break;
		
		ll pot = binpow(p, d, n);
		if (pot == 1 || pot == n-1)
			continue;
		
		bool composto = true;
		
		for (ll r = 1; r < s; r++)
		{
			pot = (__uint128_t)pot * pot % n;
			if (pot == n-1)
			{
				composto = false;
				break;
			}
		}
		
		if (composto)
			return false;
	}
	
	return true;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		while (!is_prime(++n));
		cout << n << '\n';
	}

	return 0;
}