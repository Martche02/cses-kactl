#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u128 = __uint128_t;

const ll base = 1e9+7;
const ll top = 3*(1e6+15);

ll fat[top];
ll ifat[top];

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

void calculateFat()
{
	fat[0] = 1;
	ifat[0] = 1;
	for (int i = 1; i < top; i++)
		fat[i] = (fat[i-1]*i)%base;
	
	ifat[top-1] = binpow(fat[top-1], base-2, base);
	
	for (int i = top-1; i > 0; i--)
		ifat[i-1] = (ifat[i]*i)%base;
}

ll newton(int a, int b)
{
	return (fat[a] * ifat[b]) % base;
}

int main()
{
	calculateFat();
	int n;
	cin >> n;
	if (n%2 == 1) 
	{
		cout << 0 << endl;
		return 0;
	}
	int k = n/2;
	
	
	cout << (((fat[n] * ifat[k])%base) * ifat[k+1])%base << endl;
	
	return 0;
}