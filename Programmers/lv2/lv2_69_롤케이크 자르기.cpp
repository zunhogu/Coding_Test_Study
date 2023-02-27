#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    vector<int> dp1;
    map<int, int> counts1;

    vector<int> dp2;
    map<int, int> counts2;

    for (int i = 0; i < topping.size(); i++)
    {
        map<int, int>::iterator iter = counts1.find(topping[i]);
        if (iter == counts1.end())
            counts1.insert(make_pair(topping[i], 1));
        else
            iter->second++;
        dp1.push_back(counts1.size());
    }

    for (int i = topping.size() - 1; i >= 0; i--)
    {
        map<int, int>::iterator iter = counts2.find(topping[i]);
        if (iter == counts2.end())
            counts2.insert(make_pair(topping[i], 1));
        else
            iter->second++;
        dp2.push_back(counts2.size());
    }

    reverse(dp2.begin(), dp2.end());

    for (int i = 0; i < dp1.size() - 1; i++)
    {
        if (dp1[i] == dp2[i + 1])
            answer++;
    }

    return answer;
}