/*
    moveZeroToEnd -> zeroIndex pointer, when a nonzeroElement is found you swap the nums[i] with zeroPointerIndex and increae the pointer
    Time = O(N);
    Space = O(1);
*/
#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int zeroPointer = 0;
    for(int i = 0; i < nums.size();i++){
        if(nums[i] != 0){
            swap(nums[i],nums[zeroPointer]);
            zeroPointer++;
        }
    }
}
int main(){
    vector<int>nums ={0, 1, 4, 0, 5, 2};
    moveZeroes(nums);
    for(int num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}   