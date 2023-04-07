#include <iostream>
#include <vector>

int main()
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int width, height, size, result = 0;
        std::cin>>width>>height>>size;
        std::vector<std::vector<int>> v(height, std::vector<int>(width, 0));
        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

        for(int i=0; i<size; i++)
        {
            int x, y;
            std::cin >> y >> x;
            v[x][y] = 1;
        }

        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].size(); j++)
            {
                if(v[i][j] == 1 && !visited[i][j])
                {
                    std::vector<std::pair<int, int>> st;
                    st.push_back({i, j});
                    while(!st.empty())
                    {
                        std::pair<int, int> cur = st.back();
                        st.pop_back();
                        visited[cur.first][cur.second] = true;

                        std::pair<int, int> next;
                        // 상
                        next.first = cur.first-1;
                        next.second = cur.second;
                        if(next.first >=0 && v[next.first][next.second] && !visited[next.first][next.second])
                            st.push_back(next);

                        // 하
                        next.first = cur.first+1;
                        next.second = cur.second;
                        if(next.first < height && v[next.first][next.second] && !visited[next.first][next.second])
                            st.push_back(next);

                        // 좌
                        next.first = cur.first;
                        next.second = cur.second-1;
                        if(next.second >= 0 && v[next.first][next.second] && !visited[next.first][next.second])
                            st.push_back(next);

                        // 우
                        next.first = cur.first;
                        next.second = cur.second+1;
                        if(next.second < width && v[next.first][next.second] && !visited[next.first][next.second])
                            st.push_back(next);
                    }
                    result++;
                }
            }
        }
        std::cout<<result<<"\n";
    }
}   