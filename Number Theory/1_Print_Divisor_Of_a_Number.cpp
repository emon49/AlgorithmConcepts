#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> divisor;
    for (int i = 1; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            divisor.push_back(i);
            if ((n / i) != i)
                divisor.push_back(n / i);
        }
    }
    sort(divisor.begin(), divisor.end());
    for (auto u : divisor)
        cout << u << " ";
}
// // TC : O(sqrt(n)) -> To find nod except sort function, SC : O(n)