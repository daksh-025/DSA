
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                int nse = i;

                maxArea = max(maxArea,
                              heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();
            int nse = n;

            maxArea = max(maxArea,
                          heights[element] * (nse - pse - 1));
        }

        return maxArea;
    }
};
