#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    long double exp = 0.0;

    for (int i = 0; i < k; i++) {
        exp += 1.0 - pow((long double)i / k, n);
    }

    // Sem cast, sem epsilon, puro long double.
    cout << fixed << setprecision(6) << exp << '\n';

    return 0;
}