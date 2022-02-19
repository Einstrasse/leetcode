typedef struct _State {
    int x, y, z; //z mean number of tools left to break obstacles
} State;
const int dx[] = {+1, -1, +0, +0};
const int dy[] = {+0, +0, +1, -1};
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        /*
        This problem is similar to simple BFS shortest path problem.
        Adding constraints like obstacle elimination.
        Just redefining state, I can defeat this problem.
        */
        
        //Initialize values
        bool visit[40][40][1600];
        int dist[40][40][1600];
        for (size_t i=0; i < grid.size(); i++) {
            for (size_t j=0;j < grid[0].size() ;j++) {
                for (size_t l = 0; l <= k; l++) {
                    visit[i][j][l] = false;
                    dist[i][j][l] = INT_MAX;
                }
            }
        }
        
        
        queue<State> q;
        //Insert initial state
        visit[0][0][k] = true;
        dist[0][0][k] = 0;
        q.push({0, 0, k});
        //Execute BFS for shortest_path
        while (q.size()) {
            State state = q.front();
            q.pop();
            //Check adjacent cells
            for (int d = 0; d < 4; d++) {
                int nx = state.x + dx[d];
                int ny = state.y + dy[d];
                int cur_dist = dist[state.x][state.y][state.z];
                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) {
                    continue;
                }
                if (grid[nx][ny] == 1) {
                    //Wall break case
                    if (state.z > 0 && visit[nx][ny][state.z - 1] == false) {
                        visit[nx][ny][state.z - 1] = true;
                        q.push({nx, ny, state.z - 1});
                        dist[nx][ny][state.z - 1] = cur_dist + 1;
                    }
                } else {
                    if (visit[nx][ny][state.z] == false) {
                        visit[nx][ny][state.z] = true;
                        q.push({nx, ny, state.z});
                        dist[nx][ny][state.z] = cur_dist + 1;
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i=0; i <= k; i++) {
            ans = min(ans, dist[grid.size() -1][grid[0].size() -1][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};