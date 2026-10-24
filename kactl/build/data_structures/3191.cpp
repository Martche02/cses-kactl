/**
 * Author: Team KACTL / Marce
 * Category: data_structures
 * Source: 3191.cpp
 * CSES Task ID: 3191
 * CSES Problem: Maximum Xor Subset
 * Link: https://cses.fi/problemset/task/3191
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
 *   Given an array of n integers, your task is to find the maximum xor sum of a subset.
 *   Input
 *   The first line has an integer n: the size of the array.
 *   The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
 *   Output
 *   Print one integer: the maximum xor sum of a subset.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   0 \le x_i \le 10^9
 *   Example
 *   Input:
 *   4
 *   1 6 12 6
 *   Output:
 *   13
 */
#include <bits/stdc++.h>

using namespace std;

struct LinBase
{
		int Basis[31] = {0};
		
		void insert(int val)(*@\label{fn68}@*)
		{
			int value = val;
			for (int b = 30; b >=0; b--)
			{
				int bit = (value >> b) & 1;
				int& base = Basis[b];
				if (bit == 0) continue;
				if (base == 0) base = value;
				value ^= base;
			}
			
		}
		
		int getMax()(*@\label{fn69}@*)
		{
			int value = 0;
			
			for (int b = 30; b >=0; b--)
				value = max(value , value ^ Basis[b]);
			
			return value;
		}
};

LinBase lin;

int main()
{
	int n;
	cin >> n;
	
	
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		lin.insert(j);
	}

	cout << lin.getMax() << '\n';

	return 0;
	
}