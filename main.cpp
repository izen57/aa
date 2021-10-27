#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> bubble_sort(std::vector<int> array)
{
	for (int i = 0; i < array.size() - 1; ++i)
		for (int j = i + 1; j < array.size(); ++j)
			if (array[i] > array[j])
				std::swap(array[i], array[j]);

	return array;
}

std::vector<int> insert_sort(std::vector<int> array)
{
	for (int i = 0; i < array.size(); ++i)
	{
		int j = i - 1;
		int key = array[i];
		for (; array[j] > key && j >= 0; --j)
			array[j + 1] = array[j];

		array[j + 1] = key;
	}

	return array;
}

void quick_sort(std::vector<int> &array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2];

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			std::swap(array[i], array[j]);
			i++;
			j--;
		}
	}

	if (j > low)
		quick_sort(array, low, j);
	if (i < high)
		quick_sort(array, i, high);
}

int main(void)
{
	int n;
	std::cout << "Введите размер массива: ";
	std::cin >> n;

	std::vector<int> array;
	array.resize(n);

	std::cout << "Введите через пробел элементы массива: ";
	for (int i = 0; i < n; i++)
		std::cin >> array[i];

	std::cout << "Исходный массив: ";
	for (int elem : array)
		std::cout << elem << ' ';

	std::cout << std::endl;

	std::vector<int> bubbled_array = bubble_sort(array);
	std::cout << "Массив, отсортированный пузырьком: ";
	for (int elem : bubbled_array)
		std::cout << elem << ' ';

	std::cout << std::endl;

	std::vector<int> inserted_array = insert_sort(array);
	std::cout << "Массив, отсортированный с помощью вставок: ";
	for (int elem : inserted_array)
		std::cout << elem << ' ';

	std::cout << std::endl;

	std::vector<int> quicked_array = array;
	quick_sort(quicked_array, 0, n - 1);
	std::cout << "Массив, отсортированный быстрым алгоритмом: ";
	for (int elem : quicked_array)
		std::cout << elem << ' ';
}