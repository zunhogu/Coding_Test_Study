#include <iostream>

bool isInside(std::pair<int, int> point, std::pair<int, int> origin, int radius)
{
    int val =(point.first - origin.first) * (point.first - origin.first) + (point.second - origin.second) * (point.second - origin.second);
    if(val < radius * radius)
        return true;
    else 
        return false;
}

int main()
{
    int size;
    std::cin >> size;

    for(int i=0; i<size; i++)
    {
        int n, cnt = 0;
        std::pair<int, int> start, end;

        std::cin >> start.first >> start.second >> end.first >> end.second;
        std::cin >> n;

        for(int j=0; j<n; j++)
        {
            std::pair<int, int> crd;
            int radius;
            std::cin >> crd.first >> crd.second >> radius;

            if(isInside(start, crd, radius) && !isInside(end, crd, radius))
                cnt++;
            if(isInside(end, crd, radius) && !isInside(start, crd, radius))
                cnt++;
        }
        std::cout << cnt << '\n';
    }

    return 0;
}