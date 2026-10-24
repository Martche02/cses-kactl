/**
 * Author: Team KACTL / Marce
 * Category: dynamic_programming
 * Source: 1634.cpp
 * CSES Task ID: 1634
 * CSES Problem: Minimizing Coins
 * Link: https://cses.fi/problemset/task/1634
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
 *   Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
 *   For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
 *   Input
 *   The first input line has two integers n and x: the number of coins and the desired sum of money.
 *   The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
 *   Output
 *   Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
 *   Constraints
 *   1 \le n \le 100
 *   1 \le x \le 10^6
 *   1 \le c_i \le 10^6
 *   Example
 *   Input:
 *   3 11
 *   1 5 7
 *   Output:
 *   3
 */
#include <bits/stdc++.h>
#define GET(type, name) type name; cin >> name(*@\label{fn9}@*)
using namespace std;

constexpr int macs = 1e6+5+5;
int dp[macs-2];

int main()
{
	GET(int, n);
	GET(int, x);
	
	vector<int> C(n);
	
	for (auto& c : C)
		cin >> c;
	
	dp[0] = 0;
	
	for (int i = 1; i <= x; i++)
	{
		dp[i] = macs;
		for (const auto& c : C)
			if (i - c >= 0)
				dp[i] = min(dp[i], dp[i-c] + 1);
		
	}
	
	int& v = dp[x];
	cout << (v == macs ? -1 : v) << '\n';



	return 0;
}