#include <iostream>
#include <string>

using namespace std;

string solve(string::iterator &it)
{
    char c = *it++;
    if (c != 'x') 
        return string(1, c);
    else {
        string ul = solve(it);
        string ur = solve(it);
        string ll = solve(it);
        string lr = solve(it);
        return string("x") + ll + lr + ul + ur;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        auto it = s.begin();
        cout << solve(it) << '\n';
    }
    return 0;
}
