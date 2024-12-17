/*
Problem : 
Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.


Optimal - using suffix and prfix method 
*/

#include<bits/stdc++.h>
using namespace std;

//Optimal

int maxProductOptimal(vector<int>& nums) {
    int pre = 1,suff = 1;
    int ans = INT_MIN;
    for(int i = 0; i < nums.size();i++){
        if(pre == 0) pre = 1;
        if(suff == 0) pre = 1;

        pre = pre * nums[i];
        suff = suff * nums[nums.size() - i - 1];
        ans = max(ans,max(pre,suff)); 
    } 
    return ans;
}

//better - ;
int maxProductBetter(vector<int>& nums) {
    int maxPro = -1;
    for(int i = 0; i < nums.size(); i++){
        int pro = 1;
        for(int j = i; j < nums.size(); j++){

            pro *= nums[j];
            maxPro = max(pro,maxPro);
        }
    }
    return maxPro;
}
//brute - genreate all the subarray
int maxProduct(vector<int>& nums) {
    int maxPro = -1;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            int pro = 1;
            for(int k = i; k <= j; k++){
                pro *= nums[k];
            }
            maxPro = max(pro,maxPro);
        }
    }
    return maxPro;
}
int main(){
    vector<int> nums = {4, 5, 3, 7, 1, 2};
    

    int maxProd = maxProductOptimal(nums);
    
    // Print the result
    cout << "The maximum product subarray: " << maxProd << endl;
    
    return 0;
}