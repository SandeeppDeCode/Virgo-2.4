/*
Problem : TWO SUM 
    Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.

[1, 6, 2, 10, 3 ] target = 7;
ans = 0, 1

Optmial - use a hashmap and check if the hashmap contain the difference of the target - currentElemnet of array;
*/
#include<bits/stdc++.h>
using namespace std;

//Better

vector<int> twoSumOptimal(vector<int>& nums, int target) {
        
    unordered_map<int, int> mpp; 
    int n = nums.size(); 

    for (int i = 0; i < n; i++) {

        int num = nums[i];
        int moreNeeded = target - num;

        //if more needed found in map; // not found that will equal to end();
        if(mpp.find(moreNeeded) != mpp.end()){
            return{ mpp[moreNeeded],i};
        }
        mpp[num] = i;
    }

    return {-1, -1};
}

//brute Force 
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>ans;

    for(int i = 0; i < nums.size();i++){

        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}
int main(){
    int n = 5;
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;
    


    
    // Call the twoSum method to find the indices
    vector<int> ans = twoSumOptimal( nums, target);
    
    // Print the result
    cout << "This is the answer: [" << ans[0] << ", " << ans[1] << "]" << endl;
    
    return 0;
}