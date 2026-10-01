#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<int MOD>
struct Mint 
{
    int v;
    
    Mint() : v(0) {}
    Mint(ll val)
	{
        v = val % MOD;
        if (v < 0) v += MOD;
    }

    // Operadores de atribuição (O Segredo da Velocidade)
    // O if (+ e -) é ~15x mais rápido que usar %
    Mint& operator+=(Mint o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(Mint o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(Mint o) { v = (ll)v * o.v % MOD; return *this; } // Cast seguro
    Mint& operator/=(Mint o) { return *this *= o.inv(); }

    // Operadores aritméticos puros
    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b; }

    // Exponenciação rápida e Inverso Modular embutidos
    Mint pow(ll b) const
	{
        Mint res = 1, a = *this;
        while (b > 0)
		{
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
		
        return res;
    }
	
    Mint inv() const { return pow(MOD - 2); }

    // Operadores de Comparação
    friend bool operator==(Mint a, Mint b) { return a.v == b.v; }
    friend bool operator!=(Mint a, Mint b) { return a.v != b.v; }

    // Facilita o cin/cout direto na variável
    friend istream& operator>>(istream& is, Mint& m) { ll x; is >> x; m = Mint(x); return is; }
    friend ostream& operator<<(ostream& os, Mint m) { return os << m.v; }
};

// Instância oficial para o CSES
const int MOD = 1e9 + 7;
using mint = Mint<MOD>;

int main()
{
	ll n;
	cin >> n;
	
	mint sum = 0;
	ll L = 1;
	while (L <= n)
	{
		ll q = n / L; // L aparece q vezes
		ll R = n / q; // R aparece q vezes
		
		sum  = sum + q * mint(R+L)*mint(R-L+1)/2;
		
		
		L = R + 1;
	}
	
	cout << sum << endl;
	
	return 0;
}