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
using minte = Mint<MOD-1>;

int main()
{
	int n;
	cin >> n;
	mint count = 1;
	mint sum = 1;
	mint product = 1;
	minte counte = 1;
	
	while (n--)
	{
		ll x, k;
		cin >> x >> k;
		count *= (k+1);
		sum *= (mint(x).pow(k+1) -1)*(mint(x-1).inv());
		product = product.pow(k+1) * mint(x).pow((counte*minte(k*(k+1)/2)).v);
		
		counte *= (k+1);
		
	}
	
	
	cout << count << ' '
		 << sum   << ' '
		 << product << endl;
	
	return 0;
}