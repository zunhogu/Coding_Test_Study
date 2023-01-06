#include <string>
#include <vector>
using namespace std;

void dfs(int k, int i, int count, int& maxCount, vector<vector<int>> dungeons)
{
    if (k >= dungeons[i][0])
    {
        k -= dungeons[i][1];
        dungeons.erase(dungeons.begin() + i);
        count++;
        if (count > maxCount)
            maxCount = count;
    }
    else
        return;

    for (int j = 0; j < dungeons.size(); j++)
        dfs(k, j, count, maxCount, dungeons);

    return;
}

int solution(int k, vector<vector<int>> dungeons) {

    int max = -1;
    for (int i = 0; i < dungeons.size(); i++)
        dfs(k, i, 0, max, dungeons);

    return max;
}