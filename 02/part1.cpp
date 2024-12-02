#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int LINECOUNT{ 1000 };

int main() {

	std::ifstream infile("input.txt");

	int safety_count{};
	bool ascending{};
	bool is_valid{};
	std::string line;
	std::stringstream line_stream;
	int prev{};
	int curr{};
	int diff{};
	while (std::getline(infile, line)) {
		line_stream << line;
		line_stream >> prev;
		line_stream >> curr;

		diff = curr - prev;
		if (diff < -3 || diff > 3 || diff == 0) continue;
		is_valid = true;
		ascending = (prev < curr);
		prev = curr;
		while (line_stream >> curr) {
			diff = curr - prev;
			if (
				   (ascending  && (diff <  1 || diff >  3))
				|| (!ascending && (diff < -3 || diff > -1))
			) {
				is_valid = false;
				break;
			}
			prev = curr;
		}
		if (is_valid) ++safety_count;

		// reset line_stream
		line_stream.str("");
		line_stream.clear();
	}

	std::cout << safety_count << '\n';

	return 0;
}