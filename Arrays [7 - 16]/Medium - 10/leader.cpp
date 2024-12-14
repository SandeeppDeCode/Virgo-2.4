/*
PROBLEM : Given an integer array nums, return a list of all the leaders in the array.
"A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array."

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

Optimal : traver the the arr backward maintian a max Variable equalt to last element of array as last element is always the leader . while the elemnet in the array is greader than max add ti the leaders group;
Brute : using linear search 
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>leadersOptimal(vector<int>& nums){
    vector<int>leaders;
    leaders.push_back(nums[nums.size()-1]);
    int max = nums[nums.size()-1];
    for(int i = nums.size() - 2; i >= 0; i--){
        if(nums[i] > max){
            max = nums[i];
            leaders.push_back(nums[i]);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}
vector<int> leaders(vector<int>& nums) {
    vector<int>ans;
    for(int i = 0; i < nums.size(); i++){
        bool leader = true;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] >= nums[i]){
                leader = false;
                break;
            }
        }
        if(leader ){
            ans.push_back(nums[i]);
        }
    }

    return ans;
}
int main(){
    vector<int>nums = {9,83,90,86,90,100};
    for(auto it: leadersOptimal(nums)){
        cout<<it<<" ";
    }
    cout<<endl;
}