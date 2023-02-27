#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) { return a > b; }

int makeGroup(vector<int>& cards, vector<bool>& opened, int index)
{
    int cnt = 0;
    while (!opened[index])
    {
        opened[index] = true;
        index = cards[index] - 1;
        cnt++;
    }
    return cnt;
}

int solution(vector<int> cards) {
    int answer = 1;
    vector<bool> opened(cards.size(), false);
    vector<int> groups;

    for (int i = 0; i < cards.size(); i++)
    {
        if (opened[i]) continue;
        else groups.push_back(makeGroup(cards, opened, i));
    }
    sort(groups.begin(), groups.end(), compare);

    return groups.size() <= 1 ? 0 : groups[0] * groups[1];
}