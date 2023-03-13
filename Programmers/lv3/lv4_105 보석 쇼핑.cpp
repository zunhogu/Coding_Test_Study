#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    set<string> s;
    int kind = 0;
    
    for(string str : gems)
        s.insert(str);
    kind = s.size();
    
    map<string, int> m;
    int start=0, end=0;
    int min_diff = 100001;
    
    while(1)
    {
		if (m.size() >= kind) 
        {
			m[gems[start]]--; 
			if (m[gems[start]] == 0)
				m.erase(gems[start]);
			start++;
		}
        else if(end == gems.size()) break;
        else
        {
            m[gems[end]]++;
            end++;
        }
        
        if (m.size() == kind)
        {
			if (abs(end - start) < min_diff) 
            {
				min_diff = abs(end - start);
				answer[0] = start + 1;
                answer[1] = end;
			}
		}
    }
    
    return answer;
}