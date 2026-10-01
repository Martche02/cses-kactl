//#pragma GCC optimize("O3,unroll-loops") // Força o compilador a acelerar loops ao máximo
// nao foi necessário, mas talvez seja em outro problema
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Nossa busca binária segura (não mexe, ela tá perfeita!)
ll integer_sqrt(ll n)
{
    if (n < 0) return 0;
    
    ll low = 0;
    ll high = 3000000;
    ll ans = 0;
    
    while (low <= high)
    {
        ll meio = low + (high - low) / 2;
        ll sq = meio * meio;
        
        if (sq <= n)
        {
            ans = meio;
            low = meio + 1;
        }
        else
        {
            high = meio - 1;
        }
    }
    
    return ans; 
}

bool is_square(ll n)
{
    if (n < 0) return false;
    ll root = integer_sqrt(n);
    return root * root == n;
}

bool is_triangular(ll n)
{
    return is_square(8LL * n + 1);
}

int teste(ll n)
{
    // Passo 1: É apenas 1 triângulo?
    if (is_triangular(n))
        return 1;
        
    // Passo 2: Otimização Dois Ponteiros com Adição
    ll esq = 1;
    ll tri_esq = 1; // T_1 = 1
    
    ll dir = integer_sqrt(2 * n) + 1;
    ll tri_dir = (dir * (dir + 1)) / 2;
    
    while (esq <= dir)
    {
        ll soma = tri_esq + tri_dir;
        
        if (soma == n) return 2;       // Achamos a dupla!
        
        if (soma < n) 
        {
            // Precisamos crescer o triângulo da esquerda
            esq++;
            tri_esq += esq; // Em vez de multiplicar/dividir, apenas somamos a nova base
        } 
        else 
        {
            // Precisamos encolher o triângulo da direita
            tri_dir -= dir; // Subtrai a base atual antes de reduzir
            dir--;
        }
    }
    
    // Passo 3: Se não é 1 nem 2, o Teorema de Gauss garante que é 3
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll testes;
    if (cin >> testes) {
        while(testes--)
        {
            ll n;
            cin >> n;
            cout << teste(n) << '\n';
        }
    }
    
    return 0;
}