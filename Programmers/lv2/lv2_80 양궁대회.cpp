#include <string>
#include <vector>
#include <iostream>
using namespace std;

int max_diff = -1;

void dfs(int depth, vector<int>& info, vector<int> lion, int n, vector<int>& result, bool flag)
{
    if (depth == 10)
    {
        int arrow_cnt = 0;
        for (int i = 0; i < lion.size(); i++)
            arrow_cnt += lion[i];
        if (arrow_cnt > n) return;
        else if (arrow_cnt < n) lion[lion.size() - 1] = n - arrow_cnt;

        // 어피치와 라이언의 점수차
        int diff = 0;
        int apeach_score = 0, lion_score = 0;

        for (int i = 0; i < 11; i++)
        {
            if (info[i] < lion[i]) lion_score += 10 - i;
            else
                apeach_score += info[i] == 0 ? 0 : 10 - i;
        }

        diff = lion_score - apeach_score;
        if (diff > 0)
        {
            if (max_diff < diff)
            {
                max_diff = diff;
                result = lion;
            }
            else if (max_diff == diff)
            {
                int idx1, idx2;
                for (int i = 10; i >= 0; i--)
                {
                    if (result[i] != 0)
                    {
                        idx1 = i;
                        break;
                    }
                }

                for (int i = 10; i >= 0; i--)
                {
                    if (lion[i] != 0)
                    {
                        idx2 = i;
                        break;
                    }
                }

                if (idx1 <= idx2)
                {
                    max_diff = diff;
                    result = lion;
                }
            }
        }
        return;
    }

    if (flag)
    {
        // depth 점을 얻을 경우
        lion[depth] = info[depth] + 1;
        dfs(depth + 1, info, lion, n, result, true);
        dfs(depth + 1, info, lion, n, result, false);
    }
    else
    {
        // depth 점을 얻지 않을 경우
        dfs(depth + 1, info, lion, n, result, true);
        dfs(depth + 1, info, lion, n, result, false);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> lion(11, 0);
    vector<int> result;

    dfs(0, info, lion, n, result, true);
    dfs(0, info, lion, n, result, false);

    if (max_diff == -1) result.push_back(-1);

    return result;
}