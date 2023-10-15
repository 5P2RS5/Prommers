#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 좌표를 두배로 해서 테두리 배열 만든 후 2로 나누면 결과가 나온다.

int maxX, maxY;
int arr[51][51];
bool visited[51][51];
int cost[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int cY, int cX, int iY, int iX)
{        
    queue<pair<int, int>> q;
    q.push({cY, cX});
    cost[cY][cX] = 0;
    visited[cY][cX] = true;
    while(!q.empty())
    {
        int py = q.front().first;
        int px = q.front().second;
        if(py == (iY  * 2) && px == (iX * 2))
            return;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if(nx < 0 || nx >= maxX || ny < 0 || ny >= maxY)
                continue;
            if(visited[ny][nx])
                continue;
            if(arr[ny][nx] == 1)
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
                cost[ny][nx] = cost[py][px] + 1;
            }
            
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(int i = 0; i < rectangle.size(); i++)
    {
        int fx = rectangle[i][0] * 2;
        int fy = rectangle[i][1] * 2;
        int lx = rectangle[i][2] * 2;
        int ly = rectangle[i][3] * 2;
        
        if(lx > maxX)
            maxX = lx;
        if(ly > maxY)
            maxY = ly;

        for(int j = fy; j <= ly; j++)
        {
            for(int k = fx; k <= lx; k++)
            {
                if(arr[j][k] == 0)
                {
                    if(j == ly || k == lx || j == fy || k == fx)
                    { 
                        arr[j][k] = 1;
                    }
                    else
                    {
                        if(arr[j][k] == 1)
                            arr[j][k] = 7;
                        arr[j][k] = 7;
                    }
                }
                else
                {
                    if(arr[j][k] == 1)
                    {
                        if(j == ly || k == lx || j == fy || k == fx)
                        { 
                            arr[j][k] = 1;
                        }
                        else
                            arr[j][k] = 7;
                    }
                }
            }
        }
    }
    // for(int i = 0 ; i <= maxY; i++)
    // {
    //     for(int j = 0; j <= maxX; j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    bfs(characterY * 2, characterX * 2, itemY * 2, itemX * 2);
    return cost[itemY * 2][itemX * 2] / 2;
}

int main()
{
    //vector<vector<int>> rectangle = {{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}};
    //int characterX = 1; int characterY = 3; int itemX = 7; int itemY = 8;

    vector<vector<int>> rectangle = {{1,1,8,4},{2,2,4,9},{3,6,9,8},{6,3,7,7}};
    int characterX = 9; int characterY = 7; int itemX = 6; int itemY = 1;

    //vector<vector<int>> rectangle = {{1, 1, 5, 7}};
    //int characterX = 1; int characterY = 1; int itemX = 4; int itemY = 7;

    //vector<vector<int>> rectangle = {{2, 1, 7, 5}, {6, 4, 10, 10}};
    //int characterX = 3; int characterY = 1; int itemX = 7; int itemY = 10;
    cout << solution(rectangle, characterX, characterY, itemX, itemY)<< endl;

    for(int i = 0 ; i <= maxY; i++)
    {
        for(int j = 0; j <= maxX; j++)
            cout << cost[i][j] << " ";
        cout << endl;
    }
}
