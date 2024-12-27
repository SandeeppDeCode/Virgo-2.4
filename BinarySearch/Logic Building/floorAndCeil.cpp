/*
Given a sorted array nums and an integer x. 
Find the floor and ceil of x in nums. 
The floor of x is the largest element in the array which is smaller than or equal to x. 
The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

*/
#include<bits/stdc++.h>
using namespace std;

int floor(vector<int>nums,int x){
    int floor = -1;
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] <= x){
            floor = nums[mid];
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return floor;
}
int ceil(vector<int>nums,int x){
    int ceil = -1;
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] >= x){
            ceil = nums[mid];
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ceil;
}
vector<int> getFloorAndCeilOptimal(vector<int> nums, int x) {
    return {floor(nums,x),ceil(nums,x)};
}
vector<int> getFloorAndCeilBrute(vector<int> nums, int x) {
    int floor = -1;
    for(int i =0; i < nums.size();i++){
        if(nums[i] <= x){
            floor = nums[i];
        }
    }
    int ceil = -1;
    for(int i =0; i < nums.size();i++){
        if(nums[i] >= x){
            ceil = nums[i];
            break;
        }
    }
    return {floor,ceil};

}

int main() {
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 12;



    vector<int> result = getFloorAndCeilOptimal(nums, x);

    cout << "The floor and ceil are: " << result[0] << " " << result[1] << endl;

    return 0;
}
