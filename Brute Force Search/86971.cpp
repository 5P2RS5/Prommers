#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int arr[102][102];
bool visited[102];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cnt = 0;
int len = 0;
vector<int> temp;
void dfs(int y)
{
    len++;
    temp.push_back(y);
    visited[y] = true;
    for(int i = 1; i <= cnt; i++)
    {
        if(visited[i])
            continue;
        if(arr[y][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999999;
    
    cnt = n;
    for(int i = 0; i < wires.size(); i++)
    {
        arr[wires[i][0]][wires[i][1]] = 1;
        arr[wires[i][1]][wires[i][0]] = 1;
    }
    for(int i = 0; i <= n ; i++)
    {
        for(int j = 0; j <= n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < wires.size(); i++)
    {
        vector<int> v;
        memset(visited, false, sizeof(visited));
        arr[wires[i][0]][wires[i][1]] = 0;
        arr[wires[i][1]][wires[i][0]] = 0;
        for(int j = 1; j <= n; j++)
        {
            if(visited[j]) continue;
            for(int k = 1; k <= n; k++)
            {
                if(visited[k]) continue;
                if(arr[j][k] == 1)
                {
                    len = 0;
                    dfs(j);
                    v.push_back(len);
                }
                if(len = 0)
                    v.push_back(0);
            }
            len = 0;
        }
        if(v.size() == 1)
            v.push_back(1);
        if(v.size() >= 2)
        {
            int t = abs(v[0] - v[1]);
            answer = t < answer ? t : answer;
        }
        arr[wires[i][0]][wires[i][1]] = 1;
        arr[wires[i][1]][wires[i][0]] = 1;
    }
    
    return answer;
}