/**
 * Author: Team KACTL / Marce
 * Category: data_structures
 * Source: 1655.cpp
 * CSES Task ID: 1655
 * CSES Problem: Maximum Xor Subarray
 * Link: https://cses.fi/problemset/task/1655
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
 *   Given an array of n integers, your task is to find the maximum xor sum of a subarray.
 *   Input
 *   The first line has an integer n: the size of the array.
 *   The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
 *   Output
 *   Print one integer: the maximum xor sum in a subarray.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   0 \le x_i \le 10^9
 *   Example
 *   Input:
 *   4
 *   5 1 5 9
 *   Output:
 *   13
 */
#include <bits/stdc++.h>
#define maxn 200000

using namespace std;

struct Trie
{
	struct Node
	{
		int to[2];
	};
	
	int building = 1;
	Node tree[maxn*31+5];
	
	void insert(int val)(*@\label{fn14}@*)
	{
		int visit = 1;
		
		for (int b = 30; b >= 0; b--)
		{
			int bit = (val >> b) & 1;
			
			int& n = tree[visit].to[bit];
			
			if (n == 0) n = ++building;
			visit = n;		
		}
		
	}
	
	int findxor(int val)(*@\label{fn15}@*)
	{
		int best = 0;
		int visit = 1;
		
		for (int b = 30; b >= 0; b--)
		{
			int bit = (val >> b) & 1;
			
			int n = tree[visit].to[bit ^ 1];
			
			if (n == 0) n = tree[visit].to[bit];
			else best += (1 << b);
			
			visit = n;
		}
		
		return best;
		
	}
	
};


Trie tree;
int main()
{
	int n;
	int valores[maxn];
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> valores[i];
	
	
	int xorsum = 0;
	int acxor = 0;
	
	tree.insert(0);
	
	for (int i = 0; i < n; i++)
	{
		int v = valores[i];
		acxor ^= v;
		int xs = tree.findxor(acxor);
		xorsum =  xs > xorsum ? xs : xorsum;
		tree.insert(acxor);
	}
	
	
	cout << xorsum << '\n';
	
	return 0;
}