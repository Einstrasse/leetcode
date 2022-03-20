class DetectSquares {
private:
    map<pair<int, int>, int> pos;
    map<int, int> ypos[1001];
    
public:
    DetectSquares() {
        pos.clear();
        for (int i=0; i <=1000; i++) {
            ypos[i].clear();
        }
    }
    
    void add(vector<int> point) {
        pos[make_pair(point[0], point[1])]++;
        ypos[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x1 = point[0];
        int y1 = point[1];
        for (auto it : ypos[y1]) {
            int x2 = it.first;
            int num = it.second;
            if (x1 == x2) continue;
            int len = abs(x2 - x1);
            for (int y2 = y1 - len; y2 <= y1 + len; y2 += len + len) {
                if (y2 >= 0 && y2 <= 1000 && ypos[y2].find(x1) != ypos[y2].end() && ypos[y2].find(x2) != ypos[y2].end()) {
                    ans += num * ypos[y2][x1] * ypos[y2][x2];
                }
            }
        }
        return ans;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */