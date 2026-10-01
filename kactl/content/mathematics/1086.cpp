/**
 * Author: Team KACTL / Marce
 * Category: Mathematics
 * CSES Task ID: 1086
 * CSES Problem: Writing Numbers
 * Link: https://cses.fi/problemset/task/1086
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
 *   You would like to write a list of positive integers 1,2,3,\ldots using your computer. However, you can press each key 0-9 at most n times during the process.
 *   What is the last number you can write?
 *   Input
 *   The only input line contains the value of n.
 *   Output
 *   Print the last number you can write.
 *   Constraints
 *   1 \le n \le 10^{18}
 *   Example
 *   Input:
 *   5
 *   Output:
 *   12
 *   Explanation: You can write the numbers 1,2,\ldots,12. This requires that you press key 1 five times, so you cannot write the number 13.
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	
	while (n != 1)
	{
		cout << n << ' ';
		if ((n&1) == 0)
			n>>=1;
		else
			n = 3*n + 1;
	}
	
	cout << '1' << endl;
	
	
}