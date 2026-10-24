/**
 * Author: Team KACTL / Marce
 * Category: strings
 * Source: 1731.cpp
 * CSES Task ID: 1731
 * CSES Problem: Word Combinations
 * Link: https://cses.fi/problemset/task/1731
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
 *   You are given a string of length n and a dictionary containing k words. In how many ways can you create the string using the words?
 *   Input
 *   The first input line has a string containing n characters between a-z.
 *   The second line has an integer k: the number of words in the dictionary.
 *   Finally there are k lines describing the words. Each word is unique and consists of characters a-z.
 *   Output
 *   Print the number of ways modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 5000
 *   1 \le k \le 10^5
 *   the total length of the words is at most 10^6
 *   Example
 *   Input:
 *   ababc
 *   4
 *   ab
 *   abab
 *   c
 *   cb
 *   Output:
 *   2
 *   Explanation: The possible ways are ab+ab+c and abab+c.
 */
#include <bits/stdc++.h>
using namespace std;


struct Node
{
	bool fim;
	int filhos[26];
	
	Node ()
		: fim(false)(*@\label{fn28}@*)
	{
		fill(filhos, filhos + 26, -1);
	}
};

vector<Node> trie;

void insert(string& s)(*@\label{fn29}@*)
{
	int u = 0;
	
	for (auto c : s)
	{
		int id = c - 'a';
		
		if (trie[u].filhos[id] == -1)
		{
			trie[u].filhos[id] = trie.size();
			trie.emplace_back();
		}

		u = trie[u].filhos[id];		
	}
	
	trie[u].fim = true;	
}

int main()
{
	string s;
	int k;
	cin >> s >> k;
	
	trie.emplace_back();
	
	while(k--)
	{
		string palavra;
		cin >> palavra;
		insert(palavra);
	}
	
	
	int n = s.size();
	
	long long MOD = 1e9+7;
	
	vector<long long> dp(n+1, 0);
	
	dp[n] = 1;
	
	for (int i = n-1; i >= 0; i--)
	{
		int u = 0;
		
		for (int j = i; j < n; j++)
		{
			int id = s[j] - 'a';
			
			if (trie[u].filhos[id] == -1)
				break;
			
			u = trie[u].filhos[id];
			
			if (trie[u].fim)
				dp[i] = (dp[i] + dp[j+1])%MOD;
		}
	}
	
	cout << dp[0] << endl;

	return 0;
}
