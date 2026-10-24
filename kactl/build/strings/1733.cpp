/**
 * Author: Team KACTL / Marce
 * Category: strings
 * Source: 1733.cpp
 * CSES Task ID: 1733
 * CSES Problem: Finding Periods
 * Link: https://cses.fi/problemset/task/1733
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
 *   A period of a string is a prefix that can be used to generate the whole string by repeating the prefix. The last repetition may be partial. For example, the periods of abcabca are abc, abcabc and abcabca.
 *   Your task is to find all period lengths of a string.
 *   Input
 *   The only input line has a string of length n consisting of characters a-z.
 *   Output
 *   Print all period lengths in increasing order.
 *   Constraints
 *   1 \le n \le 10^6
 *   Example
 *   Input:
 *   abcabca
 *   Output:
 *   3 6 7
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string& s)(*@\label{fn33}@*)
{
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0; // l e r formam a "janela" do match mais a direita que já achamos
    
    for (int i = 1; i < n; i++)
	{
        // Se o i tá dentro da janela, a gente copia o valor que já calculamos no passado!
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        // Tenta expandir o match letra por letra
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
            z[i]++;
		
        // Se o nosso match ultrapassou a janela, a gente atualiza a janela
        if (i + z[i] > r)
		{
            l = i;
            r = i + z[i];
        }
    }
	
    return z;
}

int main()
{
	string s;
	cin >> s;
	vector<int> z = z_function(s);
	
	int n = s.length();
	
	for (int i = 1; i < n; i++)
	{
		if (z[i] == n - i)
			cout << i << ' ';
	}
	
	cout << n;
	
	cout << endl;

	return 0;
}