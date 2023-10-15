#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    int max = citations[citations.size() - 1];
    while(true)
    {
        answer = 0;
        
        for(int i = 0; i < citations.size(); i++)
        {
            if(citations[i] >= max)
                answer++;
        }
        if(answer >= max)
        {
            int cnt = 0;
            for(int i = 0; i < citations.size(); i++)
            {
                if(citations[i] <= max)
                {
                    cnt++;
                }
            }
            if(cnt <= max)
            {
                answer = max;
                break;
            }
        }
        if(max == 0)
        {
            answer = 0;
            break;
        }
        max--;
    }
        
    return answer;
}