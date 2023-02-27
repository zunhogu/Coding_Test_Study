#include <string>
#include <vector>
using namespace std;

int solution(int n) {

    vector<long long> dp;
    dp.push_back(3);    // 2
    dp.push_back(11);   // 4

    if (n % 2 == 0)
    {
        for (int i = dp.size(); i < n / 2; i++)
            dp.push_back((1000000007 + dp[i - 1] * 4 - dp[i - 2]) % 1000000007);
        return dp[n / 2 - 1];
    }
    else return 0;
}