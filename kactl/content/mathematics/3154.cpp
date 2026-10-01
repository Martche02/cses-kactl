/**
 * Author: Team KACTL / Marce
 * Category: Mathematics
 * CSES Task ID: 3154
 * CSES Problem: System of Linear Equations
 * Link: https://cses.fi/problemset/task/3154
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
 *   You are given n\cdot(m+1) coefficients a_{i,j} and b_i which form the following n linear equations:
 *   a_{1,1}x_1 + a_{1,2}x_2 + \dots + a_{1,m}x_m = b_1 \pmod {10^9 + 7}
 *   a_{2,1}x_1 + a_{2,2}x_2 + \dots + a_{2,m}x_m = b_2 \pmod {10^9 + 7}
 *   \dots
 *   a_{n,1}x_1 + a_{n,2}x_2 + \dots + a_{n,m}x_m = b_n \pmod {10^9 + 7}
 *   Your task is to find any m integers x_1, x_2, \dots, x_m  that satisfy the given equations.
 *   Input
 *   The first line has two integers n and m: the number of equations and variables.
 *   The next n lines each have m+1 integers a_{i,1}, a_{i,2}, \dots, a_{i,m}, b_i: the coefficients of the i-th equation.
 *   Output
 *   Print m integers x_1, x_2,\dots, x_m: the values of the variables that satisfy the equations. The values must also satisfy 0 \le x_i < 10^9 + 7. You can print any valid solution. If no solution exists print only -1.
 *   Constraints
 *   1 \le n, m \le 500
 *   0 \le a_{i,j}, b_i < 10^9 + 7
 *   Example
 *   Input:
 *   3 3
 *   2 0 1 7
 *   1 2 0 0
 *   1 3 1 2
 *   Output:
 *   2 1000000006 3
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll base = 1e9+7;
using u128 = __uint128_t;


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

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<ll>> a(n, vector<ll>(m+1));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m+1; j++)
			cin >> a[i][j];
		
	
	int c = -1;
	
	for (int atual = 0; atual < n; atual++)
	{
		bool hit = false;
		
		while (!hit && c < m-1)
		{
			c++;
			for (int j = atual; j < n; j++)
				if (a[j][c] != 0)
				{
					swap(a[atual], a[j]);
					hit = true;
					break;
				}
		}
		
		if (c == m) break;
		if (!hit) break;
		ll pivot = a[atual][c];
		
		ll ipivot = binpow(pivot, base-2, base);
		for (auto& i : a[atual])
			i = (i * ipivot) % base;
		
		for (int i = 0; i<n; i++)
		{
			if (i == atual) continue;
			auto& l = a[i];
			ll fator = l[c];
			for (int d = 0; d < m+1; d++)
				l[d] = (l[d] - (fator * a[atual][d])%base + base) % base;
		}
	}
	
	for (const auto& l : a)
	{
		bool blank = true;
		
		for (int j = 0; j < m; j++)
			if (l[j] != 0)
				blank = false;
		
		if (blank && l[m] != 0)
		{
			cout << -1 << endl;
			return 0;
		}
		
	}
	
	ll ans[m] = {};
	
	
	for (const auto& l : a)
	{
		for (int j = 0; j < m; j++)
			if (l[j] != 0)
			{
				ans[j] = l[m];
				break;
			}
		
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << (i == m ? '\n' : ' ');
	return 0;
}