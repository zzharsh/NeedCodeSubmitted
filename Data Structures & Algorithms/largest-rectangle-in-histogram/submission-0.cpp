class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<vector<int>> S;
        int i = 0, res = 0, n = heights.size();
        for(i = 0; i < n; ++i)
        {
            res = max(res, heights[i]);
            if(S.empty())
            {
                S.push({heights[i], i});
            }
            else
            {
                int area = 0;
                vector<int> tp = {heights[i], i};
                while(!S.empty() && S.top()[0] >= heights[i])
                {
                    tp = S.top();
                    area = min(S.top()[0], heights[i]) * (i - S.top()[1] +1);
                    res = max(res, area);
                    cout<<i<<" "<<heights[i]<<" "<<area<<" "<<res<<"\n";
                    S.pop();
                }
                if(!S.empty())
                {
                    area = min(S.top()[0], heights[i]) * (i - S.top()[1] +1);
                    res = max(res, area);
                }
                S.push({heights[i], tp[1]});
            }
        }
        return res;
    }
};
