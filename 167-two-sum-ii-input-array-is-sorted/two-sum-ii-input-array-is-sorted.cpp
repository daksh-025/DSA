class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int,int> mpp;
        int i=0;
        int find;
        for(auto it:numbers){
            mpp[it]=i;
            i++;

        }
        int j=0;
        for (auto it:numbers){
            find=target-it;
            if(mpp.find(find) != mpp.end()){
                return {j+1,mpp[find]+1};
            }
            j++;
        }
        return {};
    }
};