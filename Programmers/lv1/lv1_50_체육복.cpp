#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    stable_sort(lost.begin(), lost.end());
    stable_sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            int index = find(reserve.begin(), reserve.end(), lost[i]) - reserve.begin();
            if (reserve.end() - reserve.begin() != index)
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + index);
            }
        }
    }


    int count = n - lost.size();
    for (int i = 0; i < lost.size(); i++)
    {
        int index = find(reserve.begin(), reserve.end(), lost[i] - 1) - reserve.begin();
        if (reserve.end() - reserve.begin() != index)
        {
            reserve.erase(reserve.begin() + index);
            count++;
            continue;
        }

        index = find(reserve.begin(), reserve.end(), lost[i] + 1) - reserve.begin();
        if (reserve.end() - reserve.begin() != index)
        {
            reserve.erase(reserve.begin() + index);
            count++;
            continue;
        }
    }

    return count;
}