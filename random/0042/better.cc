class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left, right;
        left.push_back(height.front());
        for (int i=1; i < height.size(); i++) {
            left.push_back(max(left.back(), height[i]));
        }
        right.push_back(height.back());
        for (int i=height.size() - 2; i >= 0; i--) {
            right.push_back(max(right.back(), height[i]));
        }
        reverse(right.begin(), right.end());
        int ans = 0;
        for (int i=0; i < height.size(); i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};