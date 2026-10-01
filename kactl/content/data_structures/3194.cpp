/**
 * Author: Team KACTL / Marce
 * Category: Data_structures
 * CSES Task ID: 3194
 * CSES Problem: Xor Pyramid Diagonal
 * Link: https://cses.fi/problemset/task/3194
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
 *   Given the bottom row of the pyramid, your task is to find the leftmost number of each row.
 *   Input
 *   The first line has an integer n: the size of the pyramid.
 *   The next line has n integers a_1,a_2,\dots,a_n: the bottom row of the pyramid.
 *   Output
 *   Print n integers: the leftmost numbers of the rows from bottom to top.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   1 \le a_i \le 10^9
 *   Example
 *   Input:
 *   8
 *   2 10 5 12 9 5 1 5
 *   Output:
 *   2 8 7 1 11 4 15 9
 */
#include <bits/stdc++.h>

using namespace std;

int a[2'000'000];
int dp[2'000'000];
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		dp[i] = a[i];		
	}
	
	
	for (int j = 0; j < 18; j++)
		for (int i = 0; i < n; i++)
			if ((i >> j) & 1)
				dp[i] ^= dp[i ^ (1 << j)];
	
	for (int i = 0; i < n; i++)
		cout << dp[i] << ' ';
	
	cout << endl;
	
	return 0;
}