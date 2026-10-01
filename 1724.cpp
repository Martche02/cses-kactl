#include <bits/stdc++.h>

using namespace std;
using u128 = __uint128_t;
using ll = long long;

constexpr ll inf = LLONG_MAX;

template <int N>
struct Matrix 
{
    ll m[N][N];
    
    // Construtor: Inicializa tudo com zero (evita lixo de memória)
    Matrix() 
	{
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = inf;
    }
	
	Matrix(initializer_list<ll> lst)
	{
        auto it = lst.begin();
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                if (it != lst.end()) 
				{
                    m[i][j] = *it;
                    it++;
                } 
				else 
				{
                    m[i][j] = 0;
                }
    }
    
    // Ajuda a criar a matriz identidade (diagonal de 1s)
    static Matrix identity() 
	{
        Matrix res;
        for (int i = 0; i < N; i++)
            res.m[i][i] = 0;
        return res;
    }

    // Sobrecarga da Multiplicação (Matriz * Matriz)
    Matrix operator*(const Matrix& other) const 
	{
        Matrix res; // Já nasce zerada graças ao construtor
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
				{
					// o melhor caminho de i->j vai ser o mínimo dentre i->j e i->k->j, pra todo k
					// a coisa é que temos que testar tanto i->k quanto k->j pra inf, pois se for
					// descartamos
					if (m[i][k] != inf && other.m[k][j] != inf)
						res.m[i][j] = min(res.m[i][j], m[i][k] + other.m[k][j]);
				}

        return res;
    }

    // Sobrecarga da Exponenciação (Matriz ^ Exp) - O seu Binpow!
    Matrix operator^(ll exp) const
	{
        Matrix res = Matrix::identity();
        Matrix base = *this; // Faz uma cópia para ir elevando ao quadrado
        
        while (exp > 0)
		{
            if (exp % 2 == 1) res = res * base;
            base = base * base;
            exp /= 2;
        }
		
        return res;
    }
};

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
	
	Matrix<101> adj;
	
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj.m[a][b] = min(adj.m[a][b], (ll)c);
	}
    
    Matrix<101> kadj = adj ^ k;
    
	ll ret = kadj.m[1][n];
	
	if (ret != inf)
		cout << kadj.m[1][n] << '\n';
    else
		cout << -1 << '\n';
    return 0;
}