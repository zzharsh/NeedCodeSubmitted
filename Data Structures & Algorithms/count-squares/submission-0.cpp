class CountSquares {

    unordered_map<long, int> pointCount;
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        long key = point[0] * 10000 + point[1];
        pointCount[key]++;
    }
    
    int count(vector<int> point) {
        if(pointCount.size() < 3)
        {
            return 0;
        }
        int res = 0;
        for(auto it = pointCount.begin(); it != pointCount.end(); ++it)
        {
            long key = it->first;
            int a  = static_cast<int>(key/10000), b = static_cast<int>(key % 10000);
            vector<int> p3 = {a, b};
            int dx = abs(p3[0] - point[0]);
            int dy = abs(p3[1] - point[1]);
            cout<<dx<<" "<<dy<<" \n";
            if ((dx != 0) &&
                (dx == dy))
            {
                int c1 = it->second;
                long p1 = point[0] * 10000 + p3[1];
                long p2 = p3[0] * 10000 +  point[1];
                int c2 = pointCount[p1];
                int c3 = pointCount[p2];
                res += c1 * c2 * c3;
            }
        }
        return res;
    }
};
