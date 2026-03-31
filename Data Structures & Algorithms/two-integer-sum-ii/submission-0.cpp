class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, n= numbers.size(), j=i+1;
        vector<int> res;
        while(i<n && j<n)
        {
            if(numbers[i] + numbers[j] == target)
            {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            if(numbers[i] + numbers[j] > target)
            {
                i++;
                if(j==i)
                {
                    ++j;
                }
            }
            ++j;
        }
        return res;
    }
};
