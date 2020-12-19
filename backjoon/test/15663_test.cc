#include <iostream>
#include <vector>
#include <algorithm> // sort

/////// for test ///////
#include <fstream>
#include <string>
#include <sstream>
////////////////////////

int n, m, len;
std::vector<int> input, remains, output;
std::vector<std::vector<int>> answer, result;

void n_and_m(int cnt)
{
    if (cnt == m) {
        result.push_back(output);
        return;
    }

    for (int i = 0; i < len; ++i) {
        if (remains[i] != 0) {
            remains[i]--;
            output.push_back(input[i]);
            n_and_m(cnt+1);
            output.pop_back();
            remains[i]++;
        }
    }
}

void set_remains()
{
    auto i = input.begin();
    auto j = i;
    auto end = input.end();
    while (++j != end) {
        if (*i != *j) {
            remains.push_back(j-i);
            i = j;
        }
    }
    remains.push_back(j-i);
    len = remains.size();
}

void n_and_m()
{
    std::sort(input.begin(), input.end());
    set_remains();
    auto last = std::unique(input.begin(), input.end());
    input.erase(last, input.end());
    n_and_m(0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ifstream f0("./testcase/15663_tc.txt");
    std::istream &is = f0;
    int count = 1;
    do {
        is >> n >> m;
        if (is.eof())
            break;

        // 1. get a line and transform it and move into the vector
        is.get();
        std::string line;
        std::getline(is, line);
        std::istringstream iss(line);
        int temp;
        while (iss >> temp)
            input.push_back(temp);

        // 2. read until encounter a blank line and transform it 
        // and move into the two-dimentional vector (result)
        do {
            std::getline(is, line);
            if (line.empty())
                break;
            iss = std::istringstream(line);
            std::vector<int> ans_row;
            while (iss >> temp)
                ans_row.push_back(temp);
            answer.push_back(ans_row);
        } while (true);

        // 3. compare my answer with the correct answer above
        n_and_m();

        int rows = answer.size();
        if ((int) result.size() != rows) {
            std::cerr << "test #" << count << " fail\n"
                      << "wrong result size\n"
                      << "expected result size: " << rows << "\n"
                      << "output result size: " << result.size()
                      << std::endl;
            return 0;
        }
        for (int i = 0; i < rows; ++i) {
            auto &res_row = result[i];
            if ((int) res_row.size() != m) {
                std::cerr << "test #" << count << " fail\n"
                          << "wrong row size\n"
                          << "expected result size: " << m << "\n"
                          << "output result size: " << res_row.size()
                          << std::endl;
                return 0;
            }
            auto &ans_row = answer[i];
            for (int j = 0; j < m; ++j) {
                if (res_row[j] == ans_row[j]) continue;
                std::cerr << "test #" << count << " fail\n"
                          << "wrong answer\n";
                std::cerr << "expected answer:\n";
                std::for_each(ans_row.begin(), ans_row.end(), [](int &e) {std::cerr << e << " ";});
                std::cerr << "\nresult:\n";
                std::for_each(res_row.begin(), res_row.end(), [](int &e) {std::cerr << e << " ";});
                std::cerr << std::endl;
                return 0;
            }
        }
        std::cout << "test #" << count++ << " pass\n";

        input.clear();
        result.clear();
        answer.clear();
        remains.clear();
    } while (true); 
    return 0;
}
