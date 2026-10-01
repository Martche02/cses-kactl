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