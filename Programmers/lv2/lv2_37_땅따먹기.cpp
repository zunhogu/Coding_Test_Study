#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    vector<int> dp;

    dp.push_back(land[0][0]);
    dp.push_back(land[0][1]);
    dp.push_back(land[0][2]);
    dp.push_back(land[0][3]);

    for (int row = 1; row < land.size(); row++)
    {
        for (int col = 0; col < 4; col++)
        {
            vector<int> result;
            if (col != 0) result.push_back(dp[(row - 1) * 4] + land[row][col]);
            if (col != 1) result.push_back(dp[(row - 1) * 4 + 1] + land[row][col]);
            if (col != 2) result.push_back(dp[(row - 1) * 4 + 2] + land[row][col]);
            if (col != 3) result.push_back(dp[(row - 1) * 4 + 3] + land[row][col]);

            dp.push_back(*max_element(result.begin(), result.end()));
        }
    }

    return *max_element(dp.end() - 4, dp.end());
}