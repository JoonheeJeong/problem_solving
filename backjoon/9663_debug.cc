/* 
   0. bool -> 마킹한 역순으로 해야 하는데 잘못 생각함
   1. int, += i, -= i -> when i == 0, += 0
   2. ++, -- -> success!
   ----
   n^n * n! ? 암튼 굉장히 복잡도 높음.
*/

#include <iostream>
#include <vector>

struct N_Queen {
	int n;
	std::vector<std::vector<int>> chk;
	int count;
	
	N_Queen(int n) : n(n), chk(n, std::vector<int>(n, 0)) { print(); }

	void operator()(int i = 0);

private:
	void print();
	void mark(int i, int j);
	void unmark(int i, int j);
};

void N_Queen::print()
{
	for (auto row : chk) {
		for (auto e : row) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}

void N_Queen::mark(int i, int j)
{
	chk[i][j]++;
	int next_i, j5, j7;
	j5 = j7 = j;
	for (next_i = i+1; next_i < n; next_i++) {
		chk[next_i][j]++; // 6시 방향

		if (--j7 >= 0) {
			chk[next_i][j7]++; // 7시 방향
			chk[i][j7]++; // 9시 방향
		}

		if (++j5 < n) {
			chk[next_i][j5]++; // 5시 방향
			chk[i][j5]++; // 3시 방향
		}
	}
}

void N_Queen::unmark(int i, int j)
{
	chk[i][j]--;
	int next_i, j5, j7;
	j5 = j7 = j;
	for (next_i = i+1; next_i < n; next_i++) {
		chk[next_i][j]--; // 6시 방향

		if (--j7 >= 0) {
			chk[next_i][j7]--; // 7시 방향
			chk[i][j7]--; // 9시 방향
		}

		if (++j5 < n) {
			chk[next_i][j5]--; // 5시 방향
			chk[i][j5]--; // 3시 방향
		}
	}
}

void N_Queen::operator()(int i)
{
	if (i == n) { 
		count++;
		return;
	}

	for (int j = 0; j < n; ++j)
	{
		if (chk[i][j] > 0) continue;
		mark(i, j);
		std::cout << "mark " << i << " " << j << std::endl;
		print();
		std::cout << "call recursive operator " << i << " " << j << "\n";
		operator()(i+1);
		std::cout << "done" << std::endl;
		unmark(i, j);
		std::cout << "unmark " << i << " " << j << std::endl;
		print();
	}
}

int main()
{
	int n;
	std::cin >> n;
	N_Queen nq(n);
	std::cout << "call" << std::endl;
	nq(0);
	std::cout << nq.count << std::endl;
	return 0;
}
