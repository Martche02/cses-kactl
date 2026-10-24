/**
 * Author: Team KACTL / Marce
 * Category: strings
 * Source: 1111_2.cpp
 * CSES Task ID: 1111
 * CSES Problem: Longest Palindrome (v2)
 * Link: https://cses.fi/problemset/task/1111
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
 *   Given a string, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in aybabtu is bab.
 *   Input
 *   The only input line contains a string of length n. Each character is one of a-z.
 *   Output
 *   Print the longest palindrome in the string. If there are several solutions, you may print any of them.
 *   Constraints
 *   1 \le n \le 10^6
 *   Example
 *   Input:
 *   aybabtu
 *   Output:
 *   bab
 */
#include <bits/stdc++.h>

using namespace std;

struct StringHash
{
    long long P = 313;
    long long MOD = 1e9 + 7;
    vector<long long> h, p;

    // O construtor já pré-calcula os hashes de prefixo e as potências em O(N)
    StringHash(const string& s)
	{
        int n = s.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
		
        for (int i = 0; i < n; i++)
		{
            p[i + 1] = (p[i] * P) % MOD;
            h[i + 1] = (h[i] * P + s[i]) % MOD;
        }
    }

    // Retorna o hash da substring s[L...R] em O(1)
    // L e R são índices originais da string (0-indexados)
    long long get(int L, int R)
	{
        long long res = (h[R + 1] - h[L] * p[R - L + 1]) % MOD;
        if (res < 0) 
			res += MOD;
        return res;
    }
};

int main()
{
	string s;
	
	cin >> s;
	
	string T(2*s.size()+1, '#');
	
	int n = 0;
	
	for (int i = 0; i < s.size(); i++)
		T[2*i + 1] = s[i];
	
	int big=0;
	pair<int, int> pal;
	StringHash S(T);
	reverse(T.begin(), T.end());
	StringHash S_1(T);
	reverse(T.begin(), T.end());
	
	for (int i = 0; i < T.size(); i++)
	{
		int low = 0;
		int top = min(i, static_cast<int>(T.size())-i-1);
		int mid;
		int midOld = 0	;
		while (low <= top)
		{
			mid = low + (top - low)/2;
			if (S.get(i, i + mid) == S_1.get(T.size() - i-1, T.size() - (i-mid)-1))
			{
				midOld = mid;
				low = mid+1;
			}
			else
			{
				top = mid-1;
			}
			
			
		}
		
		if (big < midOld)
		{
			big = midOld;
			pal = pair<int, int>(i-midOld, i+midOld);
		}
		
	}
	
	for (int i = pal.first; i <= pal.second; i ++)
		if (T[i] != '#')
			cout << T[i];
	cout << '\n';
	
	return 0;
}
