/**
 * Author: Team KACTL / Marce
 * Category: Contests
 * Problem: HowManyTeams
 * Description:
 *   Implementation for HowManyTeams
 */
//start time 15:15 19/09
// using 3141.cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
using u128 = __uint128_t;

// Macro segura para subtração/adição modular
#define RES(V) V

int B = 21; // 18 já é suficiente para N = 200.000 (1<<18 = 262144)
ll MAX_MASK = 1 << B;
const int MAX_N = 2*200005;

//constexpr ll umsexto = 166666668;

int main()
{
    // Otimização I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<ll> sub(MAX_MASK, 0);
    
    for (int i = 0; i < n; i++)
    {
        string h;
        cin >> h;	// mas ta em binario
        sub[stoi(h, 0, 2)]++;
		//cout << stoi(h, 0, 2) << '\n';
    }
    
    // Ida (Soma)
    for (int bit = 0; bit < B; bit++) // pra cada um dos bits (algebra linear)
        for (int i = 0; i < MAX_MASK; i++) // iterando no vetor de frequencia
            if ((i & (1 << bit))) // se tem o bit ligado
                 sub[i] = (sub[i] + sub[i ^ (1 << bit)]); // soma junto do que é igual, mas tem o bit desligado ( é subconjunto)
            
    // Mutação
    for (auto& i : sub)
        i = RES( RES(RES((u128)i*(i-1))*(i-2)) /6);
            
    // Volta (Subtração)
    for (int bit = 0; bit < B; bit++)
        for (int i = 0; i < MAX_MASK; i++)
            if ((i & (1 << bit)))
                 sub[i] = RES(sub[i] - sub[i ^ (1 << bit)]);
    
	int m;
	cin >> m;
	
    // Imprimir respostas do que sejam do E
    for (int i = 0; i < m; i++)
	{
		string e;
		cin >> e;
        cout << sub[stoi(e,0,2)] << '\n';
	}
	
	//for (int i = 0; i < 20; i++)
	//	cout << sub[i] << ' ';
    
    return 0;
}