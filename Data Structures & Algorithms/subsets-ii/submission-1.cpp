class Solution {
    vector<vector<int>> ans;
    int dCount = 0;
    unordered_map<int, int> eleCount;
    vector<int> unique;
    void Subsets(int i, int j, vector<int> runningArray)
    {
        if(j > eleCount[unique[i]])
        {
            // runningArray.push_back(unique[i]);
            // ans.push_back(runningArray);
            return;
        }
        if(i == dCount)
        {
            // runningArray.push_back(unique[i]);
            // ans.push_back(runningArray);
            return;
        }
        Subsets(i+1, j, runningArray);
        // Subsets(i, j+1, runningArray);
        runningArray.push_back(unique[i]);
        cout<<i<<" "<<j<<" ";
        for(int k = 0;k<runningArray.size();++k)
        {
            cout<<runningArray[k]<<" ";
        }
        ans.push_back(runningArray);
        Subsets(i+1, j, runningArray);
        Subsets(i, j+1, runningArray);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size()==0)
        {
            return ans;
        }
        for (int i=0;i<nums.size();++i)
        {
            eleCount[nums[i]] +=1;
        }
        for (unordered_map<int, int>::iterator it = eleCount.begin(); it!=eleCount.end();++it)
        {
            unique.push_back(it->first);
        }
        dCount = eleCount.size();
        vector<int> V;
        ans.push_back(V);
        Subsets(0,1, V);

        return ans;

    }
};
