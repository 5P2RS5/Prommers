#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int cost[52];
bool visited[52];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    int cnt = 0;
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while(!q.empty())
    {   
        string temp = q.front().first;
        cnt = q.front().second;
        q.pop();
        for(int i = 0; i < words.size(); i++)
        {
            int a = 0;
            if(!visited[i])
            {
                for(int j = 0; j < words[i].size(); j++)
                {
                    if(temp[j] == words[i][j])
                    {
                        a++;
                    }
                }                                   
                if(a >= words[i].size() - 1)
                {              
                    if(target == words[i])
                    {
                        return cnt + 1;
                    }
                    cost[i] = cnt + 1;
                    q.push({words[i], cost[i]});
                    visited[i] = true;
                }
            }
        }
        cnt++;
    }
    
    return 0;
}