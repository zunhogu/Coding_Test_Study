#include <string>
#include <vector>
using namespace std;

void dfs(string alphas, string str, string word, int& cnt, int& answer)
{
    if (str == word)
        answer = cnt;
    if (str.length() == 5)
        return;

    for (int i = 0; i < alphas.length(); i++)
    {
        cnt++;
        dfs(alphas, str + alphas[i], word, cnt, answer);
    }
}

int solution(string word)
{
    int answer = 0;
    int cnt = 0;
    string str = "";
    string alphas = "AEIOU";

    dfs(alphas, str, word, cnt, answer);

    return answer;
}