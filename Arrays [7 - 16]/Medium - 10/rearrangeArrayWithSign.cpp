/*
Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given conditions are meet;

1. Every consecutive pair of integers have opposite signs.
2. For all integers with the same sign, the order in which they were present in nums is preserved.
3. The rearranged array begins with a positive integer.


Brute : Separate the negative and postive value;
Optimal : Use the pointer method; pointer point to odd and even loaction

Time : O(N);
Space : O(1);
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArrayOptimal(vector<int>& nums) {
    vector<int>ans(nums.size());
    int pos = 0; // even;
    int neg = 1; // odd;
    for(int num : nums){
        if(num > 0){
            ans[pos] = num;
            pos += 2;
        }else{
            ans[neg] = num;
            neg += 2;
        }
    }
    return ans;
}
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> positive, negative, ans;
    
    // Separate positive and negative numbers
    for (int num : nums) {
        if (num > 0) {
            positive.push_back(num);
        } else {
            negative.push_back(num);
        }
    }
    
    // Merge positive and negative numbers alternately
    int pos = 0, neg = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            ans.push_back(positive[pos++]); // Positive at even indices
        } else {
            ans.push_back(negative[neg++]); // Negative at odd indices
        }
    }
    
    return ans;
}

int main() {
    vector<int> A = {2, 4, 5, -1, -3, -4};
    
    vector<int> ans = rearrangeArrayOptimal(A);
    
    for (int num : ans) {
        cout << num << " ";
    }
    
    return 0;
}
