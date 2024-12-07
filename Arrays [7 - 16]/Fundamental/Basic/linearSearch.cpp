/*
Linear search
    iterate the array and look for target;
*/

#include<bits/stdc++.h>
using namespace std;


int linearSearch(vector<int>& nums, int target) {

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i; 
        }
    }
    return -1; 
}
int main(){

    vector<int>nums = {1,2,4,6,7};
    cout<<linearSearch(nums,9)<<endl;

}

/*
Time : o(n)
space : O(1)
*/