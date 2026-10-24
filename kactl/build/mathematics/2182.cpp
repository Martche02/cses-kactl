/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 2182.cpp
 * CSES Task ID: 2182
 * CSES Problem: Divisor Analysis
 * Link: https://cses.fi/problemset/task/2182
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
 *   Given an integer, your task is to find the number, sum and product of its divisors. As an example, let us consider the number 12:
 *   the number of divisors is 6 (they are 1, 2, 3, 4, 6, 12)
 *   the sum of divisors is 1+2+3+4+6+12=28
 *   the product of divisors is 1 \cdot 2 \cdot 3 \cdot 4 \cdot 6 \cdot 12 = 1728
 *   Since the input number may be large, it is given as a prime factorization.
 *   Input
 *   The first line has an integer n: the number of parts in the prime factorization.
 *   After this, there are n lines that describe the factorization. Each line has two numbers x and k where x is a prime and k is its power.
 *   Output
 *   Print three integers modulo 10^9+7: the number, sum and product of the divisors.
 *   Constraints
 *   1 \le n \le 10^5
 *   2 \le x \le 10^6
 *   each x is a distinct prime
 *   1 \le k \le 10^9
 *   Example
 *   Input:
 *   2
 *   2 2
 *   3 1
 *   Output:
 *   6 28 1728
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<int MOD>
struct Mint 
{
    int v;
    
    Mint() : v(0) {}
    Mint(ll val)
	{
        v = val % MOD;
        if (v < 0) v += MOD;
    }

    // Operadores de atribuição (O Segredo da Velocidade)
    // O if (+ e -) é ~15x mais rápido que usar %
    Mint& operator+=(Mint o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(Mint o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(Mint o) { v = (ll)v * o.v % MOD; return *this; } // Cast seguro
    Mint& operator/=(Mint o) { return *this *= o.inv(); }

    // Operadores aritméticos puros
    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b; }

    // Exponenciação rápida e Inverso Modular embutidos
    Mint pow(ll b) const(*@\label{fn46}@*)
	{
        Mint res = 1, a = *this;
        while (b > 0)
		{
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
		
        return res;
    }
	
    Mint inv() const { return pow(MOD - 2); }

    // Operadores de Comparação
    friend bool operator==(Mint a, Mint b) { return a.v == b.v; }
    friend bool operator!=(Mint a, Mint b) { return a.v != b.v; }

    // Facilita o cin/cout direto na variável
    friend istream& operator>>(istream& is, Mint& m) { ll x; is >> x; m = Mint(x); return is; }
    friend ostream& operator<<(ostream& os, Mint m) { return os << m.v; }
};

// Instância oficial para o CSES
const int MOD = 1e9 + 7;
using mint = Mint<MOD>;
using minte = Mint<MOD-1>;

int main()
{
	int n;
	cin >> n;
	mint count = 1;
	mint sum = 1;
	mint product = 1;
	minte counte = 1;
	
	while (n--)
	{
		ll x, k;
		cin >> x >> k;
		count *= (k+1);
		sum *= (mint(x).pow(k+1) -1)*(mint(x-1).inv());
		product = product.pow(k+1) * mint(x).pow((counte*minte(k*(k+1)/2)).v);
		
		counte *= (k+1);
		
	}
	
	
	cout << count << ' '
		 << sum   << ' '
		 << product << endl;
	
	return 0;
}