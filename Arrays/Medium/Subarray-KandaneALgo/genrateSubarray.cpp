/*
**Subarray**: Contiguous elements maintaining order.
[1,2,3]
1
1 2
1 2 3
2
2 3
3

total  = n(n+1)/2;
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>generateSubarray(vector<int>nums){
    vector<vector<int>>ans;
    for (int i = 0; i < nums.size(); i++)
    {

        for(int j = i; j < nums.size(); j++){
            vector<int>temp;
            //range i - j;
            for(int k = i; k <= j; k++){
                temp.push_back(nums[k]);
            }
            ans.push_back(temp);

        }
    }
    return ans;
    
}
int main(){
    vector<int>nums = {1,2,3,4};
    for(auto it: generateSubarray(nums)){

        for(int num : it){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
}