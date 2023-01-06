#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(string s, int n) {

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            int c;
            int num = s[i] + n;
            if (isupper(s[i]))
                c = num > 90 ? num % 90 + 64 : num;
            else
                c = num > 122 ? num % 122 + 96 : num;

            s[i] = c;
        }

    }
    return s;
}