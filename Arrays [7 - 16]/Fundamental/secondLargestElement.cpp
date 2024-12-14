#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>nums){
    if(nums.size() < 2){
        return -1;
    }
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }else if(nums[i] > secondLargest && nums[i] < largest){
            secondLargest = nums[i];
        }
    }
    return secondLargest != INT_MIN ? secondLargest : -1;
}

int main(){
    vector<int> nums = {1,2};
    cout<<secondLargest(nums)<<endl;
}