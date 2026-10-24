/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 3355.cpp
 * CSES Task ID: 3355
 * CSES Problem: Sum of Four Squares
 * Link: https://cses.fi/problemset/task/3355
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
 *   A well known result in number theory is that every non-negative integer can be represented as the sum of four squares of non-negative integers.
 *   You are given a non-negative integer n. Your task is to find four non-negative integers a, b, c and d such that n = a^2 + b^2 + c^2 + d^2.
 *   Input
 *   The first line has an integer t: the number of test cases.
 *   Each of the next t lines has an integer n.
 *   Output
 *   For each test case, print four non-negative integers a, b, c and d that satisfy n = a^2 + b^2 + c^2 + d^2.
 *   Constraints
 *   1 \le t \le 1000
 *   0 \le n \le 10^7
 *   the sum of all n is at most 10^7
 *   Example
 *   Input:
 *   3
 *   5
 *   30
 *   322266
 *   Output:
 *   2 1 0 0
 *   1 2 3 4
 *   314 159 265 358
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll top = 1e7+1;
constexpr ll sqr = 3162;
pair<ll,ll> par[top];


int main()
{
	for (auto& i : par)
		i = {sqr+1, sqr+1};
	for (int a = 0; a <= sqr; a++)
		for (int b = 0; b <= sqr; b++)
			if (a*a+b*b < top)
				par[a*a+b*b] = {a, b};
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		for (int i = 0; i <= n; i++)
			if (par[i].first != sqr+1 && par[n-i].first != sqr+1)
			{
				cout << par[i].first << ' ' << par[i].second << ' ' << par[n-i].first << ' ' << par[n-i].second << '\n';
				break;
			}
	}
	

	return 0;
}