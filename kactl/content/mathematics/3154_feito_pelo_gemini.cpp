/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 3154_feito_pelo_gemini.cpp
 * CSES Task ID: 3154
 * CSES Problem: System of Linear Equations (v2)
 * Link: https://cses.fi/problemset/task/3154
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
 *   You are given n\cdot(m+1) coefficients a_{i,j} and b_i which form the following n linear equations:
 *   a_{1,1}x_1 + a_{1,2}x_2 + \dots + a_{1,m}x_m = b_1 \pmod {10^9 + 7}
 *   a_{2,1}x_1 + a_{2,2}x_2 + \dots + a_{2,m}x_m = b_2 \pmod {10^9 + 7}
 *   \dots
 *   a_{n,1}x_1 + a_{n,2}x_2 + \dots + a_{n,m}x_m = b_n \pmod {10^9 + 7}
 *   Your task is to find any m integers x_1, x_2, \dots, x_m  that satisfy the given equations.
 *   Input
 *   The first line has two integers n and m: the number of equations and variables.
 *   The next n lines each have m+1 integers a_{i,1}, a_{i,2}, \dots, a_{i,m}, b_i: the coefficients of the i-th equation.
 *   Output
 *   Print m integers x_1, x_2,\dots, x_m: the values of the variables that satisfy the equations. The values must also satisfy 0 \le x_i < 10^9 + 7. You can print any valid solution. If no solution exists print only -1.
 *   Constraints
 *   1 \le n, m \le 500
 *   0 \le a_{i,j}, b_i < 10^9 + 7
 *   Example
 *   Input:
 *   3 3
 *   2 0 1 7
 *   1 2 0 0
 *   1 3 1 2
 *   Output:
 *   2 1000000006 3
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll base = 1e9+7;
using u128 = __uint128_t;

// Exponenciação modular para achar o Inverso Modular
ll binpow(ll b, ll exp, ll mod) {
    ll res = 1;
    b %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (u128)res * b % mod;
        b = (u128)b * b % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    // Matriz expandida N x (M + 1)
    vector<vector<ll>> a(n, vector<ll>(m + 1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }
        
    int r = 0; // Controla a linha atual
    
    // Itera pelas colunas (variáveis)
    for (int c = 0; c < m && r < n; c++) {
        int pivo_row = r;
        bool hit = false;
        
        // Procura o pivô de 'r' para baixo
        for (int j = r; j < n; j++) {
            if (a[j][c] != 0) {
                pivo_row = j;
                hit = true;
                break;
            }
        }
        
        // Se a coluna for só de zeros, é variável livre. Ignoramos a coluna.
        if (!hit) continue;
        
        // Traz o pivô para a linha 'r'
        swap(a[r], a[pivo_row]);
        
        // Transforma o pivô em 1 multiplicando a linha pelo inverso modular
        ll ipivot = binpow(a[r][c], base - 2, base);
        for (int d = c; d <= m; d++) {
            a[r][d] = (a[r][d] * ipivot) % base;
        }
        
        // Zera a coluna 'c' em TODAS as outras linhas
        for (int i = 0; i < n; i++) {
            if (i == r || a[i][c] == 0) continue;
            
            ll fator = a[i][c];
            for (int d = c; d <= m; d++) {
                // Modulo seguro para números negativos
                a[i][d] = (a[i][d] - (fator * a[r][d]) % base + base) % base;
            }
        }
        
        r++; // Linha resolvida, avançamos para a próxima
    }
    
    // Julgamento Final: Verifica se o sistema é impossível
    for (int i = 0; i < n; i++) {
        bool blank = true;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                blank = false;
                break;
            }
        }
        // Se a linha toda é 0, mas o resultado final (coluna m) não é, 0 = k (impossível)
        if (blank && a[i][m] != 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
    // Extração das respostas
    vector<ll> ans(m, 0); // Variáveis livres ganham 0 automaticamente
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                ans[j] = a[i][m];
                break; // Achou a primeira variável da equação, pega o valor e vai pra próxima linha
            }
        }
    }

    // Impressão
    for (int i = 0; i < m; i++) {
        cout << ans[i] << (i == m - 1 ? "" : " ");
    }
    cout << '\n';

    return 0;
}