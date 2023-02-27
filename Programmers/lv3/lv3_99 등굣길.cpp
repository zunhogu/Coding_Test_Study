#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    dp[0][0] = 1;
    for(int i=0; i<puddles.size(); i++)
        dp[puddles[i][1]-1][puddles[i][0]-1] = -1;
    
    for(int i=0; i<dp.size(); i++)
    {
        for(int j=0; j<dp[i].size(); j++)
        {
            if(dp[i][j] == -1) continue;
            
            int left_row = i, left_col = j-1;
            int top_row = i-1, top_col = j;
            
            if(left_col>=0 && dp[left_row][left_col] != -1)
                dp[i][j] = (dp[i][j] % 1000000007 + dp[left_row][left_col] % 1000000007) % 1000000007;
            if(top_row>=0 && dp[top_row][top_col] != -1)
                dp[i][j] = (dp[i][j] % 1000000007 + dp[top_row][top_col] % 1000000007) % 1000000007;
        }
    }
    
    return dp[n-1][m-1];
}