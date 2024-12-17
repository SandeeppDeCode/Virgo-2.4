/*
Problem : 3Sum
Given an integer array nums.Return all triplets such that:
i != j, i != k, and j != k  // no dupiacte
nums[i] + nums[j] + nums[k] == 0.


Three Sum Problem (Optimal Solution)


The Three Sum Problem finds unique triplets in an array that sum to zero, using a time complexity of $$O(n^2).

Key Steps:
1. Sort the Array: To facilitate finding triplets and avoid duplicates.
2. Use Two Pointers:
   - For each element, set two pointers (`left` and `right`) to find pairs that sum with the current element to zero.
   - Skip duplicates to ensure uniqueness.
3. Adjust Pointers:
   - If the sum is zero, record the triplet and move both pointers.
   - If the sum is greater than zero, move `right` left; if less, move `left` right.

This method efficiently identifies all unique triplets that sum to zero.

*/

#include<bits/stdc++.h>
using namespace std;

//optimal  - time - O(NLogN * N * N) 
vector<vector<int>> threeSumOptimal(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(nums.size() > 0 && nums[i] == nums[i-1]) continue;
        int left = i  + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0){
                ans.push_back({nums[i] , nums[left] , nums[right]});
                left++;
                right--;
                while(left < right && (nums[left] == nums[left - 1])) left++;
                while(left < right && (nums[right] == nums[right + 1])) right--;
                //ensurign no dupliate;
            }else if(sum > 0){
                right--;
            }else if(sum < 0){
                left++;
            }
        }
        
    }
    return ans;
}
//better
vector<vector<int>> threeSumBetter(vector<int>& nums) {

    set<vector<int>> tripletSet;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int third = - (nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                tripletSet.insert(temp);
            }
                hashset.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());
        return ans;
}

//Brute 
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> tripletSet;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(),temp.end());
                    tripletSet.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(tripletSet.begin(),tripletSet.end());
    return ans;
}
int main(){
    vector<int> nums = {2, -2, 0, 3, -3, 5};

    vector<vector<int>> ans = threeSumOptimal(nums);

    // Print the result
    for (auto& triplet : ans) {
        cout << "[";
        for (auto& num : triplet) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}