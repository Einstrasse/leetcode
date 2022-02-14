class Solution {
public:
    int getNumberofPairSmallerThanM(vector<int>& nums, int M) {
        //M보다 distance가 작은 pair의 개수를 리턴함
        int ret = 0;
        for (int i=0; i + 1 < nums.size(); i++) {
            // i is left index of pair
            int l = i+1;
            int r = nums.size(); // Range is [l, r)
            while (l + 1 < r) {
                int m = (l+r) / 2;
                int dist = nums[m] - nums[i];
                if (dist > M) {
                    r = m;
                } else {
                    l = m;
                }
            }
            //l is right index of pair
            //adding only adjacent pair is smaller than M!
            if (nums[l] - nums[i] <= M) {
                ret += l - i;    
            }
            
        }
        return ret;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums.front(); // Range is [l, r]
        //Getting lower_bound
        while (l < r) {
            int m = (l+r)/2;
            int numSmallorEqual = getNumberofPairSmallerThanM(nums, m);
            //printf("%d, %d, %d => %d\n", l, m, r, numSmallorEqual);
            
            if (numSmallorEqual < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return r;
    }
};