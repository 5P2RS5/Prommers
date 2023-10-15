// 타겟넘버
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int sum = 0;

void dfs(int idx, vector<int> v, int target)
{
    if(idx == v.size())
    {
        if(sum == target)
        {
            answer++;
        }
        return;
    }
    sum += v[idx];
    dfs(idx + 1, v, target);
    sum -= 2 * v[idx];
    dfs(idx + 1, v, target);
    sum += v[idx];
}


int solution(vector<int> numbers, int target) {
    dfs(0, numbers, target);
    return answer;
}