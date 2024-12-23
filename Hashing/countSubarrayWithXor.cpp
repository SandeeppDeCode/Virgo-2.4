/*
Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.
*/
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorKOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    int xr = 0;
    map<int, int> mpp;
    // setting the value of 0.
    mpp[xr]++;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i:
        xr = xr ^ nums[i];

        // By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i into the map:
        mpp[xr]++;
    }
    return cnt;
}
int subarraysWithXorKBetter(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;

    // Step 1: Generate subarrays
    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for (int j = i; j < n; j++)
        {
            /* Step 2: Calculate XOR of
               all elements in the subarray */
            xorr = xorr ^ nums[j];

            // Step 3: Check XOR and count
            if (xorr == k)
                cnt++;
        }
    }
    return cnt;
}
int subarraysWithXorKBrute(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;

    // Step 1: Generate subarrays
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xorr = 0;
            /* Step 2: Calculate XOR of
               all elements in the subarray */
            for (int K = i; K <= j; K++)
            {
                xorr = xorr ^ nums[K];
            }
            // Step 3: Check XOR and count
            if (xorr == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    int ans = subarraysWithXorKBetter(a, k);

    cout << "The number of subarrays with XOR k is: " << ans << "\n";
    return 0;
}