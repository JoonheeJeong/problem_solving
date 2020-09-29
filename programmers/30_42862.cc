#include <string>
#include <vector>
#include <algorithm>

int solution(int n, std::vector<int> lost, std::vector<int> reserve) {
    std::vector<bool> chk(n+2, true);
    
    for (auto e : lost)
        chk[e] = false;
    
    std::sort(reserve.begin(), reserve.end());
    std::vector<int> v;
    for (auto e : reserve) {
        if (!chk[e])
            chk[e] = true;
        else
            v.push_back(e);
    }
    
    for (auto e : v) {
        if (!chk[e-1]) 
            chk[e-1] = true;
        else 
            chk[e+1] = true;
    }
    
    int answer = 0;
    for(auto e : chk) if(e) answer++;
    return answer-2;
}
