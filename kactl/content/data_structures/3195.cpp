/**
 * Author: Team KACTL / Marce
 * Category: data_structures
 * Source: 3195.cpp
 * CSES Task ID: 3195
 * CSES Problem: Xor Pyramid Row
 * Link: https://cses.fi/problemset/task/3195
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
 *   Consider a xor pyramid where each number is the xor of lower-left and lower-right numbers. Here is an example pyramid:
 *   Given the bottom row of the pyramid, your task is to find the numbers on the k-th row from the top.
 *   Input
 *   The first line has two integers n and k: the size of the pyramid and the given row.
 *   The next line has n integers a_1,a_2,\dots,a_n: the bottom row of the pyramid.
 *   Output
 *   Print k integers: the numbers on the k-th row from the top.
 *   Constraints
 *   1 \le k \le n \le 2 \cdot 10^5
 *   1 \le a_i \le 10^9
 *   Example
 *   Input:
 *   8 5
 *   2 10 5 12 9 5 1 5
 *   Output:
 *   1 10 5 1 8
 */
#include <bits/stdc++.h>

using namespace std;

int a[2'000'000];
int dp[2'000'000];
int main()
{
	int n, k, p;
	cin >> n >> k;
	p = n - k;
	
	int len = n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int bit = 0; (1 << bit) <= p; bit++)
	{
		if ((p >> bit) & 1)
		{
			int jump = 1 << bit;
			len -= jump;
			for (int i = 0; i < len; i++)
				a[i] ^= a[i + jump];		
		}		
	}
	
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	
	cout << endl;
	
	return 0;
}
