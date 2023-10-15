// 네트워크

#include <string>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[201][201];

void dfs(int y, int n, vector<vector<int>> c)
{
    //visited[y][x] = true;
    for(int i = 0; i < n; i++)
    {
        if(!visited[y][i] && c[y][i] != 0)
        {
            visited[y][i] = true;
            dfs(i, n, c);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j] && computers[i][j] != 0)
            {
                // 방문한, 연결된 노드들 전부 방문 처리
                visited[i][i] = true;
                visited[i][j] = true;
                visited[j][i] = true;
                dfs(j, n, computers);
                answer++;
            }
        }
    }

    // 단독 노드 네트워크 개수 더하기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(computers[i][j] == 1 && !visited[i][j])
                answer++;
        }
    }
    return answer;
}