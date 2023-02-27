#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(int i : works)
        pq.push(i);

    while(n!=0)
    {
        if(pq.empty()) break;
        int max = pq.top();
        pq.pop();
        
        max--;
        if(max > 0) pq.push(max);
        n--;
    }
 
    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}