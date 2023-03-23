#include <string>
#include <vector>
using namespace std;

void book(int start, int end, vector<vector<bool>>& rooms)
{
    for(int i=0; i<rooms.size(); i++)
    {
        bool enable = true;
        for(int j=start+1; j<=end; j++)
        {
            if(rooms[i][j])
            {
                enable = false;
                break;
            }
        }
        if(enable)
        {
            for(int j=start; j<=end; j++)
                rooms[i][j] = true;
            return;
        }
    }
    
    vector<bool> tmp(1499, false);
    for(int i=start; i<=end; i++)
        tmp[i] = true;
    rooms.push_back(tmp);
    return;
}

int solution(vector<vector<string>> book_time) {
    vector<vector<bool>> rooms;
    
    for(int i=0; i<book_time.size(); i++)
    {
        int start = stoi(book_time[i][0].substr(0,2))*60 + stoi(book_time[i][0].substr(3,5))/60 + stoi(book_time[i][0].substr(3,5))%60;
        int end = stoi(book_time[i][1].substr(0,2))*60 + (stoi(book_time[i][1].substr(3,5))+10)/60*60 + (stoi(book_time[i][1].substr(3,5)) + 10)%60;
        
        book(start, end, rooms);
    }
    
    return rooms.size();
}