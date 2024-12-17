/*
Probelem : The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.



*/
#include<bits/stdc++.h>
using namespace std;

//Optimal Moore's Voting algo
int majorityElementOpimal(vector<int>& nums) {
    int count = 0;
    int el;
    for(int i = 0; i < nums.size(); i++){
        if(count == 0){
            count = 1;
            el = nums[i];
        }else if(nums[i] == el){
            count++;
        }else{
            count--;
        }
    }
    /* Checking if the stored element
         is the majority element*/
    int cnt1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == el) {
            cnt1++;
        }
    }
        
    if (cnt1 > (nums.size()/ 2)) {
            return el;
    }
        
        //return -1 if no such element found
    return -1;
}
//better - 
int majorityElementBetter(vector<int>& nums) {
    unordered_map<int,int>mpp;
    for(int num : nums){
        mpp[num]++;
    }

    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;


    return -1;

}
//bruteForce  
int majorityElement(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        int count =0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == nums[i]){
                count++;
            }
        }
        if(count > (nums.size()  / 2)){
            return nums[i];
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElementOpimal(arr);
    cout << "The majority element is: " << ans << endl;
    
    return 0;
}
