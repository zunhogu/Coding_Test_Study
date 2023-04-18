#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        int zero_cnt = 0;
        int max_zero_cnt = 0;
        vector<int> temp = stones;
        for(int i=0; i<temp.size(); i++)
        {
            temp[i] = temp[i] - mid + 1 <= 0 ? 0 : temp[i] - mid + 1;
            if(temp[i] == 0) 
                zero_cnt++;
            else
            {
                max_zero_cnt = max(max_zero_cnt, zero_cnt);
                zero_cnt = 0;
            }
        }
        max_zero_cnt = max(max_zero_cnt, zero_cnt);
        
        if(max_zero_cnt >= k)
            right = mid-1;
        else
        {
            answer = mid;
            left = mid+1;
        }
    }
    
    return answer;
}