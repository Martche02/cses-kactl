/**
 * Author: Team KACTL / Marce
 * Category: Mathematics
 * CSES Task ID: 1081
 * CSES Problem: Common Divisors
 * Link: https://cses.fi/problemset/task/1081
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
 *   You are given an array of n positive integers. Your task is to find two integers such that their greatest common divisor is as large as possible.
 *   Input
 *   The first input line has an integer n: the size of the array.
 *   The second line has n integers x_1,x_2,\ldots,x_n: the contents of the array.
 *   Output
 *   Print the maximum greatest common divisor.
 *   Constraints
 *   2 \le n \le 2 \cdot 10^5
 *   1 \le x_i \le 10^6
 *   Example
 *   Input:
 *   5
 *   3 14 15 7 9
 *   Output:
 *   7
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1000005;


int mdc2(vector<int>& x)
{
	int maxmdc = 1;
	
	for (int i = 1; i < MAXM; i++)
	{
		int j = i;
		int mults = 0;
		while (j < MAXM)
		{
			if (x[j])
			{
				mults += x[j];
				//cout << "incrementou mults, valores: \n  i=" << i << "\n  j=" << j << "\n  mults = " << mults;
			}
			j += i;
		}
		
		if (mults >= 2)
			maxmdc = max(i, maxmdc);
		
	}
	
	return maxmdc;
}


int main()
{
	int n;
	cin >> n;
	vector<int> x(MAXM);
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		
		x[j]++;
	}
	
	cout << mdc2(x) << endl;

	return 0;
}