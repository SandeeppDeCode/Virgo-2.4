#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>nums){
    if(nums.size() < 3){
        return -1;
    }
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int thirdLargest = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > largest){
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = nums[i];
        }else if(nums[i] > secondLargest && nums[i] < largest){
            thirdLargest = secondLargest;
            secondLargest = nums[i];
        }else if(nums[i] > thirdLargest && nums[i] < secondLargest){
            thirdLargest = nums[i];
        }
    }
    return thirdLargest != INT_MIN ? thirdLargest : -1;
}

int main(){
    vector<int> nums = {1,1,1,11};
    cout<<secondLargest(nums)<<endl;
}