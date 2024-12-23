/*
Binary Search  -
Finds target in a sorted array using binary search. 
-If nums[mid] == target, return mid. 
-If nums[mid] > target, search left (high = mid - 1), 
-otherwise search right (low = mid + 1).
Sorted so either we eliminate left portion or right portion 

Time : o(log n );
space : o(n);
*/

#include<bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            //mid value greter than target serach in left portion
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}


int main() {
    vector<int> a = {-1, 0, 3, 5, 9, 12}; 
    int target = 9; 

    // Creating an instance of Solution class


    // Function call to find the given target in a sorted array
    int ind = search(a, target); 
    
    if(ind == -1) 
        cout << "The target is not present." << endl;
    else 
        cout << "The target is at index: " << ind << endl;
    
    return 0;
}
