#include <string>
#include <vector>
#include <cmath>

using namespace std;

// yellow 넓이 = (answer[0] - 2) * (answer[1] - 2)

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    vector<int> answer;
    for(int i = 1; i <= sqrt(total); i++)
    {
        int a;
        if(total % i == 0)
        {
            a = total / i;
        }
        if((i - 2) * (a - 2) == yellow)
        {
            answer.push_back(a);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}