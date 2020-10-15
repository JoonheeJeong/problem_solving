#include <iostream>
#include <deque>

struct Cogwheel {
    void turn(int wise);
    void push(bool);
    std::deque<bool> cog;
};

void Cogwheel::turn(int wise)
{
    if (wise == 1) {
        bool temp = cog.back();
        cog.pop_back();
        cog.push_front(temp);
    } else if (wise == -1) {
        bool temp = cog.front();
        cog.pop_front();
        cog.push_back(temp);
    } else {
        std::cerr << "error" << std::endl;
        std::exit(0);
    }
}

void Cogwheel::push(bool b)
{
    cog.push_back(b);
}

Cogwheel cogwheels[4];

void turn_left(int pos, int wise)
{
    int left = pos - 1;
    if (left >= 0) {
        if (cogwheels[left].cog[2] != cogwheels[pos].cog[6]) {
            turn_left(left, -wise);
            cogwheels[left].turn(-wise);
        }
    }
}

void turn_right(int pos, int wise)
{
    int right = pos + 1;
    if (right < 4) {
        if (cogwheels[pos].cog[2] != cogwheels[right].cog[6]) {
            turn_right(right, -wise);
            cogwheels[right].turn(-wise);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    char c;
    for (int i = 0; i < 4; ++i) {
        Cogwheel &cw = cogwheels[i];
        for (int j = 0; j < 8; ++j) {
            std::cin >> c;
            cw.push(c-'0');
        }
    }

    int k, j, wise;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> j >> wise;
        int pos = j - 1;
        turn_left(pos, wise);
        turn_right(pos, wise);
        cogwheels[pos].turn(wise);
    }

    int res = 0;
    int t = 1;
    for (int i = 0; i < 4; ++i) {
        if (cogwheels[i].cog[0])
            res += t;
        t *= 2;
    }
    std::cout << res << std::endl;
    return 0;
}
