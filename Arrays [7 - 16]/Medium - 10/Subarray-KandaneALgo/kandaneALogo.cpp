/*
Problem : 
Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.\


Kandane Algo - keep a running sum comapre with max and when sum is less than 0 that reset the sum to 0 beauce we dotn want to carry neagtive beacue that will decrease the sum;
*/

#include<bits/stdc++.h>
using namespace std;

//Optimal - Kandane alg0
int maxSubArrayOptimal(vector<int>&nums){
    int maxi = INT_MIN, sum = 0;
    for(int i = 0; i < nums.size();i++){
        sum += nums[i];
        maxi = max(sum,maxi);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}
//Better - dont repeat the previous subarray;
int maxSubArrayBetter(vector<int>& nums) {
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {   
            sum += nums[j];
            maxi = max(maxi,sum);
        }
        
    }
    return maxi;
}
//Basic Brute-Generate all the subaray
int maxSubArray(vector<int>& nums) {
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {   
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += nums[k];
               
            }
             maxi = max(maxi,sum);
        }
        
    }
    return maxi;
}

int main() {
    vector<int> arr = { -4,-3,-2,-1};

    int maxSum = maxSubArrayOptimal(arr);
    
    //Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}