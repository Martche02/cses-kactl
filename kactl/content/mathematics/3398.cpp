/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 3398.cpp
 * CSES Task ID: 3398
 * CSES Problem: Permutation Rounds
 * Link: https://cses.fi/problemset/task/3398
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
 *   There is a sorted array [1,2,\dots,n] and a permutation p_1,p_2,\dots,p_n. On each round, all elements move according to the permutation: the element at position i moves to position p_i.
 *   After how many rounds is the array sorted again for the first time?
 *   Input
 *   The first line has an integer n.
 *   The next line contains n integers p_1,p_2,\dots,p_n.
 *   Output
 *   Print the number of rounds modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   Example
 *   Input:
 *   8
 *   5 3 2 6 4 1 8 7
 *   Output:
 *   4
 *   Explanation: The array changes as follows after the rounds:
 *   Round 1: [6,3,2,5,1,4,8,7]
 *   Round 2: [4,2,3,1,6,5,7,8]
 *   Round 3: [5,3,2,6,4,1,8,7]
 *   Round 4: [1,2,3,4,5,6,7,8]
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u128 = __uint128_t;

const int MAX_VAL = 2e5+5;
constexpr ll base = 1e9+7;
int spf[MAX_VAL];
int freq[MAX_VAL];


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

void crivo()
{
	for (int i = 0; i < MAX_VAL; i++)
		spf[i] = i;
	
	for (int i = 2; i*i < MAX_VAL; i++)
	{
		if (spf[i] != i)
			continue;
		for (int j = i * i; j < MAX_VAL; j+=i)
			if (spf[j] == j)
				spf[j] = i;
	}
}

void factorize(int n)
{
	while (n!=1)
	{
		int s = spf[n];
		int p = 0;
		while (n % s == 0)
		{
			p++;
			n /= s;
		}
		
		
		freq[s] = max(p, freq[s]);	
	}
}


int main()
{
	crivo();
	int n;
	cin >> n;
	
	vector<int> p(n);
	for (auto& i : p)
		cin >> i;
	
	vector<bool> vis (n, false);
	
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue;

		int ciclo = 0;
		int j = i;
		
		while (!vis[j])
		{
			vis[j] = true;
			j = p[j]-1;
			ciclo++;			
		}
		
		factorize(ciclo);
	}
	
	ll ret = 1;
	
	for (int i = 0; i < MAX_VAL; i++)
		ret = ((u128)ret * binpow(i, freq[i], base))%base;
	
	cout << ret << endl;
	
	return 0;
}