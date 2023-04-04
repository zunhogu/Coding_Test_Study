#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

int N;
double result;
std::vector<std::pair<int, int>> points;
bool visited[20];

double vec_sum()
{
    std::pair<int, int> vec = {0, 0};
    for(int i = 0; i < N; i++){
        // 시작점인 경우
        if(visited[i]){
            vec.first -= points[i].first;
            vec.second -= points[i].second;
        }
        // 도착점인 경우
        else{
            vec.first += points[i].first;
            vec.second += points[i].second;
        }
    }
    
    return sqrt(pow(vec.first, 2) + pow(vec.second, 2));
}

void dfs(int index, int cnt)
{
    if(cnt == N/2)
    {
        result = std::min(result, vec_sum());
        return;
    }

    for(int i=index; i<N; i++)
    {
        visited[i] = true;
        dfs(i+1, cnt+1);
        visited[i] = false;
    }
}

int main()
{
    int T;
    std::cin >> T;
    
    while(T--)
    {
        memset(visited, 0, sizeof(visited));
        points.clear();
        result = 10e9+7;
        std::cin >> N;
        for(int i=0; i<N; i++)
        {
            int x, y;
            std::cin >> x >> y;
            points.push_back({x, y});
        }
        dfs(0, 0);
        printf("%.7lf\n", result);
    }
    return 0;
}