/*
Problem : Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
1. Do a sorting algo;
2. count a number of 0 1 and 2's
3. Dutch National Flag Algo - 
if mid == 0 swap with low and mid == 1 just move mid and if mid == 2 swap with high 

Time : O(N);
Space : O(1);
*/
#include<bits/stdc++.h>
using namespace std;

//Optimal Approach
void sort012Dutch(vector<int>& arr) {
        // code here
    int low = 0, mid = 0;
    int high =  arr.size()-1;
    while (mid <= high) // or contine till mid does not cross high; 
    {
        if(arr[mid] == 0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }else if(arr[mid] == 1){
            mid++;
        }else if(arr[mid] == 2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    
}

//Better approach
void sort012(vector<int>& arr) {
        // code here
    int zeros = 0, ones = 0, two = 0; // Initialize variables
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0) zeros++;
        else if(arr[i] == 1) ones++;
        else if(arr[i] == 2) two++;
    }
    for(int i = 0; i < zeros; i++){
        arr[i] = 0;
    }
    for(int i = zeros; i < (ones + zeros); i++){
        arr[i] = 1;

    }
    for(int i = (ones+zeros); i < arr.size(); i++){
        arr[i] = 2;
    }
}
int main(){
    vector<int>arr = {0, 1, 2, 0, 1, 2};
    sort012Dutch(arr);
    for(int num : arr){
        cout<<num<<" ";
    }
    cout<<endl;
}