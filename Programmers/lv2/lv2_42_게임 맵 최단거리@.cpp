#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int posX;
    int posY;
    int cnt;
};

int solution(vector<vector<int>> maps)
{
    int answer;

    vector<vector<int>> mark(maps.size(), vector<int>(maps[0].size(), 0));

    queue<Node> que;

    Node startNode;
    startNode.posX = 0;
    startNode.posY = 0;
    startNode.cnt = 1;
    que.push(startNode);

    mark[0][0] = 1;

    bool found = false;
    Node currNode;
    while (!que.empty() && !found)
    {
        currNode = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextPosX = currNode.posY;
            int nextPosY = currNode.posX;

            if (i == 0) nextPosX += 1;
            else if (i == 1) nextPosX -= 1;
            else if (i == 2) nextPosY -= 1;
            else if (i == 3) nextPosY += 1;

            if (nextPosX > maps[0].size() - 1) continue;
            else if (nextPosX < 0) continue;
            if (nextPosY > maps.size() - 1) continue;
            else if (nextPosY < 0) continue;

            if (nextPosY == maps.size() - 1 && nextPosX == maps[0].size() - 1)
            {
                found = true;
                answer = currNode.cnt + 1;
            }
            else if (maps[nextPosY][nextPosX] && !mark[nextPosY][nextPosX])
            {
                Node nextNode;
                nextNode.posX = nextPosY;
                nextNode.posY = nextPosX;
                nextNode.cnt = currNode.cnt + 1;
                que.push(nextNode);

                mark[nextPosY][nextPosX] = 1;
            }
        }
    }

    return found ? answer : -1;
}