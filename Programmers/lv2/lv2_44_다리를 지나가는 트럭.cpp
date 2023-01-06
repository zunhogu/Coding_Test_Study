#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;

    vector<int> complete;
    vector<pair<int, int>> going;

    int index = 0;
    int remainWeigth = weight;
    while (truck_weights.size() != complete.size())
    {
        answer++;
        if (remainWeigth >= truck_weights[index])
        {
            if (bridge_length >= going.size() && index < truck_weights.size())
            {
                going.push_back(make_pair(truck_weights[index], 1));
                remainWeigth -= truck_weights[index];
                index++;
            }
        }

        if (going.size() > 0)
        {
            for (int i = going.size() - 1; i >= 0; i--)
            {
                if (going[i].second == bridge_length)
                {
                    complete.push_back(going[i].first);
                    remainWeigth += going[i].first;
                    going.erase(going.begin() + i);
                }
                else
                    going[i].second++;
            }
        }
    }

    return answer;
}