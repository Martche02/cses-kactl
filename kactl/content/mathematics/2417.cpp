/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 2417.cpp
 * CSES Task ID: 2417
 * CSES Problem: Counting Coprime Pairs
 * Link: https://cses.fi/problemset/task/2417
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
 *   Given a list of n positive integers, your task is to count the number of pairs of integers that are coprime (i.e., their greatest common divisor is one).
 *   Input
 *   The first input line has an integer n: the number of elements.
 *   The next line has n integers x_1,x_2,\dots,x_n: the contents of the list.
 *   Output
 *   Print one integer: the answer for the task.
 *   Constraints
 *   1 \le n \le 10^5
 *   1 \le x_i \le 10^6
 *   Example
 *   Input:
 *   8
 *   5 4 20 1 16 17 5 15
 *   Output:
 *   19
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_VAL = 1000005;
int spf[MAX_VAL];
int freq[MAX_VAL];
bool impar[MAX_VAL];


void crivo()
{
	for (int i = 0; i < MAX_VAL; i++)
		spf[i] = i;
	
	for (int i = 2; i*i < MAX_VAL; i++)
	{
		if (spf[i] != i)
			continue;
		for (int j = i * i; j < MAX_VAL; j+=i)
			if (spf[j] == j)
				spf[j] = i;
	}
}

vector<int> factorize(int n)
{
	vector<int> fac;
	while (n!=1)
	{
		int s = spf[n];
		fac.emplace_back(s);
		while (n % s == 0)
			n /= s;
	}
	
	return fac;
}


int main()
{
	crivo();
	int n;
	cin >> n;
	for (int idx = 0; idx < n; idx++)
	{
		int x;
		cin >> x;
		vector<int> a = factorize(x);
		
		int k = a.size();
		
		
		for (int mask = 1; mask < 1 << k; mask++)
		{
			ll divisores = 1;
			for (int i = 0; i < k; i++)
			{
				if ((1 << i) & mask)
					divisores *= a[i];
			}
			
			freq[divisores]++;
			
			impar[divisores] = __builtin_parity(mask);
		}
		
		
	}
	
	ll total_pares = 0;
	
	for (int i = 0; i < MAX_VAL; i++)
		total_pares += (impar[i] ? 1 : -1)*(ll)freq[i]*((ll)freq[i]-1)/2;
	
	cout << (ll)n*(n-1)/2 - total_pares << endl;

	return 0;
}