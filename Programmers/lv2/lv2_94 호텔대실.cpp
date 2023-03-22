#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool book(int start, int end, int book_start, int book_end)
{
    bool result = true;
    
    if(start < book_start && end > book_start && end < book_end)
        result = false;
    else if(start > book_start && start < book_end && end > book_end)
        result = false;
    else if(start > book_start && end < book_end)
        result = false;
    else if(start < book_start && start > book_end)
        result = false;
    
    return result;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> rooms;
    
    for(int i=0; i<book_time.size(); i++)
    {
        int start = stoi(book_time[i][0].substr(0,2) + book_time[i][0].substr(3,5));
        int end = stoi(book_time[i][1].substr(0,2) + book_time[i][1].substr(3,5)) + 10;
        
        for(int j=0; j<rooms.size(); j++)
        {
            bool success = false;
            for(int k=0; k<rooms[j].size(); k++)
            {
                cout << start << " ~ " << end << " -> " << rooms[j][k].first << " ~ " << rooms[j][k].second;
                if(book(start, end, rooms[j][k].first, rooms[j][k].second))
                {
                    cout << " 가능 "  << endl;
                    break;
                    rooms[j].push_back(make_pair(start, end));
                    success = true;
                }
                cout << " 불가능 " << endl;
            }
        }
            
        if(!success)
        {
            vector<pair<int, int>> new_room;
            new_room.push_back(make_pair(start, end));
            rooms.push_back(new_room);
        }
    }
    
    return answer;
}