#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
// Macro segura para subtração/adição modular
#define RES(V) (((V) % MOD + MOD) % MOD)

int B = 18; // 18 já é suficiente para N = 200.000 (1<<18 = 262144)
int MAX_MASK = 1 << B;
const int MAX_N = 200005;

constexpr std::array<int, MAX_N> precalc_pot2() {
    std::array<int, MAX_N> arr{}; 
    arr[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        arr[i] = (1LL * arr[i - 1] * 2) % MOD;
    }
    return arr;
}

constexpr auto pot2 = precalc_pot2();

int main()
{
    // Otimização I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> super(MAX_MASK, 0);
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        super[x]++;
    }
    
    // Ida (Soma)
    for (int bit = 0; bit < B; bit++)
        for (int i = 0; i < MAX_MASK; i++)
            if (!(i & (1 << bit)))
                 super[i] = (super[i] + super[i ^ (1 << bit)]) % MOD;
            
    // Mutação
    for (auto& i : super)
        i = RES(pot2[i] - 1);
            
    // Volta (Subtração)
    for (int bit = 0; bit < B; bit++)
        for (int i = 0; i < MAX_MASK; i++)
            if (!(i & (1 << bit)))
                 super[i] = RES(super[i] - super[i ^ (1 << bit)]);
    
    // Imprimir respostas do número 0 até o número N
    for (int i = 0; i <= n; i++)
        cout << super[i] << (i == n ? "" : " ");
    
    cout << '\n';
    
    return 0;
}