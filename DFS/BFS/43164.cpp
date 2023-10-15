#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<string>> ticket;
vector<string> answer;

bool isClear;
bool visited[10001];

void dfs(string str, int cnt)
{
    answer.push_back(str);
    
    if(cnt == ticket.size())
    {
        isClear = true;
    }
    
    for(int i = 0; i < ticket.size(); i++)
    {
        if(visited[i]) continue;
        if(ticket[i][0] == str)
        {
            visited[i] = true;
            dfs(ticket[i][1], cnt + 1);
            
             if (!isClear) {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    ticket = tickets;
    sort(ticket.begin(), ticket.end());
    dfs("ICN", 0);
    return answer;
}