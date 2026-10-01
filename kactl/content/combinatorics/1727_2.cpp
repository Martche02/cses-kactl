/**
 * Author: Team KACTL / Marce
 * Category: Combinatorics
 * CSES Task ID: 1727
 * CSES Problem: Candy Lottery
 * Link: https://cses.fi/problemset/task/1727
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
 *   There are n children, and each of them independently gets a random integer number of candies between 1 and k.
 *   What is the expected maximum number of candies a child gets?
 *   Input
 *   The only input line contains two integers n and k.
 *   Output
 *   Print the expected number rounded to six decimal places (rounding half to even).
 *   Constraints
 *   1 \le n \le 100
 *   1 \le k \le 100
 *   Example
 *   Input:
 *   2 3
 *   Output:
 *   2.444444
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    long double exp = 0.0;

    for (int i = 0; i < k; i++) {
        exp += 1.0 - pow((long double)i / k, n);
    }

    // Sem cast, sem epsilon, puro long double.
    cout << fixed << setprecision(6) << exp << '\n';

    return 0;
}