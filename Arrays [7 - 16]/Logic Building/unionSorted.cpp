/*
Problem  : UNION OF TWO SORTED ARRAY - all the element no repaeation

Brute - using set dsa
Optimal : use two pointer method
Time : O(M * N);
Space : O(N) for stroing the answer;
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> unionArrayOptimal(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {

        if (nums1[i] < nums2[j])
        {
            if (ans.empty() || ans.back() != nums1[i])
            {
                ans.push_back(nums1[i]);
            }
            i++;
        }
        else
        {
            if (ans.empty() || ans.back() != nums2[j])
            {
                ans.push_back(nums2[j]);
            }
            j++;
        }
    }
    while (i < nums1.size())
    {
        if (ans.empty() || ans.back() != nums1[i])
        {
            ans.push_back(nums1[i]);
        }
        i++;
    }
    while (j < nums2.size())
    {
        if (ans.empty() || ans.back() != nums2[j])
        {
            ans.push_back(nums2[j]);
        }
        j++;
    }

    return ans;
}
vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s;
    vector<int> ans;
    for (int num : nums1)
        s.insert(num);
    for (int num : nums2)
        s.insert(num);
    for (auto it : s)
    {
        ans.push_back(it);
    }
    return ans;
}
int main()
{
    vector<int> num1 = {1, 2, 3, 4, 5}, num2 = {1, 2, 7};
    for (int num : unionArrayOptimal(num1, num2))
    {
        cout << num << " ";
    }
    cout << endl;
}