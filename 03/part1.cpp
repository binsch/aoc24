#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {

	std::ifstream infile("input.txt");

	int step{0};
	char steps[8]{ 'm', 'u', 'l', '(', '1', '2'};
	char c;
	int sum{};
	int num1{};
	int num2{};
	while (infile.get(c))
	{
		if (steps[step] == '1') {
			if (c < 48 || c > 57) {
				if (c == ',') ++step;
				else {
					step = 0;
					num1 = 0;
					num2 = 0;
				}
			}
			else {
				num1 = 10 * num1 + (int(c) - 48);
			}
		}
		else if (steps[step] == '2') {
			if (c < 48 || c > 57) {
				if (c == ')') {
					sum += num1 * num2;
				}
				step = 0;
				num1 = 0;
				num2 = 0;
			}
			else {
				num2 = 10 * num2 + (int(c) - 48);
			}
		}
		else if (steps[step] == c) {
			++step;
		}
		else {
			step = 0;
			num1 = 0;
			num2 = 0;
		}
	}

	std::cout << sum;

	return 0;
}