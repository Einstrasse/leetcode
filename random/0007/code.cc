class Solution {
public:
    int reverse(int x) {
        unsigned int src = abs(x);
        unsigned int dst = 0;
        while (src > 0) {
            dst += src % 10;
            if (src >= 10) {
                if (dst > INT_MAX / 10) {
                    return 0;
                }
                dst *= 10;
            }
            src /= 10;
        }
        if (x > 0 && dst > INT_MAX) { 
            return 0;
        }
        if (x < 0 && dst > abs(INT_MIN)) {
            return 0;
        }
        return x > 0 ? (int)dst : -(int)dst;
    }
};