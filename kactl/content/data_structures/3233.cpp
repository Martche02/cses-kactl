/**
 * Author: Team KACTL / Marce
 * Category: Data_structures
 * CSES Task ID: 3233
 * CSES Problem: All Subarray Xors
 * Link: https://cses.fi/problemset/task/3233
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
 *   Given an array of n integers, your task is to find all integers that are the xor sum in some subarray.
 *   Input
 *   The first line has an integer n: the size of the array.
 *   The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
 *   Output
 *   First print an integer k: the number of distinct integers that are the xor sum in some subarray.
 *   After this print k integers: the xor sums in increasing order.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   0 \le x_i \le 10^6
 *   Example
 *   Input:
 *   4
 *   5 1 5 9
 *   Output:
 *   7
 *   1 4 5 8 9 12 13
 */
#include <bits/stdc++.h>

using namespace std;


const int SZ = 1 << 20;

void fwht(vector<long long>&a, bool invert)
{
	int s = a.size();
	for (int len = 1; len < s; len *= 2)
		for (int i = 0; i < s; i += 2 * len)
			for (int j = i; j < i + len; j++)
			{
				long long u = a[j];
				long long v = a[j + len];
				
				a[j] = u + v;
				a[j+len] = u - v;
				
			}
			
	
	if (invert)
		for (auto& i : a)
			i/=s;
}



int main()
{
	int n;
	cin >> n;
	
	//obtem as freq
	vector<long long> freq(SZ, 0);
	
	int acc = 0;
	
	freq[acc]++;
	for (int i =0; i < n; i++)
	{
		int p;
		cin >> p;
		acc ^= p;
		freq[acc]++;
		
		//algo com o freq[0]
		
	}
	
	fwht(freq, false);
	
	for (auto& i : freq)
		i *= i;
	
	fwht(freq, true);
	int nonZero = 0;
	vector<long long> r;
	
	if (freq[0] > n + 1) 
	{
		nonZero++;
		r.push_back(0);
	}
	
	for (int i = 1; i < freq.size(); i++) if (freq[i] != 0) 
	{
		nonZero++;
		r.push_back(i);
	}
	
	cout << nonZero << '\n';
	
	for (auto i : r)
		cout << i << ' ';
	cout << endl;
	return 0;
}