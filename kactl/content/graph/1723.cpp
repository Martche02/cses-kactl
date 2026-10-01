/**
 * Author: Team KACTL / Marce
 * Category: Graph
 * CSES Task ID: 1723
 * CSES Problem: Graph Paths I
 * Link: https://cses.fi/problemset/task/1723
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
 *   Consider a directed graph that has n nodes and m edges. Your task is to count the number of paths from node 1 to node n with exactly k edges.
 *   Input
 *   The first input line contains three integers n, m and k: the number of nodes and edges, and the length of the path. The nodes are numbered 1,2,\dots,n.
 *   Then, there are m lines describing the edges. Each line contains two integers a and b: there is an edge from node a to node b.
 *   Output
 *   Print the number of paths modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 100
 *   1 \le m \le n(n-1)
 *   1 \le k \le 10^9
 *   1 \le a,b \le n
 *   Example
 *   Input:
 *   3 4 8
 *   1 2
 *   2 3
 *   3 1
 *   3 2
 *   Output:
 *   2
 *   Explanation: The paths are 1 \rightarrow 2 \rightarrow 3 \rightarrow 1 \rightarrow 2 \rightarrow 3 \rightarrow 1 \rightarrow 2 \rightarrow 3 and 1 \rightarrow 2 \rightarrow 3 \rightarrow 2 \rightarrow 3 \rightarrow 2 \rightarrow 3 \rightarrow 2 \rightarrow 3.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7; // Renomeei para MOD por clareza (opcional)
using u128 = __uint128_t;

template <int N>
struct Matrix 
{
    ll m[N][N];
    
    // Construtor: Inicializa tudo com zero (evita lixo de memória)
    Matrix() 
	{
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = 0;
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
    static Matrix identity() 
	{
        Matrix res;
        for (int i = 0; i < N; i++)
            res.m[i][i] = 1;
        return res;
    }

    // Sobrecarga da Multiplicação (Matriz * Matriz)
    Matrix operator*(const Matrix& other) const 
	{
        Matrix res; // Já nasce zerada graças ao construtor
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    res.m[i][j] = (res.m[i][j] + (u128)m[i][k] * other.m[k][j]) % MOD;

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
		int a, b;
		cin >> a >> b;
		adj.m[a][b]++;
	}
    
    Matrix<101> kadj = adj ^ k;
    
    cout << kadj.m[1][n] << '\n';
    
    return 0;
}