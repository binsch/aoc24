#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int LINECOUNT{ 1000 };

int main() {

	std::ifstream infile("input.txt");

	int a{};
	int b{};
	std::unordered_map<int, int>::iterator it{};

	std::vector<int> first(LINECOUNT);
	std::vector<int> second(LINECOUNT);

	std::unordered_map<int, int> second_counts;

	std::size_t i{};
	while (infile >> a >> b) {
		first[i] = a;
		second[i] = b;
		it = second_counts.emplace(b, 0).first;
		++(*it).second; // use iterator to increment the value
		++i;
	}

	int similarity{ 0 };
	for ( int value : first ) {
		it = second_counts.find(value);
		if (it != second_counts.end()) similarity += value * (*it).second;
	}

	std::cout << similarity << '\n';

	return 0;
}