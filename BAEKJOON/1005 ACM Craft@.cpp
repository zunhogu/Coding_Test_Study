#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int N, K, W,pre[1000] = {0};
        std::cin >> N >> K;
        std::vector<int> suc[1000];
        std::vector<int> times(1000, 0);    // 건물 건설 시간
        std::vector<int> wait(1000, 0);     // 건물들이 지어질때까지 기다린 시간
        std::queue<int> q;      // 건설 대기 건물, pop 되는 순간 건물이 건설됨

        for(int i=0; i<N; i++)
            std::cin >> times[i];
        for(int i=0; i<K; i++)
        {
            int x, y;
            std::cin >> x >> y;
            suc[x-1].push_back(y-1);
            pre[y-1]++;
        }
        std::cin >> W;

        // 선행자가 하나도 없는 노드를 먼저 큐에 push
        for(int i=0; i<N; i++)
            if(!pre[i]) q.push(i);

        // W번 건물이 선행자가 0이 될 대까지 반복
        while(pre[W-1] > 0)
        {
            // 건설 시작
            int n = q.front();
            q.pop();
            // n 번째 건물을 선행자로 가지는 후행자 건물의 최소시간을 갱신
            for(int next : suc[n])
            {
                wait[next] = std::max(wait[next], wait[n] + times[n]);
                if(--pre[next] == 0) q.push(next);
            }
        }
        std::cout<< wait[W-1] + times[W-1] << std::endl;
    }
}