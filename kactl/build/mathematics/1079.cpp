/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 1079.cpp
 * CSES Task ID: 1079
 * CSES Problem: Binomial Coefficients
 * Link: https://cses.fi/problemset/task/1079
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
 *   Your task is to calculate n binomial coefficients modulo 10^9+7.
 *   A binomial coefficient {a \choose b} can be calculated using the formula \frac{a!}{b!(a-b)!}. We assume that a and b are integers and 0 \le b \le a.
 *   Input
 *   The first input line contains an integer n: the number of calculations.
 *   After this, there are n lines, each of which contains two integers a and b.
 *   Output
 *   Print each binomial coefficient modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 10^5
 *   0 \le b \le a \le 10^6
 *   Example
 *   Input:
 *   3
 *   5 3
 *   8 1
 *   9 5
 *   Output:
 *   10
 *   8
 *   126
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u128 = __uint128_t;

const ll base = 1e9+7;
const ll top = 1e6+15;

ll fat[top];
ll ifat[top];

ll binpow(ll base, ll exp, ll mod)(*@\label{fn1}@*)
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
	fat[0] = 1;
	ifat[0] = 1;
	for (int i = 1; i < top; i++)
		fat[i] = (fat[i-1]*i)%base;
	
	ifat[top-1] = binpow(fat[top-1], base-2, base);
	
	for (int i = top-1; i > 0; i--)
		ifat[i-1] = (ifat[i]*i)%base;
	
	int n;
	cin >> n;
	
	while (n--)
	{
		ll a,b;
		cin >> a >> b;
		
		cout << (((fat[a]*ifat[b])%base ) * ifat[a-b])%base << '\n'	;
		
	}
	
	return 0;
}