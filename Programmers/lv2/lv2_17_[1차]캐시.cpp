#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;

    for (int i = 0; i < cities.size(); i++)
    {
        string input = cities[i];
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        int index = find(cache.begin(), cache.end(), input) - cache.begin();
        if (index != cache.end() - cache.begin()) // cache hit
        {
            string s = cache[index];
            cache.erase(cache.begin() + index);
            cache.push_back(s);
            answer += 1;
        }
        else // cahce miss
        {
            answer += 5;

            if (cacheSize != 0)
            {
                // cahce fault -> swapping
                if (cache.size() >= cacheSize)
                    cache.pop_front();
                cache.push_back(input);
            }
        }
    }

    return answer;
}