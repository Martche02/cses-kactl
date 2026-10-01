/**
 * Author: Team KACTL / Marce
 * Category: Strings
 * CSES Task ID: 3141
 * CSES Problem: And Subset Count
 * Link: https://cses.fi/problemset/task/3141
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
 *   You are given an array of n integers. Your task is to calculate the number of non-empty subsets whose elements' bitwise and is equal to k for each k = 0, 1,\dots, n.
 *   Input
 *   The first line has an integer n: the size of the array.
 *   The next line has n integers a_1, a_2,\dots, a_n: the contents of the array.
 *   Output
 *   Print n + 1 integers as specified above modulo 10^9 + 7.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   0 \le a_i \le n
 *   Example
 *   Input:
 *   4
 *   3 1 3 4
 *   Output:
 *   7 4 0 3 1
 */
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
// Macro segura para subtração/adição modular
#define RES(V) (((V) % MOD + MOD) % MOD)

int B = 18; // 18 já é suficiente para N = 200.000 (1<<18 = 262144)
int MAX_MASK = 1 << B;
const int MAX_N = 200005;

constexpr std::array<int, MAX_N> precalc_pot2() {
    std::array<int, MAX_N> arr{}; 
    arr[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        arr[i] = (1LL * arr[i - 1] * 2) % MOD;
    }
    return arr;
}

constexpr auto pot2 = precalc_pot2();

int main()
{
    // Otimização I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> super(MAX_MASK, 0);
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        super[x]++;
    }
    
    // Ida (Soma)
    for (int bit = 0; bit < B; bit++)
        for (int i = 0; i < MAX_MASK; i++)
            if (!(i & (1 << bit)))
                 super[i] = (super[i] + super[i ^ (1 << bit)]) % MOD;
            
    // Mutação
    for (auto& i : super)
        i = RES(pot2[i] - 1);
            
    // Volta (Subtração)
    for (int bit = 0; bit < B; bit++)
        for (int i = 0; i < MAX_MASK; i++)
            if (!(i & (1 << bit)))
                 super[i] = RES(super[i] - super[i ^ (1 << bit)]);
    
    // Imprimir respostas do número 0 até o número N
    for (int i = 0; i <= n; i++)
        cout << super[i] << (i == n ? "" : " ");
    
    cout << '\n';
    
    return 0;
}