#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    set<int> s;
    map<int, long long> m;
    vector<int> v;

    for (int i : weights)
    {
        s.insert(i);
        m[i]++;
    }

    for (int i : s)
    {
        v.push_back(i);
        answer += m[i] * (m[i] - 1) / 2;
    }

    vector<int> temp(s.size(), 0);
    temp[0] = 1; temp[1] = 1;
    do
    {
        vector<int> t;
        for (int i = 0; i < v.size(); i++)
            if (temp[i]) t.push_back(v[i]);
        float div = (float)t[0] / t[1];

        if (div == 2.0f / 4.0f) answer += 1 * m[t[0]] * m[t[1]];
        else if (div == 2.0f / 3.0f) answer += 1 * m[t[0]] * m[t[1]];
        else if (div == 3.0f / 4.0f) answer += 1 * m[t[0]] * m[t[1]];
    } while (prev_permutation(temp.begin(), temp.end()));

    return answer;
}