#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int offset = 2 * w +1;
    int dist = 0;
    
    if(stations[0] - w > 0) 
    {
        dist = (stations[0] - w) - 1;
        answer += dist / offset;
        if(dist % offset != 0) answer++;
    }
    
    for(int i=0; i<stations.size(); i++)
    {
        if(i+1 < stations.size() && stations[i] + w + 1 < stations[i+1] - w)
        {
            dist = ((stations[i+1] - w) - (stations[i] + w + 1));
            answer += dist / offset;
            if(dist % offset != 0) answer++;
        }
    }
    
    if(stations[stations.size()-1] + w <=n) 
    {
        dist = n - (stations[stations.size()-1] + w);
        answer += dist / offset;
        if(dist % offset != 0) answer++;
    }
    
    return answer;
}