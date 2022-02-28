class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1)
            return 5;
        vector<vector<int>> dp(n,vector<int>(5));
        
        for(int i=0;i<5;i++)
        {
            dp[0][i]=1;
        }
        int sum=5;
        for(int i=1;i<n;i++)
        {
            dp[i][0]=sum;
           // sum=0;
            for(int j=1;j<5;j++)
            {
                dp[i][j]=dp[i][j-1]-dp[i-1][j-1];
                sum+=dp[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<5;i++)
        {
            ans+=dp[n-1][i];
        }
        return ans;
    }
};
