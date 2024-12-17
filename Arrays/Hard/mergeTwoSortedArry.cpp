/*
Merge Two Sorted array : 

Using extra space - using two pointer method
Using no Extra Space - 
*/

#include<bits/stdc++.h>
using namespace std;



//optmial
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m - 1; // Pointer for nums1
        int j = n - 1; // Pointer for nums2
        int k = m + n - 1; // Pointer for merged array

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--]; // Place from nums1
            } else {
                nums1[k--] = nums2[j--]; // Place from nums2
            }
        }

        // If there are remaining elements in nums2
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
}

//without usign space

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m - 1;
    int right = 0;
    while( left >= 0 && right < n){
        if(nums1[left] > nums2[right]){
            swap(nums1[left],nums2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
}
//brute force;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ans;
    int i = 0; 
    int j = 0;
    while(i < m && j < n){
        if(nums1[i] <= nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }else{
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i < m){
        ans.push_back(nums1[i]);
        i++;
    }
    while(j < n){
        ans.push_back(nums2[j]);
        j++;
    }
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
}
//Time -  o(M + N);
//Space - O(M + N);
int main(){
    vector<int> nums1 = {-5, -2, 4, 5,0,0,0};
    vector<int> nums2 = {-3, 1, 8};
    merge(nums1,nums1.size(),nums2,nums2.size());
}