class Solution {
public:
    int trap(vector<int>& height) {
        /*
        스택에는 내림차순 순으로 heigth가 저장된다. 즉 top의 값이 가장 낮은 height이다.
        (height, x_pos)가 저장된다.
        top보다 높은 녀석을 만나면 스택에 원소가 2개 이상이라는 가정하에(왼쪽 봉이 있음) 
        지금 top위를 깔고 있는 양 만큼 물을 채우게 된다.
        */
        stack<pair<int, int>> stk;
        int ans = 0;
        for (size_t i=0; i < height.size(); i++) {
            int h = height[i];
            
            while (stk.size() && stk.top().first < h) {
                if (stk.size() > 1) { //왼쪽 기둥이 있는 경우만 더함
                    auto under = stk.top(); //깔아주는애
                    stk.pop();//이제 stk.top()은 왼쪽 기둥이 된다.
                    ans += (i - stk.top().second - 1) * (min(h, stk.top().first) - under.first);
                } else {
                    //왼쪽 기둥없이 높아지기만 하면 그냥 빼기만 함
                    stk.pop();
                }
            }
            
            stk.push(make_pair(h, i));
        }
        return ans;
    
    }
};
