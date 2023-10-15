#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> result;
int k_value;
bool visited[10];
int answer = 0;
int cnt = 0;
int temp;

void dfs()
{
    if(result.size() == v.size())
    {
        temp = k_value;
        cnt = 0;
        for(int i = 0; i < result.size(); i++)
        {
           if(result[i].first <= temp)
            {
                temp -= result[i].second;
                cnt++;
            } 
        }
        if(cnt > answer)
            answer = cnt;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			result.push_back(v[i]);
			dfs();
			result.pop_back();
			visited[i] = false;
		}
	}
    
}

int solution(int k, vector<vector<int>> dungeons) {
    for(int i = 0; i < dungeons.size(); i++)
    {
        v.push_back({dungeons[i][0], dungeons[i][1]});
    }
    k_value = k;
    dfs();

    return answer;
}