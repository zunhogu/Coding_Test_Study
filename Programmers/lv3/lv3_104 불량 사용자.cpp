#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

void makeMap(vector<string>& user_id, vector<string>& banned_id, vector<vector<string>>& m)
{
    for(int i=0; i<banned_id.size(); i++)
    {
        vector<string> temp;
        for(int j=0; j<user_id.size(); j++)
        {
            bool equal = true;
            if(banned_id[i].length() == user_id[j].length())
            {
                for(int n=0; n<banned_id[i].length(); n++)
                {
                    if(banned_id[i][n] == '*' || banned_id[i][n] == user_id[j][n]) continue;
                    else equal = false;
                }
            }
            else continue;
            if(equal) temp.push_back(user_id[j]);
        }
        m.push_back(temp);
    }
}

void dfs(int index, vector<string>& user_id, vector<vector<string>>& m, int result)
{
    if(index >= m.size()-1)
    {
        cout <<result << endl;
        return;
    }
    
    for(int i=index; i<m.size()-1; i++)
    {
        for(int j=0; j<m[i].size(); j++)
        {
            cout << m[i][j] << " ";
            int idx = find(user_id.begin(), user_id.end(), m[i][j]) - user_id.begin();
            
                
            result |= (1 << idx);
            dfs(index+1, user_id, m, result);   
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<vector<string>> m;
    set<int> counts;
    makeMap(user_id, banned_id, m);

    dfs(0, user_id, m, 0);
    
    return answer;
}