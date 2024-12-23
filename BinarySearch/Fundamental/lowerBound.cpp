/*
Lower Bound: 
Given a sorted array of nums and an integer x, write a program to find the lower bound of x. The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

If no such index is found, return the size of the array.

Alogo :
Finds the smallest index with nums[mid] >= x using binary search. 
If nums[mid] >= x, update ans  and search left (high = mid - 1), 
otherwise search right (low = mid + 1).

*/

#include <bits/stdc++.h>
using namespace std;


int lowerBound(vector<int>& nums, int x) {
    int ans = nums.size();
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high ) / 2;
        if(nums[mid] >= x){
            //mid value greater than target serach left
            ans = mid;
            high = mid - 1;
        }else{
            //here mid value is less than target so search right
            low = mid + 1;
        }
    }
    return ans;
}


int main() {
    vector<int> arr = {1, 2, 2, 3};
    int x = 2;

    int ind = lowerBound(arr, x);
    
    cout << "The lower bound is the index: " << ind << "\n";
    
    return 0;
}