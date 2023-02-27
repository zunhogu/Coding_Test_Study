#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp;
    
    for (int i = 0; i < triangle.size(); i++)
        dp.push_back(vector<int>(triangle[i].size(), 0));
    dp[0][0] = triangle[0][0];

    for (int i = 0; i < triangle.size() - 1; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            dp[i + 1][j] = max(dp[i + 1][j], triangle[i + 1][j] + dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], triangle[i + 1][j + 1] + dp[i][j]);
        }
    }
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
            answer = max(answer, dp[i][j]);
    }
    return answer;
}