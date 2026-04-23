class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Initialize sliding window variables
        int l = 0, r = 0;      // Left and right pointers
        int maxlen = 0;        // Maximum length found
        int zeroes = 0;        // Count of zeros in current window
        
        // Step 2: Expand window to the right
        while(r < n) {
            // Step 3: Track zeros in window
            if(nums[r] == 0) 
                zeroes++;
            
            // Step 4: Shrink window if too many zeros
            if(zeroes > k) {
                if(nums[l] == 0) 
                    zeroes--;  // Removing a zero from window
                l++;           // Shrink from left
            }
            
            // Step 5: Update maximum length when valid
            if(zeroes <= k) {
                maxlen = max(maxlen, r - l + 1);
            }
            
            // Step 6: Move right pointer forward
            r++;
        }
        
        // Step 7: Return result
        return maxlen;
    }
};