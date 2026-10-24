/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 1713.cpp
 * CSES Task ID: 1713
 * CSES Problem: Counting Divisors
 * Link: https://cses.fi/problemset/task/1713
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
 *   Given n integers, your task is to report for each integer the number of its divisors.
 *   For example, if x=18, the correct answer is 6 because its divisors are 1,2,3,6,9,18.
 *   Input
 *   The first input line has an integer n: the number of integers.
 *   After this, there are n lines, each containing an integer x.
 *   Output
 *   For each integer, print the number of its divisors.
 *   Constraints
 *   1 \le n \le 10^5
 *   1 \le x \le 10^6
 *   Example
 *   Input:
 *   3
 *   16
 *   17
 *   18
 *   Output:
 *   5
 *   2
 *   6
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXM = 1000005;

array<int, MAXM> crivo()
{
	array<int, MAXM> tb{0};
	for (int i = 1; i < MAXM; i++)
	{
		int j = i;
		while (j < MAXM)
		{
			tb[j]++;
			j += i;
		}
	}
	return tb;
}

array<int, MAXM> tb = crivo();


int main()
{
	ll q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		cout << tb[x] << '\n';
	}
	
	return 0;
}