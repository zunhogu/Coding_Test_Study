#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int origin = 30001;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int answer = 1;
    int temp = routes[0][1];
    
    for(int i=0; i<routes.size(); i++)
    {
        if(temp >= routes[i][0])
            temp = min(routes[i][1], temp);
        else
        {
            answer++;
            temp = routes[i][1];
        }
    }
    return answer;
}