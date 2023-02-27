#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;

    vector<int> temp;
    for (int i = 1; i <= n; i++)
        temp.push_back(i);

    if (k == 1) return temp;

    vector<long long> dp;
    dp.push_back(1);
    dp.push_back(1);

    for (int i = 2; i <= n; i++)
        dp.push_back(dp.back() * i);


    k--;
    while (temp.size() != 1)
    {
        int index = k / dp[n - 1];
        answer.push_back(temp[index]);
        temp.erase(temp.begin() + index);
        k = k % dp[n - 1];
        n--;
    }
    answer.push_back(temp[0]);

    return answer;
}