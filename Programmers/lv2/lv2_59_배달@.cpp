#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(int N, vector<vector<int>>& map, int K)
{
    int count = 0;

    priority_queue<pair<int, int>> pq; // dist, index
    vector<int> dist(N + 1, 1e8);

    pq.push({ 0, 1 });
    dist[1] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (int i = 1; i <= N; i++) {
            if (i == node || map[node][i] == 1e8) continue;

            if (dist[i] > d + map[node][i])
            {
                dist[i] = d + map[node][i];
                pq.push({ dist[i], i });
            }
        }
    }

    for (int i = 1; i <= N; ++i)
        if (dist[i] <= K) count++;

    return count;
}

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<int>> map(N + 1, vector<int>(N + 1, 1e8));

    for (int i = 0; i < road.size(); i++)
    {
        map[road[i][0]][road[i][1]] = min(road[i][2], map[road[i][0]][road[i][1]]);
        map[road[i][1]][road[i][0]] = min(road[i][2], map[road[i][1]][road[i][0]]);
    }

    for (int i = 1; i <= N; i++)
        map[i][i] = 0;

    return shortestPath(N, map, K);
}