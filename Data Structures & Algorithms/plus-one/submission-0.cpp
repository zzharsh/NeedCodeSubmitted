class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        int track = 0;
        while (i>=0)
        {
            if(digits[i] == 9)
            {
                // track = 1;
                digits[i] = 0;
                i--;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;

    }
};
