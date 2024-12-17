#include <bits/stdc++.h>
using namespace std;

// Optimal - Time Complexity: O(N^3)
vector<vector<int>> fourSumOptimal(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for j
            int left = j + 1;
            int right = n - 1;
            while (left < right) {
                long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++; // Skip duplicates for left
                    while (left < right && nums[right] == nums[right + 1]) right--; // Skip duplicates for right
                } else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSumOptimal(nums, target);
    
    for (const auto& triplet : result) {
        cout << "{ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
