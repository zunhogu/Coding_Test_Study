#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {

    vector<int> result;
    for (int length = 1; length <= elements.size(); length++)
    {
        for (int start = 0; start < elements.size(); start++)
        {
            int sum = 0;
            int index = start;
            for (int cnt = 0; cnt < length; cnt++)
                sum += elements[(index + cnt) % elements.size()];
            result.push_back(sum);
        }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result.size();
}