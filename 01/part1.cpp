#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

int LINECOUNT{ 1000 };

int main() {

	std::ifstream infile("input.txt");

	int a{};
	int b{};
	std::string s{};

	std::vector<int> first(LINECOUNT);
	std::vector<int> second(LINECOUNT);

	std::size_t i{};
	while (infile >> a >> b) {
		first[i] = a;
		second[i] = b;
		++i;
	}

	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());

	int sum{ 0 };
	int diff{};
	for (i = 0; i < LINECOUNT; ++i) {
		diff = first[i] - second[i];
		if (diff > 0) sum += diff;
		else sum -= diff;
	}

	std::cout << sum << '\n';

	return 0;
}