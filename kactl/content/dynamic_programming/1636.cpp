/**
 * Author: Team KACTL / Marce
 * Category: dynamic_programming
 * Source: 1636.cpp
 * CSES Task ID: 1636
 * CSES Problem: Coin Combinations II
 * Link: https://cses.fi/problemset/task/1636
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
 *   Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
 *   For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:
 *   2+2+5
 *   3+3+3
 *   2+2+2+3
 *   Input
 *   The first input line has two integers n and x: the number of coins and the desired sum of money.
 *   The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
 *   Output
 *   Print one integer: the number of ways modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 100
 *   1 \le x \le 10^6
 *   1 \le c_i \le 10^6
 *   Example
 *   Input:
 *   3 9
 *   2 3 5
 *   Output:
 *   3
 */
#include <bits/stdc++.h>
#define GET(type, name) type name; cin >> name
using namespace std;

constexpr int macs = 1e6+5+5;
int dp[macs-2];
constexpr int MOD = 1e9+7;

int main()
{
	GET(int, n);
	GET(int, x);
	
	vector<int> C(n);
	
	for (auto& c : C)
		cin >> c;
	
	for (const auto& c : C)
	{
		dp[c]++;
		for (int i = 1; i <= x; i++)
			if (i-c >= 0)
				dp[i] = (dp[i] + dp[i-c])%MOD;
	}
			
	cout << dp[x] << '\n';



	return 0;
}