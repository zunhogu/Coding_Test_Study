#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N;
float result;
std::vector<std::pair<int, int>> start;
std::vector<std::pair<int, int>> end;
bool visited[20] = { 0 };
std::pair<int, int> cur_vec;

std::pair<int, int> add_vec(int x1, int y1, int x2, int y2)
{ 
    return std::make_pair(x2 - x1 + cur_vec.first, y2 - y1 + cur_vec.second); 
}

void dfs(int index, int cnt)
{
    if(cnt >= N/2)
    {
        cur_vec = add_vec(start[index].first, start[index].second, end[cnt].first, end[cnt].second);
        result = std::min(result, sqrt(cur_vec.first * cur_vec.first + cur_vec.second * cur_vec.second));
        return;
    }

    for(int i=0; i<N/2; i++)
    {   
        // if(!visited[i])
        //     std::cout<< start << "-"<< i << std::endl;
        visited[i] = true;
        dfs(index+1, cnt+1);
        visited[i] = false;
    }
}

int main()
{
    int T;
    std::cin >> T;
    
    while(T--)
    {
        cur_vec = std::make_pair(0, 0);
        result = 100001.f;
        std::cin >> N;
        std::vector<std::pair<int, int>> crds;

        std::vector<bool> flags(N, false);
        for(int i=0; i<N/2; i++)
            flags[i] = true;

        for(int i=0; i<N; i++)
        {
            int x, y;
            std::cin >> x >> y;
            crds.push_back(std::make_pair(x, y));
        }

        // seperate start and end coordinates
        do
        {
            for(int i=0; i<crds.size(); i++)
            {
                if(flags[i]) start.push_back(crds[i]);
                else end.push_back(crds[i]);
            }

            dfs(0, 0);
        } while (std::prev_permutation(flags.begin(), flags.end()));

        
        std::cout << min << std::endl;
    }
    return min;
}