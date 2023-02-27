#include <string>
#include <stack>
using namespace std;

bool isCorrect(string s)
{
    stack<char> parens;
    stack<char> expect;

    for (int i = 0; i < s.length(); i++)
        parens.push(s[i]);

    while (!parens.empty())
    {
        char c = parens.top();
        parens.pop();

        if (c == '(' || c == '{' || c == '[')
        {
            if (expect.empty())
                return false;
            if (c == expect.top())
                expect.pop();
            else
                return false;
        }
        else
        {
            switch (c)
            {
            case ')':
                expect.push('(');
                break;
            case '}':
                expect.push('{');
                break;
            case ']':
                expect.push('[');
                break;
            }
        }
    }

    if (expect.empty())
        return true;
    else
        return false;
}

int solution(string s) {

    int answer = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (isCorrect(s))
            answer++;
        s += s[0];
        s = s.substr(1, s.length());
    }

    return answer;
}