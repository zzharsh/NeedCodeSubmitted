class Solution {
public:
    vector<int> parents;
    void Union(int a, int b)
    {
        int pA = Find(a);
        int pB = Find(b);
        parents[a] = min(pA, pB);
        parents[b] = min(pA, pB);
        parents[pA] = min(pA, pB);
        parents[pB] = min(pA, pB);
    }
    int Find(int a)
    {
        while(parents[a] != a)
        {
            a = parents[a];
        }
        return a;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents.resize(n+1);

        for(int i = 0; i < n; ++i)
        {
            parents[i+1] = i+1;
        }
        for(int i = 0; i < n; ++i)
        {
            int c1 = Find(edges[i][0]);
            int c2 = Find(edges[i][1]);
            cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<c1<<" "<<c2;
            if(c1 == c2)
            {
                return edges[i];
            }
            Union(edges[i][0], edges[i][1]);
            c1 = Find(edges[i][0]);
            c2 = Find(edges[i][1]);
            cout<<" "<<c1<<" "<<c2<<"\n";
        }
        return {};
    }
};
