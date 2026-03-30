class Solution {
    vector<vector<int>> ans;
    int dCount = 0;
    unordered_map<int, int> eleCount;
    vector<int> unique;
    void Subsets(int i, int j, vector<int> runningArray)
    {

        cout<<"\n H "<<i<<" ";
        if(i >= dCount)
        {
            return;
        }
        
        for(j = 1; j <= eleCount[unique[i]]; ++j)
        {
            runningArray.push_back(unique[i]);
            for(int k = 0;k<runningArray.size();++k)
            {
                cout<<runningArray[k]<<" ";
            }
            ans.push_back(runningArray);
            for(int l = i; l<dCount;)
            {
                l++;
                Subsets(l, j, runningArray);
            }
        }


        return;
        // if( j == eleCount[unique[i]])
        // {
        //     Subsets(i+1, j, runningArray);
        // }
        // Subsets(i, j+1, runningArray);
        // cout;
        runningArray.push_back(unique[i]);
        
        for(int k = 0;k<runningArray.size();++k)
        {
            cout<<runningArray[k]<<" ";
        }
        ans.push_back(runningArray);
        int dd = j;
        while(dd<=eleCount[unique[i]])
        {
            runningArray.push_back(unique[i]);
            for(int k = 0;k<runningArray.size();++k)
            {
                cout<<runningArray[k]<<" ";
            }
            // cout<<"\n";
            ans.push_back(runningArray);
            Subsets(i+1, j, runningArray);
            dd++;
        }
        // dd = j;
        // while(dd!=eleCount[unique[i]]+1)
        // {
            // Subsets(i, ++dd, runningArray);
        // }
        // Subsets(i, ++dd, runningArray);

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
            cout<<it->first<<"->"<<it->second<<" ";
        }
        // cout<<"\n";
        dCount = eleCount.size();
        vector<int> V;
        ans.push_back(V);
        for (int m = 0;m<dCount;++m)
        {
            Subsets(m, 1, V);
        }

        return ans;

    }
};
