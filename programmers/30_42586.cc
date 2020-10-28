#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    int beg = 0;
    int end = beg;
    while (beg < n) {
        int temp = 100 - progresses[beg];
        int q = temp / speeds[beg];
        int r = temp % speeds[beg];
        if (r != 0)
            q++;
        for (int i = beg; i < n; ++i)
            progresses[i] += q * speeds[i];
        for (int i = beg; i < n && progresses[i] >= 100; ++i)
            end++;
        answer.push_back(end-beg);
        beg = end;
    }
    
    return answer;
}
