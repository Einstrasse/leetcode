#include <cstring>
struct State {
    int pos, speed, dir;
};

class Solution {
public:
    int racecar(int target) {
        int dp[10004][17][2] = {0,};
        queue<State> q;
        q.push({0, 0, 1}); //pos, speed, direction;
        //dp[0][1][1] = 0;
        while (q.size()) {
            State state = q.front();
            q.pop();
            State acc = {state.pos + (1 << state.speed) * (state.dir == 1 ? 1 : -1), state.speed +1, state.dir};
            if (acc.pos >= 0 && acc.pos <= 10000 && acc.speed < 17 && dp[acc.pos][acc.speed][state.dir] == 0) {
                dp[acc.pos][acc.speed][state.dir] = dp[state.pos][state.speed][state.dir] + 1;
                q.push(acc);
                if (acc.pos == target) {
                    return dp[acc.pos][acc.speed][state.dir];
                }
            }
            State rev = {state.pos, 0, !state.dir};
            if (dp[rev.pos][rev.speed][rev.dir] == 0) {
                dp[rev.pos][rev.speed][rev.dir] = dp[state.pos][state.speed][state.dir] + 1;
                q.push(rev);
            }
        }
        return -1;
        // 6 = 110(2)
        /*
        In Base2(binary digit)
        1 -> 11 -> 111 -> 1111 -> 11111 -> 111111
        With single reverse operation
        111111 -> 111110 -> 111100 -> 111000
        
        101010101010
        
        101010
        111111 => 6
        100000 => 5 + 1
        101111 => 4 + 1
        101000 => 3 + 1
        101011 => 2 + 1
        101010 => 1 + 1
        
        2^10 = 1024 ~= 10^3
        2^14 = 16 * 1024 < 10^4
        101010101010
         11111111111
        111111111111 => 14
        100000000000 => 13 + 1
        101111111111 => 12 + 1
        101000000000 => 11 + 1
        101011111111 => 10 + 1
        */
    }
};