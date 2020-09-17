#include <iostream>
#include <array>
#include <queue>

struct coord {
	int x;
	int y;
};

int T, len, curr_x, curr_y, goal_x, goal_y;
typedef std::array<int, 300> Row;
std::array<Row, 300> board;

int main() 
{
	std::cin >> T;
	while (--T >= 0) {
		std::for_each(board.begin(), board.end(), [] (
		std::cin >> len;
		std::cin >> curr_x >> curr_y >> goal_x >> goal_y;
	}
}
