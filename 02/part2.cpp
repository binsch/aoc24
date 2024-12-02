#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int LINECOUNT{ 1000 };

bool validate(std::vector<int> values) {
	int diff{ values[1] - values[0] };

	if (diff < -3 || diff > 3 || diff == 0) return false;
	bool ascending{ (values[0] < values[1]) };
	for (int i{ 1 }; i < values.size() - 1; ++i) {
		diff = values[i + 1] - values[i];
		if (
			(ascending && (diff < 1 || diff >  3))
			|| (!ascending && (diff < -3 || diff > -1))
			) {
			return false;
		}
	}
	return true;
}

int main() {

	std::ifstream infile("input.txt");

	int safety_count{};
	std::string line;
	std::stringstream line_stream;
	while (std::getline(infile, line)) {
		std::vector<int> values;
		line_stream << line;
		int value;
		while (line_stream >> value) {
			values.push_back(value);
		}
		if (validate(values)) ++safety_count;
		else {
			for (int i{ 0 }; i < values.size(); ++i) {
				std::vector<int> copy(values);
				copy.erase(std::next(copy.begin(), i));
				if (validate(copy)) {
					++safety_count;
					break;
				}
			}
		}
		line_stream.str("");
		line_stream.clear();
	}

	std::cout << safety_count << '\n';

	return 0;
}