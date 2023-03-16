#include <iostream>
#include <vector>
#include <iostream>          
using namespace std;

int max = 0;

int solution(vector<int> sticker)
{
    int answer =0;
    
    int size = sticker.size();
    vector<int> dp(size, 0);
    
    for(int i=0; i<size; i++)
    {
        dp[i] += sticker[i] - sticker[(i-1)%size];
        dp[i] += sticker[i] - sticker[(i+1)%size];
    }
    for(int i=0; i<dp.size(); i++)
        cout << dp[i] << " ";
    cout << endl;
    return answer;
}