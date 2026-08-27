class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        // Count frequency
        for (int num : nums) {
            mpp[num]++;
        }

        // bucket[i] contains numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : mpp) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        // Start from highest frequency
        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    break;
                }
            }
        }

        return ans;
    }
};