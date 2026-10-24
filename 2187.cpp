#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u128 = __uint128_t;

const ll base = 1e9+7;
const ll top = 1e6+15; // 10^6 é o suficiente, n não passa disso

ll fat[top];
ll ifat[top];

ll binpow(ll base, ll exp, ll mod)
{
	ll res = 1;
	base %= mod;
	while (exp > 0)
	{
		if (exp % 2 == 1) res = (u128)res * base % mod;
		base = (u128)base * base % mod;
		exp /= 2;
	}
	return res;
}

void calculateFat()
{
	fat[0] = 1;
	ifat[0] = 1;
	for (int i = 1; i < top; i++)
		fat[i] = (fat[i-1]*i)%base;
	
	ifat[top-1] = binpow(fat[top-1], base-2, base);
	
	for (int i = top-1; i > 0; i--)
		ifat[i-1] = (ifat[i]*i)%base;
}

// Consertada para calcular a Combinação C(a,b) de verdade e tratar ca negativos
ll newton(int a, int b)
{
    if (b < 0 || b > a) return 0;
	return (((fat[a] * ifat[b]) % base) * ifat[a - b]) % base;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	calculateFat();
    
	int n;
	if (!(cin >> n)) return 0;
    
    string s;
    cin >> s;
    
	if (n % 2 == 1) 
	{
		cout << 0 << '\n';
		return 0;
	}
    
    int o = 0; // Quantidade de '('
    int c = 0; // Quantidade de ')'
    
    for (char ch : s)
    {
        if (ch == '(') o++;
        else c++;
        
        // Filtro 1: A sequência prefixo já quebrou a regra
        if (c > o)
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    
    // Filtro 2: O prefixo exigiu mais abertos do que podemos fechar
    if (o > n / 2)
    {
        cout << 0 << '\n';
        return 0;
    }
    
    int fo = (n / 2) - o;
    int fc = (n / 2) - c;
    int t = fo + fc;
    
    // Aplicação da fórmula do Princípio da Reflexão
    // (A - B + MOD) % MOD impede resultados negativos na subtração modular
    ll ans = (newton(t, fo) - newton(t, fo - 1) + base) % base;
	
	cout << ans << '\n';
	
	return 0;
}