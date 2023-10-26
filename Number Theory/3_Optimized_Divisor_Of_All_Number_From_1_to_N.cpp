#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6+123;
int main()
{
    int n;
    cin >> n;
    vector<int> divisor[mx];
    for(int i=1; i<=n; i++){
        for(int j=i; j <= n; j+=i){
            divisor[j].push_back(i);
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
// Harmonic series : H(n) = 1 + 1/2 + 1/3 + ... + 1/n
/*
The time complexity of this code is O(n * log(n)). Let's break it down step by step:

1. You have a loop that iterates from `i = 1` to `i = n`. This outer loop runs for `n` iterations, which is O(n).

2. Inside the outer loop, you have an inner loop that iterates from `j = i` to `j = n` with a step size of `i`. This means that for each value of `i`, the inner loop will run `n/i` times.

3. Inside the inner loop, you are pushing values into the `divisor[j]` vector. The `push_back` operation for a vector is generally considered to have an amortized constant time complexity, O(1).

So, the total time complexity is the product of the time taken by each level of the loop:

O(n) * O(n/i) * O(1) = O(n) * O(n/i) = O(n^2/i)

To get the overall time complexity, you need to sum up this expression for all possible values of `i` from 1 to `n`. In this case, you have to compute the sum of:

O(n^2/1) + O(n^2/2) + O(n^2/3) + ... + O(n^2/n)

This sum is approximately O(n * log(n)) because it resembles the harmonic series, which grows with a logarithmic factor. So, the time complexity of your code is O(n * log(n)).

*/