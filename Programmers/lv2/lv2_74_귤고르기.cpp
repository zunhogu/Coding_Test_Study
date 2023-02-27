#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) { return p1.second < p2.second; }

int solution(int k, vector<int> tangerine) {
    map<int, int> counts;

    for (int i = 0; i < tangerine.size(); i++)
    {
        map<int, int>::iterator iter = counts.find(tangerine[i]);
        if (iter == counts.end()) counts.insert(make_pair(tangerine[i], 1));
        else iter->second += 1;
    }

    vector<pair<int, int>> sortCounts(counts.begin(), counts.end());
    sort(sortCounts.begin(), sortCounts.end(), compare);

    vector<int> board;

    for (int i = 0; i < sortCounts.size(); i++)
    {
        for (int j = 0; j < sortCounts[i].second; j++)
            board.push_back(sortCounts[i].first);
    }

    for (int i = 0; i < tangerine.size() - k; i++)
        board.erase(board.begin());
    board.erase(unique(board.begin(), board.end()), board.end());

    return board.size();
}