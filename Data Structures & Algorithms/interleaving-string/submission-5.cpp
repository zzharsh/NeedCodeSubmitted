class Solution {
    int DP[101][101] = { -1 };
    string str1, str2, str3;
    bool DPfun(int i, int j)
    {
        // cout<<i<<" "<<j<<" "<<DP[i][j]<<"\n";
        if(DP[i][j] != -1)
        {
            // cout<<"Harsh ";
            return DP[i][j];
        }
        if((i==str1.size()) && (j==str2.size()))
        {
            // cout<<"Harsh1 ";
            DP[i][j] = 1;
            return DP[i][j];
        }
        if(str1[i]!=str3[i+j] && str2[j]!=str3[i+j])
        {
            // cout<<"harsh ";
            DP[i][j]=0;
            return DP[i][j];
        }
        if((str1[i] == str3[i+j]) && (str2[j] == str3[i+j]))
        {
            // DP[i][j] = 1;
            DPfun(i+1,j);
            if(DP[i+1][j] == 1)
            {
                // cout<<"Harsh2 ";

                DP[i][j] = 1;
                return DP[i+1][j];
            }
            DP[i][j] = DPfun(i,j+1);
            // cout<<"Harsh3 ";

            return DP[i][j];
        }
        if(i<str1.size() && str1[i]==str3[i+j])
        {
            DP[i][j] = DPfun(i+1,j);
            // cout<<"Harsh4 ";

            return DP[i][j];
        }
        if(j<str2.size() && str2[j]==str3[i+j])
        {
            DP[i][j] = DPfun(i,j+1);
            // cout<<"Harsh5 ";
            return DP[i][j];
        }
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        str1 = s1;
        str2 = s2;
        str3 = s3;
        for (int ii=0;ii<=str1.size();++ii)
        {
            for(int jj=0;jj<=str2.size();++jj)
            {
                DP[ii][jj] = -1;
            }
            // cout<<"\n";
        }
        DPfun(0,0);
        // for (int ii=0;ii<str1.size();++ii)
        // {
        //     for(int jj=0;jj<str2.size();++jj)
        //     {
        //         cout<<DP[ii][jj]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return DP[0][0];
        // int i=0, j=0;
        // cout<<i<<" "<<j<<" "<<DP[i][j]<<"\n";
        
        // if(DP[i][j] == 0)
        // {
        //     return false;
        // }
        // else if(DP[i][j] == 1)
        // {
        //     return true;
        // }
        // while(i+j<s3.size())
        // {
        //     if((s3[i+j] == s1[i]) && (s3[i+j] == s2[j]))
        //     {
        //         // i++;
        //         DP[++i][j] = isInterleave(s1, s2, s3);
        //         if(DP[i][j] == true)
        //         {
        //             return true;
        //         }
        //         DP[--i][++j] = isInterleave(s1, s2, s3);
        //         if(DP[i][j] ==true)
        //         {
        //             return true;
        //         }
        //     }
        //     if(s3[i+j] == s1[i])
        //     {
        //         ++i;
        //     }
        //     else if(s3[i+j] == s2[j])
        //     {
        //         ++j;
        //     }
        //     else
        //     {
        //         DP[i][j] =0;
        //         return false;
                
        //     }
        // }
        // DP[i][j] = 1;
        // return true;
    }
};
