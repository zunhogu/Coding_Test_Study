#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

void dfs(vector<int> vec, int index, int sum, int target, int& cnt)
{
    if (index < vec.size())
    {
        dfs(vec, index + 1, sum + vec[index], target, cnt);
        dfs(vec, index + 1, sum - vec[index], target, cnt);
    }
    else
    {
        if (sum == target)
            cnt++;
    }
}

int solution(vector<int> numbers, int target) {
    int cnt = 0;

    dfs(numbers, 0, 0, target, cnt);

    return cnt;
}