#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            answer = false;
    }

    if (!(s.length() == 4 || s.length() == 6))
        answer = false;

    return answer;
}