#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

set<int> s;

bool check(string str1, string str2)
{
    if(str1.length() != str2.length()) return false;
    
    for(int i=0; i<str1.length(); i++)
    {
        if(str2[i] == '*') continue;
        else if(str1[i] != str2[i]) return false;
    }
    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, int index, int result)
{
    if(index >= banned_id.size())
    {
        s.insert(result);
        return;
    }
    
    for(int i=0; i<user_id.size(); i++)
    {
        if(!(result & (1 << i)) && check(user_id[i], banned_id[index]))
            dfs(user_id, banned_id, index+1, result | (1 << i));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}