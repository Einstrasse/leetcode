const int dx[] = {+1, -1, +0, +0};
const int dy[] = {+0, +0, +1, -1};
typedef pair<int, int> pos;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0 ;
        for (int i=0; i < grid.size(); i++) {
            for (int j=0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    
                    //do dfs iteratively
                    stack<pos> stk;
                    grid[i][j] = '0';
                    stk.push(make_pair(i, j));
                    while (stk.size()) {
                        pos p = stk.top(); stk.pop();
                        for (int k=0; k< 4; k++) {
                            int nx = p.first + dx[k];
                            int ny = p.second + dy[k];
                            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[nx].size() && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                stk.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};