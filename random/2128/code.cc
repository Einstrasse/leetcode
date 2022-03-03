class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        vector<bool> rowOper(grid.size(), false);
        for (int i=0; i< grid.size(); i++) {
            if (grid[i].front() == 1) {
                rowOper[i] = true;
            }
        }
        for (int i=0; i < grid.front().size(); i++) {
            int base = grid[0][i] ^ rowOper[0];
            for (int j=1; j < grid.size(); j++) {
                int v = grid[j][i] ^ rowOper[j];
                if (base != v) {
                    return false;
                }
            }
        }
        return true;
    }
};
/*
000
000
000

111 011
000 100
000 100

100 011
100 100
100 100

operation order doesn't matter.

Just doing column level operation, all row should be uniform pattern.
-> Not for all row alignment, just one row alignment should be okay
Uniform row pattern => removing all '1' is possible with row-level operation.
*/