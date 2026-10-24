/**
 * Author: Team KACTL / Marce
 * Category: combinatorics
 * Source: 1725.cpp
 * CSES Task ID: 1725
 * CSES Problem: Dice Probability
 * Link: https://cses.fi/problemset/task/1725
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
 *   You throw a dice n times, and every throw produces an outcome between 1 and 6. What is the probability that the sum of outcomes is between a and b?
 *   Input
 *   The only input line contains three integers n, a and b.
 *   Output
 *   Print the probability rounded to six decimal places (rounding half to even).
 *   Constraints
 *   1 \le n \le 100
 *   1 \le a \le b \le 6n
 *   Example
 *   Input:
 *   2 9 10
 *   Output:
 *   0.194444
 */
#include <bits/stdc++.h>
using namespace std;

constexpr int top = 1e2+5;

double dp[top][6*top];

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	
	dp[0][0] = 1.0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6*i; j++)
			for (int k = 1; k <7; k++)
				if (j-k >= 0)
					dp[i][j] += dp[i-1][j-k] / 6.0;
			
			
	double ans = 0.0;
	for (int j = a; j<=b; j++)
		ans += dp[n][j];
	
	cout << fixed << setprecision(6) << ans << '\n';



	return 0;
}