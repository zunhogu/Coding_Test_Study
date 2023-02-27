#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define SWAP(x, y, tmp) {tmp = x; x = y; y = tmp;}

bool compare(pair<string, int> p1, pair<string, int> p2) { return p1.second > p2.second; }

int find(vector<pair<string, int>>& counts, string str)
{
    for(int i=0; i<counts.size(); i++)
    {
        if(counts[i].first == str)
            return i;
    }
    return -1;
}

void sort(vector<string>& genres, vector<int>& plays, vector<int>& indexs)
{
	int i, j, tmp, least;
    string tmp2;
	for (i = 0; i < plays.size()-1; i++)
	{
		least = i;
		for (j = i + 1; j < plays.size(); j++)
		{
			if (plays[j] > plays[least])
				least = j;
		}
        SWAP(plays[i], plays[least], tmp);
        SWAP(indexs[i], indexs[least], tmp);
		SWAP(genres[i], genres[least], tmp2);
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<pair<string, int>> counts;
    vector<int> indexs;
    
    for(int i=0; i<plays.size(); i++)
        indexs.push_back(i);
    
    sort(genres, plays, indexs);

    for(int i=0; i<genres.size(); i++)
    {
        int index = find(counts, genres[i]);
        if(index != -1)
            counts[index].second += plays[i];
        else
            counts.push_back(make_pair(genres[i], plays[i]));
    }

    sort(counts.begin(), counts.end(), compare);  
    for(int i=0; i<counts.size(); i++)
    {
        int cnt = 0;
        for(int j=0; j<genres.size(); j++)
        {
            if(cnt >= 2) break;
            else if(counts[i].first == genres[j])
            {
                answer.push_back(indexs[j]);
                cnt++;
            }
        }
    }
    
    return answer;
}