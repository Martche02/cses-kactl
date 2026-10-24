/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 1146.cpp
 * CSES Task ID: 1146
 * CSES Problem: Counting Bits
 * Link: https://cses.fi/problemset/task/1146
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
 *   Your task is to count the number of one bits in the binary representations of integers between 1 and n.
 *   Input
 *   The only input line has an integer n.
 *   Output
 *   Print the number of one bits in the binary representations of integers between 1 and n.
 *   Constraints
 *   1 \le n \le 10^{15}
 *   Example
 *   Input:
 *   7
 *   Output:
 *   12
 *   Explanation: The binary representations of 1 \ldots 7 are 1, 10, 11, 100, 101, 110, and 111, so there are a total of 12 one bits.
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long n, sum = 0;
	int k;
	cin >> n;
	
	while (n)
	{
		// se n = 2 ^ k
		// cout << (n)*k/2 + 1
		k = bit_width(n) - 1;
		n ^= (1LL << k);
		
		sum += (((1LL << k)*k) >>1) + 1;
		sum += n;
	}
	cout << sum << endl;
	
	return 0;
}