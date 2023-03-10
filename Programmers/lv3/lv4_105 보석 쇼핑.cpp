#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

bool isFull(map<string, int>& m)
{
    for(map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        if(iter->second == 0) return false;
    return true;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int front = 0, back = gems.size();
    map<string, int> counts;
    queue<string> q;
    
    for(int i=0; i<gems.size(); i++)
    {
        map<string, int>::iterator iter = counts.find(gems[i]);
        if(iter == counts.end())
            counts.insert(make_pair(gems[i], 0));
    }
    
    for(int i=gems.size()-1; i>=0; i--)
    {
        map<string, int>::iterator iter = counts.find(gems[i]);
        if(iter->second == 0)
        {
            q.push(gems[i]);
            iter->second++;
        }
        else
        {
            while(q.front() == gems[i])
            {
                q.pop();
                iter->second--;
            }
            if(!isFull(counts))
            {
                q.push(gems[i]);
                iter->second++;
            }
        }
    }
    
    while(!q.empty())
    {
        cout << q.front()<< " ";
        q.pop();
    }
    
    answer.push_back(front+1);
    answer.push_back(back);
    
    return answer;
}