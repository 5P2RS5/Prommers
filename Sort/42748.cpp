#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++)
    {
        vector<int> temp;
        int s = commands[i][0] - 1;
        int l = commands[i][1] - 1;
        int k = commands[i][2] - 1;
        
        for(int j = s; j <= l; j++)
        {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }
    
    return answer;
}