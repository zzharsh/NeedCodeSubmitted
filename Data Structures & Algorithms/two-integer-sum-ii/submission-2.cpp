class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, n= numbers.size();
        int j=n-1;
        vector<int> res;
        while(i<n && j>i)
        {
            cout<<i<<" "<<j<<" "<<numbers[i] + numbers[j]<<"\n";
            if(numbers[i] + numbers[j] == target)
            {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else
            {
                --j;
            }
        }
        return res;
    }
};
