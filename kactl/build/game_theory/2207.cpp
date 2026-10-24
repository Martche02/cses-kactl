/**
 * Author: Team KACTL / Marce
 * Category: game_theory
 * Source: 2207.cpp
 * CSES Task ID: 2207
 * CSES Problem: Grundy's Game
 * Link: https://cses.fi/problemset/task/2207
 * Description:
 *   Time limit: 1.00 s
 *   Memory limit: 512 MB
 *   There is a heap of n coins and two players who move alternately. On each move, a player chooses a heap and divides into two nonempty heaps that have a different number of coins. The player who makes the last move wins the game.
 *   Your task is to find out who wins if both players play optimally.
 *   Input
 *   The first input line contains an integer t: the number of tests.
 *   After this, there are t lines that describe the tests. Each line has an integer n: the number of coins in the initial heap.
 *   Output
 *   For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.
 *   Constraints
 *   1 \le t \le 10^5
 *   1 \le n \le 10^6
 *   Example
 *   Input:
 *   3
 *   6
 *   7
 *   8
 *   Output:
 *   first
 *   second
 *   first
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll top = 1222+5;
ll grundy[top];


int main()
{
	
	for (int i = 0; i < top; i++)
	{
		vector<bool> mex(top, true);
		for (int j = 1; j <= i; j++)
		{
			if (j == i-j || i-j == 0)
				continue;
			mex[grundy[j] ^ grundy[i-j]] = false;			
		}
		
		
		ll valor;
		for (valor = 0; valor < i+1; valor++)
			if (mex[valor])
				break;
			
		grundy[i] = valor;		
	}
	
	
	
	int testes;
	cin >> testes;
	while (testes--)
	{
		int s;
		cin >> s;
		if (s >= top)
		{
			cout << "first\n";
			continue;
		}
		
		cout << ((grundy[s]) != 0 ? "first\n" : "second\n");
	}
	
	return 0;
}