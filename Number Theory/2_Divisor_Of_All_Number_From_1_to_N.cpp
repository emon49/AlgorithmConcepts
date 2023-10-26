#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> divisor[n + 1];
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i * i <= j; i++)
        {
            if ((j % i) == 0)
            {
                divisor[j].push_back(i);
                if ((j / i) != i)
                    divisor[j].push_back(j / i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto u : divisor[i])
            cout << u << " ";
        cout << endl;
    }
}
// TC : O( n * sqrt(n))