/**
 * Author: Team KACTL / Marce
 * Category: combinatorics
 * Source: 1727.cpp
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

constexpr int top = 1e2+5;

int main()
{
	int n, k;
	cin >> n >> k;
	
	long double exp = 0;
	
	//for (int i = 0; i <= k; i++)
	//	exp += i*( pow((double)i/(double)k, n) - pow((double)(i-1)/(double)k, n));
	// subtração de pow de double da WA. não fazer. ao invez de calcular P(max <= i), abrir isso em 
	/*
	 * Fórmula original da Esperança: 
	 * exp += i * (P(max <= i) - P(max <= i-1))
	 * 
	 * MOTIVO DO WA: Subtrair resultados de pow() muito próximos causa 
	 * "Cancelamento Catastrófico", perdendo as casas decimais de precisão do double.
	 * 
	 * SOLUÇÃO: Soma por partes (Layer-cake representation).
	 * Ao invés de multiplicar, abrimos a soma e agrupamos verticalmente:
	 * E = 1*P(1) + 2*P(2) + 3*P(3) ...
	 * 
	 * Coluna 0: P(1) + P(2) + P(3) + ... + P(k) = 1.0  (100% de chance de dar <= k)
	 * Coluna 1:        P(2) + P(3) + ... + P(k) = 1.0 - P(max <= 1)
	 * Coluna 2:               P(3) + ... + P(k) = 1.0 - P(max <= 2)
	 * Coluna i:                                 = 1.0 - P(max <= i)
	 * 
	 * Somando todas as colunas, a matemática prova que o resultado é idêntico, 
	 * mas sem subtrair floats pequenos! O loop vira apenas:
	 * Somatório de (1.0 - P(max <= i)) para 'i' indo de 0 até k-1.
	*/
	 
	//for (int i = 0; i<k; i++)
	//	exp += 1 - pow((double)i/k, n);
	
	// o gemini disse que ia resolver
	// nao resolveu. Gemini burro
	// dai o gemini disse que era pra dar um + 1e-9 no cout q ia resolver
	
	// dai no "gabarito" em https://github.com/Jonathan-Uy/CSES-Solutions/
	// ele faz assim, que é a tecnica inicial, mas com pow manual
	
	/*for (int i = 0; i <= k; i++)
	{
		double a, b;
		a = b = 1.0;
		for(int j = 1; j <=n; j++)
		{
			a *= (double)i/k;
			b *= (double)(i-1)/k;
		}
		
		exp += i*(a - b);
	}
	*/
	
	// e deu wa tbm
	
	// licao de moral
	// 1. gemini burro
	// 2. use long double
	
	
	
	//for (int i = 0; i <= k; i++)
	//	exp += i*( pow((long double)i/(long double)k, n) - pow((long double)(i-1)/(long double)k, n));
	// da ruim
	
	
	for (int i = 0; i<k; i++)
		exp += 1 - pow((long double)i/k, n);
	//funciona
	
	cout << fixed << setprecision(6) << exp<< '\n';
	
	return 0;
}