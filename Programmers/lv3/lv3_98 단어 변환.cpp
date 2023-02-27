#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int min_val = 1e9;

bool Available(string str1, string str2)
{
    int cnt = 0;
    for(int i=0; i<str1.size(); i++)
        if(str1[i] == str2[i]) cnt++;
    
    return str1.size() - cnt == 1? true : false;
}

void dfs(string curStr, string target, int count, vector<string>& words, vector<bool> visited)
{
    if(curStr == target)
    {
        min_val = min(min_val, count);
        return;
    }
    
    for(int i=0; i<words.size(); i++)
    {
        if(!visited[i] && Available(curStr, words[i]))
        {
            visited[i] = true;
            dfs(words[i], target, count+1, words, visited);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if(words.end() == find(words.begin(), words.end(), target)) return 0;
    else
    {
        vector<bool> visited(words.size(), false);
        dfs(begin, target, 0, words, visited);
        return min_val;
    }
}