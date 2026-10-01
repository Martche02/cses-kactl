#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll base = 1e9+7;
using u128 = __uint128_t;

struct Matrix
{
	ll m[2][2];
	
	void mod(ll base)
	{
		for (auto& l : m)
			for (auto& c : l)
				c %= base;
	}	
	
	void prod(const Matrix& p, ll base)
	{
		Matrix c{0,0,0,0};
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					c.m[i][j] = (c.m[i][j] + (u128)(m[i][k]) * p.m[k][j]) % base;
				
		*this = c;
	}
};

Matrix binpow(Matrix base, ll exp, ll mod)
{
	Matrix res = {1,0,0,1};
	base.mod(mod);
	
	while (exp > 0)
	{
		if (exp % 2 == 1) 
			res.prod(base, mod);
		base.prod(base, mod);
		exp /= 2;
	}
	return res;
}

int main()
{
	ll n;
	cin >> n;
	
	// ( 1, 1) * (Fn-1) = (Fn-1 + fn-2 ) = (Fn  )
	// ( 1, 0) * (Fn-2) = (Fn-1)         = (Fn-1)

	Matrix fib = {1,1,1,0};
	
	fib = binpow(fib, n, base);
	
	cout << fib.m[0][1] 
		 << endl;
	


}