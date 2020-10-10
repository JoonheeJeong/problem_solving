#include <iostream>
#include <cmath>
#include <deque>

const int M = 500000;
int n, k;
bool block[10];
std::deque<int> nums;
int len;
int unblock_min;
int unblock_max;

int find_down(int num)
{
    for (int j = num-1; j >= 0; --j)
        if (!block[j])
            return j;
    return 10;
}

int find_up(int num)
{
    for (int j = num+1; j < 10; ++j)
        if (!block[j])
            return j;
    return -1;
}

int get_sum(const int &beg, const int &end, const int &init, const int &val)
{
    int res = init;
    for (int i = beg; i < end; ++i)
        res = 10*res + val;
    return res;
}

int min_same_len()
{
    int i = 0;
    int num;
    for (; i < len; ++i) { 
        num = nums[i];
        if (block[num])
            break;
    }
    if (i == len)
        return 0;

    int sum = 0;
    for (int j = 0; j < i-1; ++j) {
        num = nums[j];
        sum = (sum + num) * 10;
    }

    int down, up, res_down, res_up;
    res_down = res_up = M;
    num = (i == 0) ? 0 : nums[i-1];
    if (i > 0) {
        down = find_down(num);
        up = find_up(num);
        if (down != 10)
            res_down = n - get_sum(i, len, sum + down, unblock_max);
        if (up != -1)
            res_up = get_sum(i, len, sum + up, unblock_min) - n;
    }
    sum = (sum + num) * 10;
    num = nums[i];
    down = find_down(num);
    up = find_up(num);
    i++;
    int temp;
    if (down != 10) {
        temp = n - get_sum(i, len, sum + down, unblock_max);
        if (temp < res_down)
            res_down = temp;
    }
    if (up != -1) {
        temp = get_sum(i, len, sum + up, unblock_min) - n;
        if (temp < res_up)
            res_up = temp;
    }
    return std::min(res_down, res_up);
}

int solve()
{
    int diff_100 = std::abs(n - 100);

    if (k == 10) 
        return diff_100;

    int temp = n;
    do {
        nums.push_front(temp % 10);
        temp /= 10;
    } while (temp != 0);

    for (int i = 9; i >= 0; --i) {
        if (!block[i]) {
            unblock_max = i;
            break;
        }
    }
    len = nums.size();
    int short_max = (len > 1) ? n - get_sum(1, len, 0, unblock_max) + len - 1 : M;

    int front = 9;
    for (int i = 1; i < 10; ++i) {
        if (!block[i]) {
            front = i;
            break;
        }
    }
    unblock_min = (!block[0]) ? 0 : front;
    int long_min = get_sum(0, len, front, unblock_min) - n + len + 1;

    int same_len = min_same_len() + len;
    int res = (same_len < diff_100) ? same_len : diff_100;
    if (short_max < res)
        res = short_max;
    if (long_min < res)
        res = long_min;

    return res;
}

int main()
{
    std::cin >> n >> k;
    int i, temp;
    i = k;
    while (i--) {
        std::cin >> temp;
        block[temp] = true;
    }

    std::cout << solve() << std::endl;
    return 0;
}
