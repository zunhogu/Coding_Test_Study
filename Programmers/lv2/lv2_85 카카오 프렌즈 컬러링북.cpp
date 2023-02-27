#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> counts;
    vector<vector<bool>> mask(m, vector<bool>(n, false));

    for (int i = 0; i < picture.size(); i++)
    {
        for (int j = 0; j < picture[i].size(); j++)
            if (!picture[i][j]) mask[i][j] = true;
    }

    int row = 0, col = 0;

    for (int i = 0; i < picture.size(); i++)
    {
        for (int j = 0; j < picture[i].size(); j++)
        {
            if (!mask[i][j])
            {
                vector<pair<int, int>> st;
                st.push_back(make_pair(i, j));
                mask[i][j] = true;
                int cnt = 0;

                while (!st.empty())
                {
                    int curr_row = st.back().first;
                    int curr_col = st.back().second;
                    int curr_val = picture[curr_row][curr_col];
                    st.pop_back();
                    cnt++;

                    // 상
                    if (curr_row - 1 >= 0 && !mask[curr_row - 1][curr_col] && picture[curr_row - 1][curr_col] == curr_val)
                    {
                        mask[curr_row - 1][curr_col] = true;
                        st.push_back(make_pair(curr_row - 1, curr_col));
                    }
                    // 하
                    if (curr_row + 1 < m && !mask[curr_row + 1][curr_col] && picture[curr_row + 1][curr_col] == curr_val)
                    {
                        mask[curr_row + 1][curr_col] = true;
                        st.push_back(make_pair(curr_row + 1, curr_col));
                    }
                    // 좌
                    if (curr_col - 1 >= 0 && !mask[curr_row][curr_col - 1] && picture[curr_row][curr_col - 1] == curr_val)
                    {
                        mask[curr_row][curr_col - 1] = true;
                        st.push_back(make_pair(curr_row, curr_col - 1));
                    }
                    // 우
                    if (curr_col + 1 < n && !mask[curr_row][curr_col + 1] && picture[curr_row][curr_col + 1] == curr_val)
                    {
                        mask[curr_row][curr_col + 1] = true;
                        st.push_back(make_pair(curr_row, curr_col + 1));
                    }
                }
                counts.push_back(cnt);
            }
            else continue;
        }
    }

    vector<int> answer(2);
    answer[0] = counts.size();
    answer[1] = *max_element(counts.begin(), counts.end());
    return answer;
}