class Solution {
public:
    int makePair(int a, int b)
    {
        return ( a + 100000 ) * 1000000 + b;  
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_multimap<int, int>  remaining_values;
        unordered_set<int> IJ;
        multimap<int, int> sorted_values;
        for(int i = 0;i<nums.size();++i)
        {
            sorted_values.insert(make_pair(nums[i], i));
            remaining_values.insert(make_pair(nums[i], i));
        }
        for(auto it1 = sorted_values.begin(); it1 != sorted_values.end();++it1)
        {
            remaining_values.erase(it1->first);
            unordered_multimap<int, int>  jRemaining_values = remaining_values;
            for(auto it2 = next(it1); it2!=sorted_values.end(); ++it2)
            {
                jRemaining_values.erase(it2->first);
                if(IJ.find(makePair(it1->first, it2->first)) == IJ.end())
                {
                    IJ.insert(makePair(it1->first, it2->first));
                    IJ.insert(makePair(it2->first, it1->first));
                    cout<<it1->first<<" "<<it2->first<<" "<<jRemaining_values.size()<<" "<<IJ.size()<<"\n";
                    if(jRemaining_values.find(0 - (it1->first + it2->first)) != jRemaining_values.end())
                    {
                        vector<int> A(3,0);
                        A[0] = it1->first;
                        A[1] = it2->first;
                        A[2] = 0 - (it1->first + it2->first);
                        ans.push_back(A);
                    }
                }
            }
        }
        return ans;
    }
};
