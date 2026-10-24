/**
 * Author: Team KACTL / Marce
 * Category: strings
 * Source: 1753.cpp
 * CSES Task ID: 1753
 * CSES Problem: String Matching
 * Link: https://cses.fi/problemset/task/1753
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
 *   Given a string and a pattern, your task is to count the number of positions where the pattern occurs in the string.
 *   Input
 *   The first input line has a string of length n, and the second input line has a pattern of length m. Both of them consist of characters a-z.
 *   Output
 *   Print one integer: the number of occurrences.
 *   Constraints
 *   1 \le n,m \le 10^6
 *   Example
 *   Input:
 *   saippuakauppias
 *   pp
 *   Output:
 *   2
 */
#include <bits/stdc++.h>

using namespace std;

int main ()
{
	string s, p;
	
	cin >> s >> p;
	
	string z = p + "#" + s;
	
	int L = 0, R = 0;
	
	vector<int> pre(z.size(), 0);
	int rep = 0;
	
	for (int i = 1; i < z.size(); i++)
	{
		if (i <= R)
			pre[i] = min(pre[i-L], R-i+1);
		
		while (i + pre[i] < z.size() && z[i + pre[i]] == z[pre[i]])
			pre[i]++;
		
		if (i + pre[i] > R + 1)
		{
			L = i;
			R = i + pre[i] - 1;
		}
		
		
		if (pre[i] == p.size())
			rep++;
	}
	
	cout << rep << '\n';
	
	return 0;
}