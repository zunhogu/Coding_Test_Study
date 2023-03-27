#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    int count;
    std::vector<std::pair<int, int>> dp;
    dp.push_back(std::make_pair(1, 0));
    dp.push_back(std::make_pair(0, 1));

    std::cin >> count;

    for (int i = 0; i < count; i++)
    {
        int tmp;
        std::cin >> tmp;
        for (int j = dp.size(); j <= tmp; j++)
            dp.push_back(std::make_pair(dp[j-2].first + dp[j-1].first, dp[j - 2].second + dp[j - 1].second));
        std::cout << dp[tmp].first << " " << dp[tmp].second << std::endl;
    }

    return 0;
}