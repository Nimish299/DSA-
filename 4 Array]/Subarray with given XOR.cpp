
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B)
{
    int n = A.size(); // size of the given array.
    int xr = 0;
    int k = B;
    map<int, int> mpp; // declaring the map.
    mpp[xr]++;         // setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i:
        xr = xr ^ A[i];

        // By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}