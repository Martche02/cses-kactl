/**
 * Author: Team KACTL / Marce
 * Category: Mathematics
 * CSES Task ID: 3397
 * CSES Problem: Permutation Order
 * Link: https://cses.fi/problemset/task/3397
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
 *   Let p(n,k) denote the kth permutation (in lexicographical order) of 1 \dots n. For example, p(4,1)=[1,2,3,4] and p(4,2)=[1,2,4,3].
 *   Your task is to process two types of tests:
 *   Given n and k, find p(n,k)
 *   Given n and p(n,k), find k
 *   Input
 *   The first line has an integer t: the number of tests.
 *   Each test is either "1 n k" or "2 n p(n,k)".
 *   Output
 *   For each test, print the answer according to the example.
 *   Constraints
 *   1 \le t \le 1000
 *   1 \le n \le 20
 *   1 \le k \le n!
 *   Example
 *   Input:
 *   6
 *   1 4 1
 *   1 4 2
 *   2 4 1 2 3 4
 *   2 4 1 2 4 3
 *   1 5 42
 *   2 5 2 4 5 3 1
 *   Output:
 *   1 2 3 4
 *   1 2 4 3
 *   1
 *   2
 *   2 4 5 3 1
 *   42
 */
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

template <int N>
constexpr array<ll, N> calculateFat()
{
	array<ll, N> fat{};
	fat[0] = 1;
	for (int i = 1; i < N; i++)
		fat[i] = fat[i-1] * i;
	return fat;
}

constexpr array<ll, 21> fat = calculateFat<21>();


void print1(int n, ll k)
{	
	vector<int> disp(n);
	iota(disp.begin(), disp.end(), 1);
	for (int i = 0; i < n; i++)
	{
		int idx = (k / fat[n - 1 - i]);
		cout << disp[idx] << (i == n-1 ? '\n' : ' ');
		k %= fat[n - 1 - i];
		disp.erase(disp.begin() + idx);
	}
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int n;
			ll k;
			cin >> n >> k;
			print1(n, k-1);
		}
		else
		{
			int n;
			cin >> n;
			vector<int> disp(n);
			iota(disp.begin(), disp.end(), 1);
			ll k = 0;
			while (n--)
			{
				int i;
				cin >> i;
				
				auto it = find(disp.begin(), disp.end(), i);
				int idx = distance(disp.begin(), it);
				k += idx*fat[n];
				disp.erase(it);
			}
			
			cout << k+1 << '\n';
		}
		
	}
	
	return 0;
}