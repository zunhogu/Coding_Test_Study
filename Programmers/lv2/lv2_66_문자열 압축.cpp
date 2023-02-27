#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.length() + 1;

    for (int i = 1; i <= s.length(); i++)
    {
        string comp = "";
        string prev = s.substr(0, i);
        int count = 0;

        for (int j = 0; j < s.length(); j += i)
        {
            if (prev != s.substr(j, i))
            {
                if (count > 1) comp += to_string(count);
                comp += prev;
                prev = s.substr(j, i);
                count = 1;
            }
            else count++;
        }
        if (count > 1) comp += to_string(count);
        comp += prev;

        int size = comp.length();
        answer = min(answer, size);
    }
    return answer;
}