/**
 * Author: Team KACTL / Marce
 * Category: data_structures
 * Source: 3211.cpp
 * CSES Task ID: 3211
 * CSES Problem: Number of Subset Xors
 * Link: https://cses.fi/problemset/task/3211
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
 *   Given an array of n integers, your task is to find the number of different subset xors.
 *   Input
 *   The first line has an integer n: the size of the array.
 *   The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
 *   Output
 *   Print one integer: the number of different subset xors.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   0 \le x_i \le 10^9
 *   Example
 *   Input:
 *   3
 *   3 6 5
 *   Output:
 *   4
 *   Explanation: The following values can be the xor of a subset:
 *   0 = \text{xor of the empty set}
 *   3 = 3
 *   5 = 3 \oplus 6
 *   6 = 3 \oplus 5
 *   In this case, no other values can be the xor of a subset.
 */
#include <bits/stdc++.h>

using namespace std;

struct LinBase
{
		int Basis[31] = {0};
		
		void insert(int val)(*@\label{fn70}@*)
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
		
		int getBasis()(*@\label{fn71}@*)
		{
			int value = 0;
			
			for (int b = 30; b >=0; b--) if (Basis[b] != 0)
				value++;
			
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

	cout << (1 << lin.getBasis()) << '\n';

	return 0;
	
}