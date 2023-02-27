#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int height = maps.size();
    int width = maps[0].length();
    vector<vector<bool>> visited(height, vector<bool>(width, false));

    vector<pair<int, int>> st;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (maps[i][j] == 'X' || visited[i][j]) continue;
            else
            {
                int day_sum = 0;
                st.push_back(make_pair(i, j));
                visited[i][j] = true;
                while (!st.empty())
                {
                    pair<int, int> curr = st.back();
                    st.pop_back();
                    day_sum += maps[curr.first][curr.second] - 48;
                    for (pair<int, int> next : { make_pair(curr.first - 1, curr.second), make_pair(curr.first + 1, curr.second),
                                               make_pair(curr.first, curr.second - 1), make_pair(curr.first, curr.second + 1) })
                    {
                        if (!(next.first >= 0 && next.first < height && next.second >= 0 && next.second < width)) continue;
                        if (!visited[next.first][next.second] && maps[next.first][next.second] != 'X')
                        {
                            st.push_back(make_pair(next.first, next.second));
                            visited[next.first][next.second] = true;
                        }
                    }
                }
                if (day_sum) answer.push_back(day_sum);
            }
        }
    }

    if (answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());

    return answer;
}