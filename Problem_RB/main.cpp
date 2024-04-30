#include <iostream>
#include <vector>
#include <locale>

int trapWater(const std::vector<int>& heights) {
	int n = heights.size();
	if (n <= 2) {
		return 0; // Меньше двух плиток, вода не скапливается
	}

	int left = 0;        // Левый указатель
	int right = n - 1;   // Правый указатель
	int leftMax = 0;     // Максимальная высота слева
	int rightMax = 0;    // Максимальная высота справа
	int water = 0;       // Сумма воды

	while (left < right) {
		if (heights[left] < heights[right]) {
			if (heights[left] >= leftMax) {
				leftMax = heights[left];
			}
			else {
				water += leftMax - heights[left];
			}
			left++;
		}
		else {
			if (heights[right] >= rightMax) {
				rightMax = heights[right];
			}
			else {
				water += rightMax - heights[right];
			}
			right--;
		}
	}

	return water;
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<int> heights = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int trappedWater = trapWater(heights);
	std::cout << "Объем скопившейся воды: " << trappedWater << " единиц" << std::endl;

	return 0;
}
