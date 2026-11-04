class Solution {
public:
    long long totalHrs(vector<int>& piles, int rate) {
        long long totalhrs = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalhrs += (piles[i] + rate - 1LL) / rate;
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int minRate = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long Rate = totalHrs(piles, mid);

            if (Rate <= h) {
                minRate = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return minRate;
    }
};