/**
 * Author: Team KACTL / Marce
 * Category: strings
 * Source: 1732.cpp
 * CSES Task ID: 1732
 * CSES Problem: Finding Borders
 * Link: https://cses.fi/problemset/task/1732
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
 *   A border of a string is a prefix that is also a suffix of the string but not the whole string. For example, the borders of abcababcab are ab and abcab.
 *   Your task is to find all border lengths of a given string.
 *   Input
 *   The only input line has a string of length n consisting of characters a-z.
 *   Output
 *   Print all border lengths of the string in increasing order.
 *   Constraints
 *   1 \le n \le 10^6
 *   Example
 *   Input:
 *   abcababcab
 *   Output:
 *   2 5
 */
#include <bits/stdc++.h>

using namespace std;

string s;
long long modulo = 1e9+7;
long long base = 31;

#define MOD(V) (((V) % modulo + modulo) % modulo)(*@\label{fn30}@*)

long long getHash(int R, vector<long long>& hash, vector<long long>& pot);
long long getHash(int L, int R, vector<long long>& hash, vector<long long>& pot);

long long getHash(int R, vector<long long>& hash, vector<long long>& pot)(*@\label{fn31}@*)
{
	return hash[R];
}

long long getHash(int L, int R, vector<long long>& hash, vector<long long>& pot)(*@\label{fn32}@*)
{
	int tam = R - L +1;
	
	long long hL = MOD(hash[L-1] * pot[tam]);
	
	return MOD(hash[R] - hL);
}

int main()
{
	cin >> s;

	int n = s.size();
	vector<long long> hash(n);
	vector<long long> pot(n);
	
	pot[0] = 1;
	for (int i = 1; i < n; i++)
	{
		pot[i] = MOD(pot[i-1] * base);
	}
	
	
	hash[0] = s[0];
	
	for (int i = 1; i < n; i++)
	{
		hash[i] = MOD(hash[i-1] * base + s[i]);
	}
	
	
	for (int i = 1; i < n; i++)
	{
		if (getHash(i-1, hash, pot) == getHash(n-i, n-1, hash, pot))
			cout << i << ' ';
	}
	
	cout << endl;
	
	
	
	return 0;
}