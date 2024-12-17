#include<bits/stdc++.h>
using namespace std;

/*
    MaxConsecutiveOne = take a pointer count the no of ones and compare with max and reset the pointer when found 0;
    Time = O(N);
    Space = O(1);
*/
int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int ones = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                ones++;
            }
            maxOnes = max(ones,maxOnes);
            if(nums[i] == 0){
                ones = 0;
            }

        }
        return maxOnes;
}

int main(){
    vector<int> nums = {1, 0, 1, 1, 1, 0, 1, 1, 1};
    cout<<findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}