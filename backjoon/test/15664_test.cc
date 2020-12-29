#include <iostream>
#include <vector>
#include <algorithm> // find, sort, min

#include <fstream>
#include <string>
#include <sstream>

struct option {
    int id;
    int size;
    option(int id) : id(id), size(1) {}
};

bool operator<(const option &lhs, const option &rhs)
{
    return lhs.id < rhs.id;
}

bool operator==(const option &lhs, const option &rhs)
{
    return lhs.id == rhs.id;
}

int n, m;
std::vector<option> input;
std::vector<int> output;
std::vector<std::vector<int>> answer, result;

void n_and_m(int pos, int rem)
{
    if (rem == 0) {
        result.push_back(output);
        return;
    }
    if (pos == (int) input.size()) return;

    option &opt = input[pos];
    int &id = opt.id;
    for (int i = std::min(opt.size, rem); i >= 0; i--) {
        for (int j = 0; j < i; j++)
            output.push_back(id);
        n_and_m(pos+1, rem-i);
        for (int j = 0; j < i; j++)
            output.pop_back();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ifstream f("./testcase/15664_tc.txt");
    std::istream &is = f;
    int test_cnt = 1;
    do {
        is >> n >> m;
        if (is.eof()) 
            break;

        is.get();
        std::string str;
        std::getline(is, str);
        std::istringstream input_stream(str);
        for (int temp; input_stream >> temp; ) {
            auto it = std::find(input.begin(), input.end(), temp);
            if (it != input.end())
                it->size++;
            else
                input.push_back({temp});
        }

        do {
            std::getline(is, str);
            if (str.empty())
                break;
            std::istringstream answer_stream(str);
            std::vector<int> answer_line;
            for (int temp; answer_stream >> temp; )
                answer_line.push_back(temp);
            answer.push_back(answer_line);
        } while (true);

        std::sort(input.begin(), input.end());
        n_and_m(0, m);

        if (answer.size() != result.size()) {
            std::cerr << "test #" << test_cnt << " failed:\n"
                      << "wrong number of lines of output\n"
                      << "answer: " << answer.size() << std::endl;
            return 0;
        }
        for (int i = 0; i < answer.size(); ++i) {
            std::vector<int> &answer_line = answer[i];
            std::vector<int> &result_line = result[i];
            if (m != (int) result_line.size()) {
                std::cerr << "test #" << test_cnt << " failed:\n"
                          << "wrong number of elements of output\n"
                          << "line #" << i+1 << '\n'
                          << "answer: " << m << '\n';
                for (int &e : answer_line)
                    std::cerr << e << ' ';
                std::cerr << "\noutput: " << result_line.size() << '\n';
                for (int &e : result_line)
                    std::cerr << e << ' ';
                std::cerr << std::endl;
                return 0;
            }
            for (int j = 0; j < m; ++j) {
                if (answer_line[j] != result_line[j]) {
                    std::cerr << "test #" << test_cnt << " failed:\n"
                              << "expected:\n";
                    for (int &e : answer_line)
                        std::cerr << e << ' ';
                    std::cerr << "\nyour output:\n";
                    for (int &e : result_line)
                        std::cerr << e << ' ';
                    std::cerr << std::endl;
                    return 0;
                }
            }
        }
        std::cerr << "test #" << test_cnt++ << " succeeded.\n";
        input.clear();
        result.clear();
        answer.clear();
    } while (true);
    return 0;
}
