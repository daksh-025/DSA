class Solution {
public:
    int f(int ind, vector <int>&ans, vector <int> &dp){
        if(ind == 0) return ans[0];
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take=ans[ind]+f(ind-2,ans,dp);
        int notTake=0+f(ind-1,ans,dp);
        return dp[ind]=max(take,notTake);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,-1);
        int sum=f(n-1,nums,dp);
        return sum;
        
    }
};