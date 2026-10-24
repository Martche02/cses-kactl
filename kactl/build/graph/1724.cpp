/**
 * Author: Team KACTL / Marce
 * Category: graph
 * Source: 1724.cpp
 * CSES Task ID: 1724
 * CSES Problem: Graph Paths II
 * Link: https://cses.fi/problemset/task/1724
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
 *   Consider a directed weighted graph having n nodes and m edges. Your task is to calculate the minimum path length from node 1 to node n with exactly k edges.
 *   Input
 *   The first input line contains three integers n, m and k: the number of nodes and edges, and the length of the path. The nodes are numbered 1,2,\dots,n.
 *   Then, there are m lines describing the edges. Each line contains three integers a, b and c: there is an edge from node a to node b with weight c.
 *   Output
 *   Print the minimum path length. If there are no such paths, print -1.
 *   Constraints
 *   1 \le n \le 100
 *   1 \le m \le n(n-1)
 *   1 \le k \le 10^9
 *   1 \le a,b \le n
 *   1 \le c \le 10^9
 *   Example
 *   Input:
 *   3 4 8
 *   1 2 5
 *   2 3 4
 *   3 1 1
 *   3 2 2
 *   Output:
 *   27
 */
#include <bits/stdc++.h>

using namespace std;
using u128 = __uint128_t;
using ll = long long;

constexpr ll inf = LLONG_MAX;

template <int N>
struct Matrix 
{
    ll m[N][N];
    
    // Construtor: Inicializa tudo com zero (evita lixo de memória)
    Matrix() 
	{
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = inf;
    }
	
	Matrix(initializer_list<ll> lst)
	{
        auto it = lst.begin();
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                if (it != lst.end()) 
				{
                    m[i][j] = *it;
                    it++;
                } 
				else 
				{
                    m[i][j] = 0;
                }
    }
    
    // Ajuda a criar a matriz identidade (diagonal de 1s)
    static Matrix identity() (*@\label{fn27}@*)
	{
        Matrix res;
        for (int i = 0; i < N; i++)
            res.m[i][i] = 0;
        return res;
    }

    // Sobrecarga da Multiplicação (Matriz * Matriz)
    Matrix operator*(const Matrix& other) const 
	{
        Matrix res; // Já nasce zerada graças ao construtor
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
				{
					// o melhor caminho de i->j vai ser o mínimo dentre i->j e i->k->j, pra todo k
					// a coisa é que temos que testar tanto i->k quanto k->j pra inf, pois se for
					// descartamos
					if (m[i][k] != inf && other.m[k][j] != inf)
						res.m[i][j] = min(res.m[i][j], m[i][k] + other.m[k][j]);
				}

        return res;
    }

    // Sobrecarga da Exponenciação (Matriz ^ Exp) - O seu Binpow!
    Matrix operator^(ll exp) const
	{
        Matrix res = Matrix::identity();
        Matrix base = *this; // Faz uma cópia para ir elevando ao quadrado
        
        while (exp > 0)
		{
            if (exp % 2 == 1) res = res * base;
            base = base * base;
            exp /= 2;
        }
		
        return res;
    }
};

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
	
	Matrix<101> adj;
	
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj.m[a][b] = min(adj.m[a][b], (ll)c);
	}
    
    Matrix<101> kadj = adj ^ k;
    
	ll ret = kadj.m[1][n];
	
	if (ret != inf)
		cout << kadj.m[1][n] << '\n';
    else
		cout << -1 << '\n';
    return 0;
}