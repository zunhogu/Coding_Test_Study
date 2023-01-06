#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isCorrect(string p)
{
    bool result = true;
    vector<char> s;

    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
            s.push_back(p[i]);
        else if (p[i] == ')')
        {
            if (s.empty())
            {
                result = false;
                break;
            }
            else
                s.pop_back();
        }
    }

    return result;
}

string Separate(string p)
{
    string answer = "";
    string u, v;

    if (p.length() == 0)
        return answer;

    int lparenCnt = 0;
    int rparenCnt = 0;

    int index = 0;
    for (; index < p.length(); index++)
    {
        if (p[index] == '(') lparenCnt++;
        else if (p[index] == ')') rparenCnt++;

        if (lparenCnt == rparenCnt)
            break;
    }

    u = p.substr(0, index + 1);
    v = p.substr(index + 1, p.length() - 1);

    if (isCorrect(u))
    {
        answer += u;
        answer += Separate(v);
    }
    else
    {
        string temp = "(" + Separate(v) + ")";

        string temp2 = u.substr(1, u.length() - 2);
        for (int i = 0; i < temp2.length(); i++)
        {
            if (temp2[i] == '(') temp2[i] = ')';
            else if (temp2[i] == ')') temp2[i] = '(';
        }
        temp += temp2;
        answer += temp;
    }

    return answer;
}



string solution(string p) {

    if (p.length() == 0)
        return "";
    else if (isCorrect(p))
        return p;
    else
        return Separate(p);
}