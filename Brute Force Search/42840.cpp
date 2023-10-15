#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a = {1,2,3,4,5};
vector<int> b = {2,1,2,3,2,4,2,5};
vector<int> c = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ac = 0;
    int bc = 0;
    int cc = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(a[i % a.size()] == answers[i])
            ac++;
        if(b[i % b.size()] == answers[i])
            bc++;
        if(c[i % c.size()] == answers[i])
            cc++;
    }
    int top = max(max(ac, bc), cc);
    if(top == ac)
            answer.push_back(1);
        if(top == bc)
            answer.push_back(2);
        if(top == cc)
            answer.push_back(3);
    return answer;
}