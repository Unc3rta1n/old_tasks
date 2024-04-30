#include <iostream>
#include <vector>
#include <stack>
#include <string>


template <typename T>
bool find_majority(const std::vector<T>& seq, T& majority_elem) {
	int count = 0;
	T elem{};
	std::stack<T> S;
	if (seq.empty()) {
		return false;
	}

	for (size_t i = 0; i < seq.size(); i++)
	{
		if (S.empty())
			S.push(seq[i]);
		else {
			if (S.top() == seq[i])
				S.push(seq[i]);
			else
				S.pop();

		}
	}


	if (S.size() == 0) {
		return false;
	}
	else {
		elem = S.top();
		for (size_t i = 0; i < seq.size(); i++) {
			if (elem == seq[i])
				count++;
		}
		if (count <= (seq.size() / 2)) {
			return false;
		}
		else
			majority_elem = elem;
	}
	return true;

}


void test_func() {
	std::vector<int> vec1 = { 1, 2, 2, 2, 3 };
	std::vector<int> vec2 = { 3, 3, 4, 2, 2 };
	std::vector<char> vec3 = { 'a', 'b', 'a', 'a', 'c' };
	std::vector<float> vec4 = { 0.1, 0.2, 0.2, 0.3, 0.2 };
	std::vector<double> vec5 = { 2.5, 2.5, 3.0, 2.5, 2.5 };
	std::vector<std::string> vec6 = { "apple", "banana", "apple", "apple", "cherry" };
	std::vector<int> vec7 = { 1, 1, 1, 1 };
	std::vector<double> vec8 = { 3.14 };
	std::vector<int> vec9;
	int majority1;
	int majority2;
	char majority3;
	float majority4;
	double majority5;
	std::string majority6;
	int majority7;
	double majority8;
	int majority9;

	if (find_majority(vec1, majority1))
		std::cout << "Majority in vec1: " << majority1 << std::endl;
	else
		std::cout << "No majority in vec1 or the vector is empty." << std::endl;

	if (find_majority(vec2, majority2))
		std::cout << "Majority in vec2: " << majority2 << std::endl;
	else
		std::cout << "No majority in vec2 or the vector is empty." << std::endl;

	if (find_majority(vec3, majority3))
		std::cout << "Majority in vec3: " << majority3 << std::endl;
	else
		std::cout << "No majority in vec3 or the vector is empty." << std::endl;

	if (find_majority(vec4, majority4))
		std::cout << "Majority in vec4: " << majority4 << std::endl;
	else
		std::cout << "No majority in vec4 or the vector is empty." << std::endl;

	if (find_majority(vec5, majority5))
		std::cout << "Majority in vec5: " << majority5 << std::endl;
	else
		std::cout << "No majority in vec5 or the vector is empty." << std::endl;

	if (find_majority(vec6, majority6))
		std::cout << "Majority in vec6: " << majority6 << std::endl;
	else
		std::cout << "No majority in vec6 or the vector is empty." << std::endl;

	if (find_majority(vec7, majority7))
		std::cout << "Majority in vec7: " << majority7 << std::endl;
	else
		std::cout << "No majority in vec7 or the vector is empty." << std::endl;

	if (find_majority(vec8, majority8))
		std::cout << "Majority in vec8: " << majority8 << std::endl;
	else
		std::cout << "No majority in vec8 or the vector is empty." << std::endl;

	if (find_majority(vec9, majority9))
		std::cout << "Majority in vec9: " << majority9 << std::endl;
	else
		std::cout << "No majority in vec9 or the vector is empty." << std::endl;

}



int main() {
	test_func();
	return 0;
}