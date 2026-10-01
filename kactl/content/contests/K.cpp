/**
 * Author: Team KACTL / Marce
 * Category: Contests
 * Problem: K
 * Description:
 *   Implementation for K
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u128 = __uint128_t;

constexpr ll base = 998244353;
const ll top = 1e5+15;
 
ll fat[top];
ll ifat[top];
ll pot[top];

ll binpow(ll a, ll b)
{
	ll res = 1;
	a %= base;
	while (b > 0)
	{
		if (b % 2 == 1) 
			res = (u128)res * a % base;
		a = (u128)a * a % base;
		b /= 2;
	}
	
	return res;
	
}

void transform(vector<ll>&a, bool inverse = false)
{
	int n = a.size();
	
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) 
			j ^= bit;
		j ^= bit;
		if (j > i) 
			swap(a[i], a[j]);
	}
	
	
	for (int len = 2; len <= n; len <<= 1)
	{
		ll w_len = binpow(3, (base-1)/len);
		if (inverse)
			w_len = binpow(w_len, base-2);
		
		for (int i = 0; i < n; i += len)
		{
			ll w = 1;
			for (int j = 0; j < len/2; j++)
			{
				ll u = a[i+j];
				ll v = (w*a[i + j + len/2])%base;
				
				a[i+j] = ( u + v < base ? u + v : u + v - base);
				a[i + j + len/2] = (u < v ? u - v + base : u - v);
				
				w = (w * w_len) % base;
			}
		}
	}
	
	if (inverse)
	{
		ll inv = binpow(n, base-2);
		for (auto& i : a)
			i = (i*inv)%base;
	}	
}

vector<ll> ntt(vector<ll> a, vector<ll> b)
{
	int n = 1;
	
	while (n < a.size() + b.size())
		n <<= 1;
	
	a.resize(n,0);
	b.resize(n,0);
	
	transform(a, false);
	transform(b, false);
	
	for (int i = 0; i < n; i++)
		a[i] = (a[i] * b[i])%base;
	
	transform(a, true);
	
	return a;
	
}

vector<ll> taylor_swift(const vector<ll>& o, ll k_shift)
{
	ll n = o.size();
	// A_i = o_i*i!
	// B_i = des^i/i!
	// C_j = sum[i=k->n](A_i*B_(i-j))
	// fazendo as seguintes substituicoes pra formatar como mulitiplicação de polinomio
	// Arev_i = A_(n-i) [em indice 1, em indice 0 seria n-1-i)
	// l = i-j
	// h = n-j
	// C_(n-h) = sum[l=0->h](Arev_(j-l)*B_l)
	// note que C esta "invertido"
	vector<ll> Arev(n), B(n);
	
	ll current_k_pow = 1; // Substitui o vetor 'pot' global
	
	for (int i = 0; i < n; i++)
	{
		Arev[n-1-i] = (o[i] * fat[i]) % base;
		B[i] = (current_k_pow * ifat[i]) % base;
		
		// Avança a potência para o próximo ciclo
		current_k_pow = (current_k_pow * k_shift) % base;
	}
	
	vector<ll> r = ntt(Arev, B);
	vector<ll> c(n);
	
	for (int i = 0; i < n; i++)
		c[i] = (r[n-1-i] * ifat[i]) % base;
	
	return c;	
}

int main()
{
    // Otimização clássica para I/O rápido
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Pré-computa fatoriais em O(top)
	fat[0] = 1;
	ifat[0] = 1;
	for (int i = 1; i < top; i++)
		fat[i] = (fat[i-1]*i)%base;
	
	ifat[top-1] = binpow(fat[top-1], base-2);
	
	for (int i = top-1; i > 0; i--)
		ifat[i-1] = (ifat[i]*i)%base;

    // Leitura das variáveis ajustada
	int degree;
	ll k;
	if (!(cin >> degree >> k)) return 0;
	
	int n = degree + 1; // O grau N possui N+1 coeficientes!
	
	vector<ll> t(n);
	vector<ll> p(n);
	
	for (auto& i : t) cin >> i;
	for (auto& i : p) cin >> i;
	
	// Trata K negativo automaticamente graças à matemática modular
	ll k_plus  = (k % base + base) % base;
	ll k_minus = (-k % base + base) % base;
	
	// t está na base x + k -> shift de +K
	// p está na base x - k -> shift de -K
	vector<ll> t_x = taylor_swift(t, k_plus);
	vector<ll> p_x = taylor_swift(p, k_minus);
	
	// Imprime a resposta
	for (int i = 0; i < n; i++)
		cout << (t_x[i] + p_x[i]) % base << (i == n - 1 ? "" : " ");
	
	cout << "\n";

	return 0;
}
