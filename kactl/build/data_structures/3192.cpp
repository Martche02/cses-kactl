/**
 * Author: Team KACTL / Marce
 * Category: data_structures
 * Source: 3192.cpp
 * CSES Task ID: 3192
 * CSES Problem: K Subset Xors
 * Link: https://cses.fi/problemset/task/3192
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
 *   You are given an array of n integers. Consider the xors of all 2^n subsets of the array (including the empty subset with xor equal to zero).
 *   Your task is to find the k smallest subset xors.
 *   Input
 *   The first line has two integers n and k: the size of the array and the number of subset xors k.
 *   The next line has n integers x_1, x_2,\dots, x_n: the contents of the array.
 *   Output
 *   Print k integers: the k smallest subset xors in increasing order.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   1 \le k \le \min(2^n, 2 \cdot 10^5)
 *   0 \le x_i \le 10^9
 *   Example
 *   Input:
 *   4 9
 *   3 5 14 8
 *   Output:
 *   0 0 3 3 5 5 6 6 8
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int Basis[31] = {0};
	int tamanho_base = 0;
	
	for (int i = 0; i< n; ++i)
	{
		int val;
		cin >> val;
		for (int b = 30; b >=0; b--)
		{
			int bit = (val >> b) & 1;
			if (bit == 1)
			{
				if (Basis[b] == 0)
				{
					Basis[b] = val;
					tamanho_base++;
					break;
				}
				else
					val ^= Basis[b];
			}
		}
	}
	
	
	for (int b = 30; b>= 0; b--) if (Basis[b])
		for (int j = b-1; j >=0; j--) if ((Basis[b] >> j) & 1)
			Basis[b] ^= Basis[j];
		
	
	vector<int> blimpa;
	for (auto b : Basis) if (b)
		blimpa.emplace_back(b);
	
	
	int d = n- tamanho_base;
	long long d2 = 1;
	for (int i = 0; i < d; ++i) 
	{
	    d2 *= 2;
	    if (d2 >= k) { d2 = k; break; }
	}
	
	int limite_m = (1 << blimpa.size());
	int impres = 0;
	for (int m =0; m < limite_m && impres < k; ++m)
	{
		int xor_atual = 0;
		for (int i = 0; i< blimpa.size(); i++)
		{
			if ((m>>i) & 1)
				xor_atual ^= blimpa[i];
		}
		
		for (int r = 0; r < d2 && impres < k; r++)
		{
			cout << xor_atual << ' ';
			impres++;	
		}
		
	}
	
	cout << endl;

	return 0;
}