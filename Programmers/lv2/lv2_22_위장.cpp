#include <string>
#include <vector>
using namespace std;

int find(vector<pair<string, int>> list, string str)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].first == str)
            return i;
    }

    return list.end() - list.begin();
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    vector<pair<string, int>> counts;

    for (int i = 0; i < clothes.size(); i++)
    {
        int index = find(counts, clothes[i][1]);
        if (index == counts.end() - counts.begin())
            counts.push_back(make_pair(clothes[i][1], 1));
        else
            counts[index].second += 1;
    }


    for (int i = 0; i < counts.size(); i++)
        answer *= (counts[i].second + 1);

    return answer - 1;
}