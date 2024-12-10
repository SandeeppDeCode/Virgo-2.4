/*
Problem : INTERSECTION OF TWO ARRAY  -  Common element

Optimal Soln : usign two pointer method;
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i  < nums1.size() && j < nums2.size())
    {
        if(nums1[i] == nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            j++;
        }else if(nums1[i] < nums2[j]){
            i++;
        }else{
            j++;
        }
        
    }
    return ans;
    
}
int main(){
    vector<int> num1 = {1, 2, 3, 4, 5}, num2 = {1, 2, 7};
    for (int num : intersectionArray(num1, num2))
    {
        cout << num << " ";
    }
    cout << endl;
}