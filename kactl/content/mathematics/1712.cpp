/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 1712.cpp
 * CSES Task ID: 1712
 * CSES Problem: Exponentiation II
 * Link: https://cses.fi/problemset/task/1712
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
 *   Your task is to efficiently calculate values a^{b^c} modulo 10^9+7.
 *   Note that in this task we assume that 0^0=1.
 *   Input
 *   The first input line has an integer n: the number of calculations.
 *   After this, there are n lines, each containing three integers a, b and c.
 *   Output
 *   Print each value a^{b^c} modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 10^5
 *   0 \le a,b,c \le 10^9
 *   Example
 *   Input:
 *   3
 *   3 7 1
 *   15 2 2
 *   3 4 5
 *   Output:
 *   2187
 *   50625
 *   763327764
 */
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