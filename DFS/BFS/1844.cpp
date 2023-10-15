#include<vector>
#include<queue>
#include<vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[102][102] = {false, };
int cost[102][102];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int h = maps.size();
    int w = maps[0].size();
    queue<pair<int,int>> q;
    q.push({0, 0});
    cost[0][0] = 1;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(visited[ny][nx] || maps[ny][nx] == 0)
                continue;
            cost[ny][nx] = cost[y][x] + 1;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    if(cost[h - 1][w - 1] == 0)
        answer = -1;
    else
        answer =  cost[h - 1][w - 1] ;
        
    return answer;
}