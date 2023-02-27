#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    deque<int> dq;

    sort(people.begin(), people.end());
    for (int i = 0; i < people.size(); i++)
        dq.push_back(people[i]);


    while (dq.size() != 0)
    {
        if (dq.size() == 1)
        {
            dq.pop_front();
            answer++;
        }
        else
        {
            if (dq[dq.size() - 1] + dq[0] > limit)
            {
                dq.pop_back();
                answer++;
            }
            else
            {
                dq.pop_front();
                dq.pop_back();
                answer++;
            }
        }
    }

    return answer;
}