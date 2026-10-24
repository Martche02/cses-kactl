/**
 * Author: Team KACTL / Marce
 * Category: graph
 * Source: 1096.cpp
 * CSES Task ID: 1096
 * CSES Problem: Throwing Dice
 * Link: https://cses.fi/problemset/task/1096
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
 *   Your task is to calculate the number of ways to get a sum n by throwing dice. Each throw yields an integer between 1 \ldots 6.
 *   For example, if n=10, some possible ways are 3+3+4, 1+4+1+4 and 1+1+6+1+1.
 *   Input
 *   The only input line contains an integer n.
 *   Output
 *   Print the number of ways modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 10^{18}
 *   Example
 *   Input:
 *   8
 *   Output:
 *   125
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
    static Matrix identity() (*@\label{fn6}@*)
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
    ll n;
    cin >> n;
    
    Matrix<6> dic
	{
		1,1,1,1,1,1,
		1,0,0,0,0,0,
		0,1,0,0,0,0,
		0,0,1,0,0,0,
		0,0,0,1,0,0,
		0,0,0,0,1,0,
	};
    
    Matrix<6> final_res = dic ^ n;
    
    cout << final_res.m[0][0] << '\n';
    
    return 0;
}