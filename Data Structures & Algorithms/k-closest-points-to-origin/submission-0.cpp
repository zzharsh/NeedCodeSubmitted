class Solution {
public:
    int distance(vector<int>& point)
    {
        return (point[0] * point[0] + point[1] * point[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, vector<int>> kD;
        for(int i = 0; i<points.size(); ++i)
        {
            kD.insert(make_pair(distance(points[i]), points[i]));
            if(k<=i)
            {
                auto it = kD.end();
                it--;
                cout<<"Deleting "<<it->second[0]<<", "<<it->second[1]<<"\n";
                // kD.insert(make_pair(distance(points[i])))
                kD.erase(it);
            }
        }
        vector<vector<int>> res;
        for(auto it = kD.begin(); it!=kD.end(); ++it)
        {
            res.push_back(it->second);
        }
        return res;

    }
};
