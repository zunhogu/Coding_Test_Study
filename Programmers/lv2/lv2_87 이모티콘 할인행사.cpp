#include <string>
#include <vector>
using namespace std;

void dfs(int depth, vector<vector<int>>& users, vector<int>& emoticons, vector<int> sale_rates, vector<int>& answer)
{
    if (depth + 1 > emoticons.size())
    {
        int total_member = 0, total_money = 0;
        for (int i = 0; i < users.size(); i++)
        {
            int min_sale_rate = users[i][0];
            int border = users[i][1];
            int member = 0, money = 0;

            for (int k = 0; k < sale_rates.size(); k++)
            {
                if (min_sale_rate <= sale_rates[k])
                    money += emoticons[k] * (100 - sale_rates[k]) / 100;
            }
            if (border <= money)
            {
                member++;
                money -= money;
            }

            total_member += member;
            total_money += money;
        }

        if (total_member > answer[0])
        {
            answer[0] = total_member;
            answer[1] = total_money;
        }
        else if (total_member == answer[0] && total_money > answer[1])
        {
            answer[0] = total_member;
            answer[1] = total_money;
        }
        return;
    }

    for (int i = 1; i < 5; i++)
    {
        sale_rates[depth] = 10 * i;
        dfs(depth + 1, users, emoticons, sale_rates, answer);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);
    vector<int> sale_rates(emoticons.size(), 0);

    dfs(0, users, emoticons, sale_rates, answer);

    return answer;
}