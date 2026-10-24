/**
 * Author: Team KACTL / Marce
 * Category: combinatorics
 * Source: 1717.cpp
 * CSES Task ID: 1717
 * CSES Problem: Christmas Party
 * Link: https://cses.fi/problemset/task/1717
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
 *   There are n children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought by someone else.
 *   In how many ways can the gifts be distributed?
 *   Input
 *   The only input line has an integer n: the number of children.
 *   Output
 *   Print the number of ways modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 10^6
 *   Example
 *   Input:
 *   4
 *   Output:
 *   9
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll base = 1e9+7;


int main()
{
	int n;
	cin >> n;
	
	ll D[n+1] = {};
	
	D[0] = 0;
	D[1] = 0;
	D[2] = 1;
	
	
	for (int i = 3; i < n+1; i++)
		D[i] = ((i-1) * (D[i-1] + D[i-2]) ) % base;
	
	
	cout << D[n] << endl;
	
	return 0;
}