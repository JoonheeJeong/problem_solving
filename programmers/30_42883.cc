#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size();
    int beg = 0;
    int rem = k;
    int end = beg + rem + 1;
    while (end <= len && rem != 0) {
        char max = number[beg];
        int max_i = beg;
        for (int i = beg + 1; i < end; ++i) {
            if (max < number[i]) {
                max = number[i];
                max_i = i;
            }
        }
        answer += number[max_i];
        rem -= max_i - beg;
        beg = max_i + 1;
        end = beg + rem + 1;
    }
    if (rem == 0 && beg < len) 
    	answer += number.substr(beg);
    return answer;
}
