/*

Left Rotate or counterclockwise - [1,2,3,4,5] -> 
                                    / / / / 
                           1times [2,3,4,5,1]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>leftRoate(vector<int> &nums){
    int first = nums[0];
    for(int i = 1; i < nums.size(); i++){
        nums[i - 1] = nums[i];
    }
    nums[nums.size() - 1] = first;
    return nums;
}
int main(){
    vector<int>nums = {1,2,3,4,5};
    nums = leftRoate(nums);
    for(int num : nums){
        cout<<num << " ";
    }
    cout<<endl;
}