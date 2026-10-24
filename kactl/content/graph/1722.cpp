/**
 * Author: Team KACTL / Marce
 * Category: graph
 * Source: 1722.cpp
 * CSES Task ID: 1722
 * CSES Problem: Fibonacci Numbers
 * Link: https://cses.fi/problemset/task/1722
 * Description:
 *   addEventListener("DOMContentLoaded", function (e) {
 *   const mathElements = document.getElementsByClassName("math");
 *   const macros = {};
 *   for (let element of mathElements) {
 *   katex.render(element.textContent, element, {
 *   displayMode: element.classList.contains("math-display"),
 *   throwOnError: false,
 *   globalGroup: true,
 *   macros,
 *   });
 *   }
 *   });
 *   .katex .base:last-child {
 *   display: inline;
 *   }
 *   Time limit: 1.00 s
 *   Memory limit: 512 MB
 *   The Fibonacci numbers can be defined as follows:
 *   F_0=0
 *   F_1=1
 *   F_n = F_{n-2}+F_{n-1}
 *   Your task is to calculate the value of F_n for a given n.
 *   Input
 *   The only input line has an integer n.
 *   Output
 *   Print the value of F_n modulo 10^9+7.
 *   Constraints
 *   0 \le n \le 10^{18}
 *   Example
 *   Input:
 *   10
 *   Output:
 *   55
 */
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