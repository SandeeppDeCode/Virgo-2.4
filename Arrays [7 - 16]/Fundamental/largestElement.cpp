/*
Largest Element
    take a maxElement = arr[0] and comapre with all element of array
*/

#include<bits/stdc++.h>
using namespace std;


int largestElement(vector<int>& nums, int target) {
    int largest = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }
    return largest; 
}
int main(){

    vector<int>nums = {1};
    cout<<largestElement(nums,9)<<endl;

}

/*
Time : o(n)
space : O(1)
*/