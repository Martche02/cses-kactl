/**
 * Author: Team KACTL / Marce
 * Category: Data_structures
 * CSES Task ID: 1654
 * CSES Problem: SOS Bit Problem
 * Link: https://cses.fi/problemset/task/1654
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
 *   Given a list of n integers, your task is to calculate for each element x:
 *   the number of elements y such that x \mid y = x
 *   the number of elements y such that x \mathrel{\&} y = x
 *   the number of elements y such that x \mathrel{\&} y \neq 0
 *   Input
 *   The first line has an integer n: the size of the list.
 *   The next line has n integers x_1,x_2,\dots,x_n: the elements of the list.
 *   Output
 *   Print n lines: for each element the required values.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   1 \le x_i \le 10^6
 *   Example
 *   Input:
 *   5
 *   3 7 2 9 2
 *   Output:
 *   3 2 5
 *   4 1 5
 *   2 4 4
 *   1 1 3
 *   2 4 4
 */
#include <bits/stdc++.h>

using namespace std;

int B = 20;
int MAX_MASK = 1 << B;

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<int> sub(MAX_MASK);
	vector<int> super(MAX_MASK);
	
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sub[a[i]]++;
		super[a[i]]++;
	}
	
	for (int bit = 0; bit < B; bit++)
	{
		for (int i = 0; i < MAX_MASK; i++)
		{
			if (i & (1 << bit))
			{
				 sub[i] += sub[i ^ (1 << bit)];
			}
			else
			{
				 super[i] += super[i ^ (1 << bit)];
			}
		}
	}
	
	for (auto i : a)
	{
		cout << sub[i] << ' ' << super[i] << ' ' << n - sub[(~i) & (MAX_MASK - 1)] << '\n';
	}
	
	
	return 0;
}