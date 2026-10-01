#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll base = 1e9+7;
using u128 = __uint128_t;


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

// Pelo Lema de Burnside, precisamos da quantidade de "pontos fixos" de cada rotação.
// Semanticamente, rotacionar 'i' posições quebra o colar em gcd(i, n) ciclos independentes, 
// onde cada ciclo tem tamanho n / gcd(i, n).
// Como todas as pérolas do mesmo ciclo precisam ter a mesma cor para o colar não mudar visualmente,
// temos 'm' escolhas de cores para cada um dos gcd(i, n) ciclos. Logo: m^gcd(i, n) colares invariantes.
int main()
{
	int n, m;
	cin >> n >> m;
	
	ll acc = 0;
	
	//burnside: tamanho do grupo = média dos pontos fixos sob cada operação
	//assim, tamanho do grupo é média dos tamanhos dos conjuntos de "arranjos" que ficam iguais depois de i-rotação
	for (int i = 0; i<n; i++)
	{
		// no caso de ser grupo de rotações, o tamanho do conjunto pode ser obtido via m**gdc(i,n)
		// semanticamente, i-rotação gera gdc ciclos de tamanho n/gdc
		ll ciclos = gcd(i, n);
		
		acc = (acc + binpow(m, ciclos, base)) % base;
	}
	
	ll umsobren = binpow(n, base-2, base);
	
	cout << (acc * umsobren) % base << endl;
	

	return 0;
}