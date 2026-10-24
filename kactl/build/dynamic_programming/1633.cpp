/**
 * Author: Team KACTL / Marce
 * Category: dynamic_programming
 * Source: 1633.cpp
 * CSES Task ID: 1633
 * CSES Problem: Dice Combinations
 * Link: https://cses.fi/problemset/task/1633
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
 *   Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
 *   For example, if n=3, there are 4 ways:
 *   1+1+1
 *   1+2
 *   2+1
 *   3
 *   Input
 *   The only input line has an integer n.
 *   Output
 *   Print the number of ways modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 10^6
 *   Example
 *   Input:
 *   3
 *   Output:
 *   4
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7;
constexpr int top = 1e6+5;

ll dp[top];

int main()
{
	int n;
	cin >> n;
	
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++)
		for (int k = 1; k < 7; k++)
			if (i-k >= 0)
				dp[i] = (dp[i] + dp[i-k]) % MOD;
			
			
	cout << dp[n] << '\n';



	return 0;
}