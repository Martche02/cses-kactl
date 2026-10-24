/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: 2010\J.cpp
 * Problem: Maratona 2010 - J
 * Description:
 *   Implementation for Maratona 2010 - J
 */
#include <bits/stdc++.h>

using namespace std;

int mex(vector<int>& she, vector<int>& we, int i)(*@\label{fn34}@*)
{
    for (; i <= 52; i++)
    {
        if ( !(i == she[0]
        || i == she[1]
        || i == she[2]
        || i == we[0]
        || i == we[1]
        ))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    bool end = false;
    while (!end)
    {
        vector<int> she(3), we(2);
        for (auto& i : she)
            cin >> i;
        for (auto& i : we)
            cin >> i;

        if (she[0] == 0)
            break;

        sort(she.begin(), she.end());
        sort(we.begin(), we.end());

        if (we[0] > she[2])
        {
            cout << mex(she, we, 1) << "\n";
            continue;
        }

        if (we[0] < she[1] && we[1] < she[2])
        {
            cout << -1 << '\n';
            continue;
        }

        // we[1] X she[0]

        if (we[0] > she[1]) // she[1] < we[0] < she[2]
            cout << mex(she, we, she[1]) << '\n';
        else
            cout << mex(she, we, she[2]) << '\n';
    }


    return 0;
}