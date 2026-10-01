/**
 * Author: Team KACTL / Marce
 * Category: Strings
 * CSES Task ID: 3138
 * CSES Problem: All Palindromes
 * Link: https://cses.fi/problemset/task/3138
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
 *   Given a string, calculate for each position the length of the longest palindrome that ends at that position.
 *   Input
 *   The only line contains a string of length n. Each character is one of a-z.
 *   Output
 *   Print n numbers: the length of each palindrome.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   Example
 *   Input:
 *   ababbababaa
 *   Output:
 *   1 1 3 3 2 4 6 8 5 5 2
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string s;
	
	cin >> s;
	
	string M(2 * s.size() + 1, '#');
	
	int n = 0;
	
	for (int i = 0; i < s.size(); i++)
		M[2*i + 1] = s[i];
	
	vector<int> P(M.size(), 0);
	
	int R, C;
	
	R = C = 0;
	
	for (int i = 0; i < M.size(); i++)
	{		
		if (i < R)
			P[i] = min(P[2 * C - i], R-i);
		
		while( (i-P[i]-1 >=0) && (i+P[i]+1 < M.size())
			&& M[i-P[i]-1] == M[i+P[i]+1])			
			P[i]++;
		
		if (i+P[i] > R)
		{
			R = i+P[i];
			C = i;
		}
		
	}
	
	//E[i+P[i]] = max(E[i+P[i]], P[i]);
	
	vector<int> E(s.size(), 1);
	
	for (int i = 0; i < M.size(); i++)
	{
		if (P[i] <=0) continue;
		int fim = (i + P[i])/2-1;
		E[fim] = max(E[fim], P[i]);
	}
	
	
	for (int i = E.size()-1; i >= 1; i--)
	{
		E[i-1] = max(E[i-1], E[i]-2);
	}
	
	for (const auto& e : E)
		cout << e << ' ';
	
	cout << endl;
	
	return 0;
}
