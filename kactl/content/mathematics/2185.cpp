/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 2185.cpp
 * CSES Task ID: 2185
 * CSES Problem: Prime Multiples
 * Link: https://cses.fi/problemset/task/2185
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
 *   You are given k distinct prime numbers a_1,a_2,\ldots,a_k and an integer n.
 *   Your task is to calculate how many of the first n positive integers are divisible by at least one of the given prime numbers.
 *   Input
 *   The first input line has two integers n and k.
 *   The second line has k prime numbers a_1,a_2,\ldots,a_k.
 *   Output
 *   Print one integer: the number integers within the interval 1,2,\ldots,n that are divisible by at least one of the prime numbers.
 *   Constraints
 *   1 \le n \le 10^{18}
 *   1 \le k \le 20
 *   2 \le a_i \le n
 *   Example
 *   Input:
 *   20 2
 *   2 5
 *   Output:
 *   12
 *   Explanation: the 12 numbers are 2,4,5,6,8,10,12,14,15,16,18,20.
 */
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