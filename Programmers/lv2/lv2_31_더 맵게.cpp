#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) { return a > b; }

int solution(vector<int> scoville, int K) {
    int cnt = 0;

    make_heap(scoville.begin(), scoville.end(), compare);

    while (1)
    {
        int first = scoville.front();
        if (first < K)
        {
            if (scoville.size() <= 1)
                break;
            int second = 0;

            pop_heap(scoville.begin(), scoville.end(), compare);
            scoville.pop_back();

            pop_heap(scoville.begin(), scoville.end(), compare);
            second = scoville.back();
            scoville.pop_back();

            int newScoville = first + second * 2;

            scoville.push_back(newScoville);
            push_heap(scoville.begin(), scoville.end(), compare);

            cnt++;
        }
        else
            return cnt;
    }

    return -1;
}