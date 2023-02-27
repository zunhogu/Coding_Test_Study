#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {

    string answer = "";

    int index = 0;
    int cnt = 0;
    while (s[index] != '\0')
    {
        char c = s[index];

        if (s[index] != ' ')
        {
            if (cnt % 2 == 0)
                c = toupper(c);
            else
                c = tolower(c);
            cnt++;
        }
        else
            cnt = 0;

        answer += c;
        index++;
    }
    return answer;
}