#include <iostream>
#include <string>

using namespace std;

int t;
string s;

int size(string &s, int pos)
{
    int cnt = 0;
    int i = pos;
    while (cnt != 4) {
        cnt++;
        if (s[++i] == 'x') 
            i += size(s, i) - 1;
    }
    return i-pos+1;
}

string solve(string s)
{
    if (s[0] != 'x')
        return s.substr(0, 1);

    int pos = 1;
    string ss[4];
    for (int i = 0; i < 4; ++i) {
        if (s[pos] != 'x')
            ss[i] = s[pos++];
        else {
            int len = (i != 3) ? size(s, pos) : s.size() - pos;
            ss[i] = solve(s.substr(pos, len));
            pos += len;
        }
    }

    return 'x' + ss[2] + ss[3] + ss[0] + ss[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}
