/**
 * Author: Team KACTL / Marce
 * Category: Combinatorics
 * CSES Task ID: 1726
 * CSES Problem: Moving Robots
 * Link: https://cses.fi/problemset/task/1726
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
 *   Each square of an 8 \times 8 chessboard has a robot. Each robot independently moves k steps, and there can be many robots on the same square.
 *   On each turn, a robot moves one step left, right, up or down, but not outside the board. It randomly chooses a direction among those where it can move.
 *   Your task is to calculate the expected number of empty squares after k turns.
 *   Input
 *   The only input line has an integer k.
 *   Output
 *   Print the expected number of empty squares rounded to six decimal places (rounding half to even).
 *   Constraints
 *   1 \le k \le 100
 *   Example
 *   Input:
 *   10
 *   Output:
 *   23.120740
 */
#include <bits/stdc++.h>
using namespace std;

constexpr int top = 1e2+5;

struct Board
{
	double robot[8][8];
};

Board dp[top][8][8];

int main()
{
	int n;
	cin >> n;
	
	for (int l = 0; l < 8; l++) // cada linha
		for (int c = 0; c < 8; c++) // cada coluna
			dp[0][l][c].robot[l][c] = 1.0;
			
	for (int i = 1; i <= n; i++) // para cada rodada
		for (int l = 0; l < 8; l++) // cada linha
			for (int c = 0; c < 8; c++) // cada coluna
			{ // dispersa a probabilidade pras vizinhas
				Board& p = dp[i-1][l][c]; // probabilidade acumulada na rodada passada
				
				vector<Board*> alvos;
				if (l != 0)
					alvos.emplace_back(&dp[i][l-1][c]);
				if (l != 7)
					alvos.emplace_back(&dp[i][l+1][c]);
				if (c != 0)
					alvos.emplace_back(&dp[i][l][c-1]);
				if (c != 7)
					alvos.emplace_back(&dp[i][l][c+1]);
				
				for (auto& a : alvos)
					for (int ll = 0; ll < 8; ll++) // cada linha
						for (int cc = 0; cc < 8; cc++) // cada coluna
							a->robot[ll][cc] += p.robot[ll][cc] / (double)alvos.size();
				
			}

	double ans = 0.0;
	
	for (int l = 0; l < 8; l++) // cada linha
		for (int c = 0; c < 8; c++) // cada coluna
		{
			double exp = 1;
			for (int ll = 0; ll < 8; ll++) // cada linha
				for (int cc = 0; cc < 8; cc++) // cada coluna
					exp *= (1-(dp[n][l][c]).robot[ll][cc]);
			ans += exp;
		}

	cout << fixed << setprecision(6) << ans << '\n';

	return 0;
}