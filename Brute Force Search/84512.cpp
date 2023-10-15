#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> a = {'A', 'E', 'I', 'O', 'U'};
bool visited[5];

int answer = 0;
string temp = "";
bool isFind = false;

void con(int pos, string word)
{
     cout << temp << endl;
    if(isFind)
        return;
    if(temp == word)
    {
        isFind = true;
        return;
    }
    if(temp.size() == 5)
    {
        answer++;
        return;
    }
    answer++;
    
    for(int j = 0; j < 5; j++)
    {
        visited[pos] = true;
        temp += a[j];
        con(j, word);
        temp.pop_back();
        visited[pos] = false;
    }
    
}

int solution(string word) {
    con(0, word);
    return answer;
}