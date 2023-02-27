#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> dp(1000001, -1);
    queue<int> q;
    dp[x] = 0;
    q.push(x);

    while (!q.empty())
    {
        int cur_x = q.front();
        q.pop();

        for (auto new_x : { cur_x + n, cur_x * 2, cur_x * 3 })
        {
            if (new_x < 0 || new_x>y) continue;
            dp[new_x] = dp[cur_x] + 1;
            q.push(new_x);
        }
    }

    return dp[y];
}