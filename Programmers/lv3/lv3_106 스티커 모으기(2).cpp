#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int size= sticker.size();
    if(size==1) return sticker[0];
    
    vector<int> dp1(size, 0), dp2(size, 0);
    
    dp1[0] = sticker[0];
    dp1[1] = dp1[0];
    for(int i=2; i<size-1; i++)
        dp1[i] = max(dp1[(i-2)%size] + sticker[i], dp1[(i-1)%size]);
    
    for(int i=1; i<size; i++)
        dp2[i] = max(dp2[(i-2)%size] + sticker[i], dp2[(i-1)%size]);
    
    return max(dp1[size-2], dp2[size-1]);
}