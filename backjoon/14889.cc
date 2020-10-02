#include <iostream>

int n;
int abt[20][20];

// 0 포함 팀의 false set == 미포함 팀의 true set (연산 중복 방지)
bool chk[20] { true, }; 

int solve(int pos, int rem)
{
    // chk 확인해서 true set과 false set의 abt합의 차를 구하기
    if (rem == 0) {
        int true_sum = 0;
        int false_sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (chk[i] != chk[j]) continue;
                if (chk[i]) true_sum += abt[i][j];
                else        false_sum += abt[i][j];
            }
        }
        int diff = true_sum - false_sum;
        if (diff < 0) 
            diff = -diff;
        return diff; 
    }

    // 남은 사람 고려해서 end 설정
    int end = n-rem+1;
    int min = INT32_MAX;
    for (int i = pos; i < end; ++i) {
       chk[i] = true;
       int temp = solve(i+1, rem-1);
       if (temp < min)
           min = temp;
       chk[i] = false;
    } 
    return min;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> abt[i][j];

    std::cout << solve(1, n/2 - 1) << std::endl;
    return 0;
}
