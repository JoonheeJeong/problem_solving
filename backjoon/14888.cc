#include <iostream>
#include <vector>

int N;
std::vector<int> operands;
std::vector<int> op_count(4);

int max = INT32_MIN;
int min = INT32_MAX;

void solve(int n, int pos, int val)
{
	if (pos == N) {
		if (val > max)
			max = val;
		if (val < min)
			min = val;
		return;
	}
	
	int next_val;

	for (int i = 0; i < 4; ++i) {
		if (op_count[i] == 0)
			continue;
		--op_count[i];
		switch(i) {
			case 0:
				next_val = val + operands[pos];
				break;
			case 1:
				next_val = val - operands[pos];
				break;
			case 2:
				next_val = val * operands[pos];
				break;
			default:
				next_val = val / operands[pos];
				break;
		}
		solve(n, pos + 1, next_val);
		++op_count[i];
	}
}

int main()
{
	int n;

	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		std::cin >> n;
		operands.push_back(n);
	}

	for (int i = 0; i < 4; ++i) {
		std::cin >> op_count[i];
	}

	solve(N, 1, operands[0]);
	std::cout << max << "\n" << min << std::endl;

	return 0;
}
