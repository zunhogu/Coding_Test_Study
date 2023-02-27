#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<pair<string, int>> list, string str)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].first == str)
            return i;
    }

    return list.end() - list.begin();
}

float GetSimilarlity(vector<pair<string, int>> A, vector<pair<string, int>> B)
{
    int a = 0;
    int b = 0;
    vector<pair<string, int>> new_A;
    vector<pair<string, int>> new_B;

    for (int i = A.size() - 1; i >= 0; i--)
    {
        int index = find(B, A[i].first);
        if (index == B.end() - B.begin())
            new_B.push_back(A[i]);
        else
        {
            new_A.push_back(make_pair(A[i].first, min(A[i].second, B[index].second)));
            new_B.push_back(make_pair(A[i].first, max(A[i].second, B[index].second)));
        }
    }

    for (int i = 0; i < B.size(); i++)
    {
        if (find(new_B, B[i].first) == new_B.end() - new_B.begin())
            new_B.push_back(B[i]);
    }

    for (int i = 0; i < new_A.size(); i++)
        a += new_A[i].second;
    for (int i = 0; i < new_B.size(); i++)
        b += new_B[i].second;

    return a == 0 && b == 0 ? 1 : (float)a / b;
}

int solution(string str1, string str2) {
    int answer = 0;

    vector<pair<string, int>> A;
    vector<pair<string, int>> B;

    for (int i = 0; i < str1.size(); i++)
    {
        string token = str1.substr(i, 2);
        if (isalpha(token[0]) && isalpha(token[1]))
        {
            transform(token.begin(), token.end(), token.begin(), ::toupper);

            int index = find(A, token);
            if (index == A.end() - A.begin())
                A.push_back(make_pair(token, 1));
            else
                A[index].second += 1;
        }
    }
    for (int i = 0; i < str2.size(); i++)
    {
        string token = str2.substr(i, 2);
        if (isalpha(token[0]) && isalpha(token[1]))
        {
            transform(token.begin(), token.end(), token.begin(), ::toupper);
            int index = find(B, token);
            if (index == B.end() - B.begin())
                B.push_back(make_pair(token, 1));
            else
                B[index].second += 1;
        }
    }

    answer = GetSimilarlity(A, B) * 65536;

    return answer;
}