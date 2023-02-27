#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);

    for (int i = 0; i < n; i++)
        dp.push_back((dp[i] + dp[i + 1]) % 1000000007);

    return dp.back();
}