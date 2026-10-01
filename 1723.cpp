#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7; // Renomeei para MOD por clareza (opcional)
using u128 = __uint128_t;

template <int N>
struct Matrix 
{
    ll m[N][N];
    
    // Construtor: Inicializa tudo com zero (evita lixo de memória)
    Matrix() 
	{
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = 0;
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
            res.m[i][i] = 1;
        return res;
    }

    // Sobrecarga da Multiplicação (Matriz * Matriz)
    Matrix operator*(const Matrix& other) const 
	{
        Matrix res; // Já nasce zerada graças ao construtor
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    res.m[i][j] = (res.m[i][j] + (u128)m[i][k] * other.m[k][j]) % MOD;

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
		int a, b;
		cin >> a >> b;
		adj.m[a][b]++;
	}
    
    Matrix<101> kadj = adj ^ k;
    
    cout << kadj.m[1][n] << '\n';
    
    return 0;
}