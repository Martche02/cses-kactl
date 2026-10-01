/**
 * Author: Team KACTL / Marce
 * Category: Mathematics
 * CSES Task ID: 2419
 * CSES Problem: Xor Pyramid Peak
 * Link: https://cses.fi/problemset/task/2419
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
 *   Given the bottom row of the pyramid, your task is to find the topmost number.
 *   Input
 *   The first line has an integer n: the size of the pyramid.
 *   The next line has n integers a_1,a_2,\dots,a_n: the bottom row of the pyramid.
 *   Output
 *   Print one integer: the topmost number.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   1 \le a_i \le 10^9
 *   Example
 *   Input:
 *   8
 *   2 10 5 12 9 5 1 5
 *   Output:
 *   9
 */
#include <bits/stdc++.h>

using namespace std;




int main()
{
	int n;
	cin >> n;
	
	int acc = 0;
	
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		if (((n-1) & i) == i)
			acc ^= val;
	}
	
	cout << acc << endl;
	return 0;
}