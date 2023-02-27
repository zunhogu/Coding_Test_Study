#include <string>
#include <vector>
using namespace std;

vector<bool> networks;

void recursive(int i, vector<vector<int>>& computers, int& answer)
{
    if(!networks[i]) 
    {
        answer++;
        networks[i] = true;
    }
    for(int j=0; j<computers[i].size(); j++)
    {
        if(i==j) continue;
        else if(!networks[j] && computers[i][j]) 
        {
            networks[j] = true;
            recursive(j, computers, answer);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++)
        networks.push_back(false);

    for(int i=0; i<n; i++)
        if(!networks[i]) recursive(i, computers, answer);

    return answer;
}