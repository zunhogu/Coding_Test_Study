#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end());
    int hIndex = 0;

    vector<int> hIdxs;
    hIdxs.push_back(0);
    while (hIndex < citations[citations.size() - 1])
    {
        int lCnt = 0;
        int rCnt = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] < hIndex)
                lCnt++;
            else if (citations[i] >= hIndex)
                break;
        }
        rCnt = citations.size() - lCnt;

        if (lCnt <= hIndex && rCnt >= hIndex)
            hIdxs.push_back(hIndex);
        hIndex++;
    }

    return hIdxs[hIdxs.size() - 1];
}