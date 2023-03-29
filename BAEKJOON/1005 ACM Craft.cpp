#include <iostream>
#include <vector>

void recursive(std::vector<int>& times, std::vector<std::pair<int ,int>>& rules, std::vector<int>& dp, int num)
{
    for(int i=0; i<rules.size(); i++)
    {
        if(rules[i].second == num)
        {
            recursive(times, rules, dp, rules[i].first);
            dp[num-1] = std::max(dp[rules[i].first-1] + times[rules[i].first-1], dp[num-1]);
        }
    }
}

int main()
{
    int T;
    std::cin >> T;

    while(T--)
    {
        int cnt, rule_cnt, win_condition;
        std::cin >> cnt >> rule_cnt;
        std::vector<int> times(cnt, 0);
        std::vector<std::pair<int ,int>> rules(rule_cnt);
        std::vector<int> dp(cnt, 0);

        for(int i=0; i<cnt; i++)
            std::cin >> times[i];
        for(int i=0; i<rule_cnt; i++)
            std::cin >> rules[i].first >> rules[i].second;
        std::cin >> win_condition;

        recursive(times, rules, dp, win_condition);
        std::cout << dp[win_condition-1] + times[win_condition-1] << "\n";
    }

    return 0;
}