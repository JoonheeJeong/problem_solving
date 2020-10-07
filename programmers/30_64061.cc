#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> v;
    for (auto &i : moves) {
        int k = 0;
        for (auto &row : board) {
            if (row[i-1] != 0) {
                k = row[i-1];
                row[i-1] = 0;
                break;
            }
        }
        if (k == 0) continue;
        if (v.empty() || v.back() != k) {
            v.push_back(k);
        } else {
            v.pop_back();
            answer += 2;
        }
    }
    return answer;
}
