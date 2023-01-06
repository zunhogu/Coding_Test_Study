#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    bool flag = false;
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] == ' ')
            flag = true;
        else if (flag)
        {
            s[i] = toupper(s[i]);
            flag = false;
        }
    }

    return s;
}