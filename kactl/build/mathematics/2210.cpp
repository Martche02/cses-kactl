/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 2210.cpp
 * CSES Task ID: 2210
 * CSES Problem: Counting Grids
 * Link: https://cses.fi/problemset/task/2210
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
 *   Your task is to count the number of different n \times n grids whose each square is black or white.
 *   Two grids are considered to be different if it is not possible to rotate one of them so that they look the same.
 *   Input
 *   The only input line has an integer n: the size of the grid.
 *   Output
 *   Print one integer: the number of grids modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 10^9
 *   Example
 *   Input:
 *   4
 *   Output:
 *   16456
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll base = 1e9+7;
using u128 = __uint128_t;


ll binpow(ll base, ll exp, ll mod)(*@\label{fn51}@*)
{
	ll res = 1;
	base %= mod;
	while (exp > 0)
	{
		if (exp % 2 == 1) res = (u128)res * base % mod;
		base = (u128)base * base % mod;
		exp /= 2;
	}
	return res;
}

ll burnside(ll n, ll m)(*@\label{fn52}@*)
{	
	ll acc = 0;
	
	//burnside: tamanho do grupo = média dos pontos fixos sob cada operação
	//assim, tamanho do grupo é média dos tamanhos dos conjuntos de "arranjos" que ficam iguais depois de i-rotação
	for (int i = 0; i<n; i++)
	{
		// no caso de ser grupo de rotações, o tamanho do conjunto pode ser obtido via m**gdc(i,n)
		// semanticamente, i-rotação gera gdc ciclos de tamanho n/gdc
		ll ciclos = gcd(i, n);
		
		acc = (acc + binpow(m, ciclos, base)) % base;
	}
	
	ll umsobren = binpow(n, base-2, base);
	
	return (acc * umsobren) % base;
}

int main()
{
	int n;
	cin >> n;
	// tome q como o numero de quadradinhos num quadrante
	// q = (n - (n%2))/4
	ll q = (ll)n*n/4;
	
	// um quadrante pode tar pintado de 2**q "cores"
	// assim, "m" = 2**q
	cout << (burnside(4, binpow(2, q, base)) << (n%2))%base << endl;
	
	return 0;
}