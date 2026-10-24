/**
 * Author: Team KACTL / Marce
 * Category: strings
 * Source: 1112.cpp
 * CSES Task ID: 1112
 * CSES Problem: Required Substring
 * Link: https://cses.fi/problemset/task/1112
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
 *   Your task is to calculate the number of strings of length n having a given pattern of length m as their substring. All strings consist of characters A-Z.
 *   Input
 *   The first input line has an integer n: the length of the final string.
 *   The second line has a pattern of length m.
 *   Output
 *   Print the number of strings modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 1000
 *   1 \le m \le 100
 *   Example
 *   Input:
 *   6
 *   ABCDB
 *   Output:
 *   52
 *   Explanation: The final string will be of the form ABCDBx or xABCDB where x is any character between A-Z.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1e9+7;
int main()
{
	
	int n;
	cin >> n;
	string padrao;
	cin >> padrao;
	
	int m = padrao.size();
	
	vector<int> pi(m, 0);
	
	//kpm pi
	for (int i = 1; i < m; i++)
	{
		int j = pi[i-1];
		
		while (j > 0 && padrao[i] != padrao[j])
			j = pi[j-1];
		
		if (padrao[i] == padrao[j])
			j++;
		
		pi[i] = j;
	}
	
	vector<vector<int>> prox_estado(m, vector<int>('z'-'a'+1, 0));
	
	for (int i = 0; i < m; i++)
	{
		for (char c = 'A'; c <= 'Z'; c++)
		{
			
			int j = i;
			
			while (j > 0 && c != padrao[j])
				j = pi[j-1];
			
			if (c == padrao[j])
				j++;
			
			prox_estado[i][c-'A'] = j;
		}
	}
	
	vector<vector<ll>> dp(n+1, vector<ll>(m+1));
	dp[0][0] = 1;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (char c = 'A'; c <= 'Z'; c++)
			{
				int k = prox_estado[j][c-'A'];
				dp[i+1][k] = (dp[i][j] + dp[i+1][k]) % MOD;
			}			
		}
		
		dp[i+1][m] = (dp[i+1][m] + 26*dp[i][m]) % MOD;
	}
	
	cout << dp[n][m] << endl;

	return 0;
}