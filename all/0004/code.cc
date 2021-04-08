class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());
        int p, q, r;
        p = q = r = 0;
        while (p < nums1.size() && q < nums2.size()) {
            if (nums1[p] < nums2[q]) {
                merged[r++] = nums1[p++];
            } else {
                merged[r++] = nums2[q++];
            }
        }
        while (p < nums1.size()) {
            merged[r++] = nums1[p++];
        }
        while (q < nums2.size()) {
            merged[r++] = nums2[q++];
        }
        r--;
        if (r & 1) {
            return (merged[r/2] + merged[r/2+1]) / (double)2.0;
        } else {
            return merged[r/2];
        }
        
    }
};
