#include <iostream>
#include <algorithm> // sort

using namespace std;

int n_stop;
int n_stop_to_add;
int len;
int pos[1000];
int diff[1000];

enum result {
    OVER_FIT,
    FIT,
    UNDER_FIT
};

result calc_sum_quot(int target)
{
    int sum_quot = 0;
    for (int i = n_stop; i >= 0 && sum_quot <= n_stop_to_add; --i)
        sum_quot += (diff[i]-1) / target;
    if      (sum_quot >  n_stop_to_add) return UNDER_FIT;
    else if (sum_quot == n_stop_to_add) return FIT;
    else                                return OVER_FIT;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n_stop >> n_stop_to_add >> len;
    for (int i = 0; i < n_stop; ++i)
        cin >> pos[i];
    sort(pos, pos+n_stop);

    diff[0] = pos[0];
    for (int i = 0; i < n_stop-1; ++i)
        diff[i+1] = pos[i+1] - pos[i];
    diff[n_stop] = len - pos[n_stop-1];
    sort(diff, diff+n_stop+1);

    // lo <= x <= hi
    int lo = 1;
    int hi = diff[n_stop];
    while(lo != hi) {
        int mid = (lo + hi) / 2;
        result res_sum_quot = calc_sum_quot(mid);
        switch(res_sum_quot) {
            case UNDER_FIT:
                lo = mid + 1;
                break;
            default:
                hi = mid;
                break;
        }
    }

    cout << lo << endl;
    return 0;
}
