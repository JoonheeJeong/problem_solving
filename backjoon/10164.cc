#include<iostream>

int n, m, k;
int dp[15] {1, };

int solve()
{
    int a, b, aa, bb;
    a = k / m;
    b = k % m;
    if (b == 0) {
        if (a != 0) {
            a--;
            b = m-1;
        }
    } else {
        b--;
    }
    aa = n-1-a;
    bb = m-1-b;

    int less_i, diff_i, less_pair, big_j;
    if (aa < a) {
        less_i = aa;
        less_pair = bb; 
        diff_i = a - aa;
    } else {
        less_i = a;
        less_pair = b; 
        diff_i = aa - a;
    }
    big_j = (bb >= b) ? bb : b;

    int ans;
    for (int i = 0; i <= less_i; ++i)
        for (int j = 1; j <= big_j; ++j)
            dp[j] += dp[j-1];
    ans = dp[less_pair]; 
    for (int i = 0; i < diff_i; ++i)
        for (int j = 1; j <= big_j; ++j)
            dp[j] += dp[j-1];
    ans *= (less_pair != b) ? dp[b] : dp[bb];
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m >> k;
    std::cout << solve() << std::endl;
    return 0;
}
