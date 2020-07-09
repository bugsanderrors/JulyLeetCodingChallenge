/*
    3Sum

    Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

    Note:

    The solution set must not contain duplicate triplets.

    Example:
    Given array nums = [-1, 0, 1, 2, -1, -4],

    A solution set is:
    [
        [-1, 0, 1],
        [-1, -1, 2]
    ]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> m;
        
        set<vector<int>> ans;
        
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        int i, j;
        for(i=0; i<n; i++)
        {
            if(-nums[i] < 0)
                break;
                
            int j = i + 1;
            int k = n-1;
            while(j<k)
            {
                if(nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                {
                    vector<int> triplet(3,0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[j];
                    triplet[2] = nums[k];
                    res.push_back(triplet);
                    while(j<k && nums[j] == triplet[1])
                        j++;
                    while(j<k && nums[k] == triplet[2])
                        k--;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }

        return res;
    }
};