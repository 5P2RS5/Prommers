#include <string>
#include <vector>

using namespace std;

vector<int> result;
const int MAX = 10000001;
int arr[MAX];
int answer = 0;
bool visited[7];
string temp;

// 소수 미리 구하기
void eratos()
{
    for(int i = 0; i < MAX; i++)
    {
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2; i < MAX; i++)
    {
        if(arr[i] = 0)
            continue;
        
        for(int j = i + i; j < MAX; j += i)
        {
            arr[j] = 0;
        }
    }
}

void dfs(int size, string number)
{
    if(temp.size() == size)
    {
        if(arr[stoi(temp)] == 1)
        {
            arr[stoi(temp)] == 2;
            answer++;
        }
        return;
    }
    for(int i = 0; i < number.size(); i++)
    {
        if(visited[i] == true) continue;
        visited[i] = true;
        temp += number[i];
        dfs(size, number);
        temp.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    eratos();
    for(int i = 1; i <= numbers.size(); i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i, numbers);
    }
    return answer;
}