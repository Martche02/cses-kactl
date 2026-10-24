/**
 * Author: Team KACTL / Marce
 * Category: combinatorics
 * Source: 1716.cpp
 * CSES Task ID: 1716
 * CSES Problem: Distributing Apples
 * Link: https://cses.fi/problemset/task/1716
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
 *   There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.
 *   For example, if n=3 and m=2, there are 6 ways: [0,0,2], [0,1,1], [0,2,0], [1,0,1], [1,1,0] and [2,0,0].
 *   Input
 *   The only input line has two integers n and m.
 *   Output
 *   Print the number of ways modulo 10^9+7.
 *   Constraints
 *   1 \le n,m \le 10^6
 *   Example
 *   Input:
 *   3 2
 *   Output:
 *   6
 */
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
	
	int n, m;
	cin >> n >> m;
	
	cout << (((fat[n - 1 + m] * ifat[n-1]) % base) * ifat[m]) % base << endl;
	
	return 0;
}