
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());
    }
};
int main()
{

    cout << "cc" << endl;
}


/*

  void rotate(vector<int>& nums, int k) {
        int i = 0;
       k=nums.size()-k;
        while (k--)
        {
            int t = nums[i];
            nums.erase(nums.begin() + i);
            nums.push_back(t);
            // i++;
        } 
    }
*/