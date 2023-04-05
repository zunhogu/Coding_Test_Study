#include <iostream>

int dp[31][31] = { 0 };
int N, M;

int main()
{
    for(int i=1; i<31; i++)
        dp[1][i]=i;

    for(int i=2; i<31; i++)
    {
        for(int j=i; j<31; j++)
        {
            for(int k=j-1; k>=1; k--)
                dp[i][j] += dp[i-1][k];
        }
    }

    int T;
    std::cin>>T;
    while(T--)
    {
        int result = 0;
        std::cin>>N>>M;
        std::cout<<dp[N][M]<<"\n";
    }
}   