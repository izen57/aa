#include <iostream>
#include <vector>

struct my_matrix
{
	std::vector<std::vector<float>> values;
	int n;
	int m;
};

void input_matrix(my_matrix &matrix)
{
	for (int i = 0; i < matrix.n; i++)
	{
		std::cout << "Введите строку: ";
		for (int j = 0; j < matrix.m; j++)
			std::cin >> matrix.values[i][j];
	}
}

void output_matrix(my_matrix matrix)
{
	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m - 1; j++)
			std::cout << matrix.values[i][j] << ' ';
		std::cout << matrix.values[i][matrix.m - 1] << std::endl;
	}

	std::cout << std::endl;
}

bool are_matrices_ok(int m1, int n2)
{
	return m1 == n2 ? true : false;
}

my_matrix classical_multiplication(my_matrix matrix1, my_matrix matrix2)
{
	my_matrix result
	{
		std::vector<std::vector<float>>(matrix1.n, std::vector<float>(matrix2.m, 0)),
		matrix1.n,
		matrix2.m
	};

	for (int i = 0; i < result.n; i++)
		for (int j = 0; j < result.m; j++)
			for (int k = 0; k < matrix1.m; k++)
				result.values[i][j] += matrix1.values[i][k] * matrix2.values[k][j];

	return result;
}

my_matrix winograd_algorithm(my_matrix matrix1, my_matrix matrix2)
{
	my_matrix result
	{
		std::vector<std::vector<float>>(matrix1.n, std::vector<float>(matrix2.m, 0)),
		matrix1.n,
		matrix2.m
	};

	std::vector<float> row(matrix1.n, 0);
	for (int i = 0; i < matrix1.n; i++)
		for (int j = 0; j < matrix1.m / 2; j++)
			row[i] += matrix1.values[i][2 * j] * matrix1.values[i][2 * j + 1];

	std::vector<float> column(matrix2.m, 0);
	for (int i = 0; i < matrix2.m; i++)
		for (int j = 0; j < matrix1.m / 2; j++)
			column[i] += matrix2.values[2 * j][i] * matrix2.values[2 * j + 1][i];

	for (int i = 0; i < matrix1.n; i++)
		for (int j = 0; j < matrix2.m; j++)
		{
			result.values[i][j] = -row[i] - column[j];
			for (int k = 0; k < matrix1.m / 2; k++)
				result.values[i][j] += (matrix1.values[i][2 * k + 1] + matrix2.values[2 * k][j]) * (matrix1.values[i][2 * k] + matrix2.values[2 * k + 1][j]);
		}

	if (matrix1.m % 2)
		for (int i = 0; i < matrix1.n; i++)
			for (int j = 0; j < matrix2.m; j++)
				result.values[i][j] += matrix1.values[i][matrix1.m - 1] * matrix2.values[matrix1.m - 1][j];

	return result;
}

my_matrix optimized_winograd_algorithm(my_matrix matrix1, my_matrix matrix2)
{
	my_matrix result
	{
		std::vector<std::vector<float>>(matrix1.n, std::vector<float>(matrix2.m, 0)),
		matrix1.n,
		matrix2.m
	};

	std::vector<float> row(matrix1.n, 0);
	for (int i = 0; i < matrix1.n; i++)
		for (int j = 1; j < matrix1.m; j += 2)
			row[i] -= matrix1.values[i][j] * matrix1.values[i][j - 1];

	std::vector<float> column(matrix2.m, 0);
	for (int i = 0; i < matrix2.m; i++)
		for (int j = 1; j < matrix1.m; j += 2)
			column[i] -= matrix2.values[j][i] * matrix2.values[j - 1][i];

	for (int i = 0; i < matrix1.n; i++)
		for (int j = 0; j < matrix2.m; j++)
		{
			result.values[i][j] += row[i] + column[j];
			for (int k = 1; k < matrix1.m; k += 2)
			{
				result.values[i][j] += (matrix1.values[i][k - 1] + matrix2.values[k][j]) * (matrix1.values[i][k] + matrix2.values[k - 1][j]);
				if (matrix1.m % 2)
					result.values[i][j] += matrix1.values[i][matrix1.m - 1] * matrix2.values[matrix1.m - 1][j];
			}
		}

	return result;
}

int main(void)
{
	std::setbuf(stdout, nullptr);
	my_matrix matrix1, matrix2;

	bool flag = false;
	while (flag == false)
	{
		std::cout << "Ввод первой матрицы.\nВведите количество строк: ";
		std::cin >> matrix1.n;

		std::cout << "Введите количество столбцов: ";
		std::cin >> matrix1.m;

		matrix1.values = std::vector<std::vector<float>>(matrix1.n, std::vector<float>(matrix1.m, 0));
		input_matrix(matrix1);

		std::cout << "\nВвод второй матрицы.\nВведите количество строк: ";
		std::cin >> matrix2.n;

		std::cout << "Введите количество столбцов: ";
		std::cin >> matrix2.m;

		matrix2.values = std::vector<std::vector<float>>(matrix2.n, std::vector<float>(matrix2.m, 0));
		input_matrix(matrix2);

		if (are_matrices_ok)
			flag = true;
		else
			std::cout << "Матрицы не совместимы. Введите матрицы ещё раз.\n";
	}

	my_matrix classical_matrix = classical_multiplication(matrix1, matrix2);
	std::cout << "Матрица, полученная классическим умножением:" << std::endl;
	output_matrix(classical_matrix);

	my_matrix winograd_matrix = winograd_algorithm(matrix1, matrix2);
	std::cout << "Матрица, полученная алгоритмом Винограда:" << std::endl;
	output_matrix(winograd_matrix);

	my_matrix optimized_winograd_matrix = optimized_winograd_algorithm(matrix1, matrix2);
	std::cout << "Матрица, полученная оптимизированным алгоритмом Винограда:" << std::endl;
	output_matrix(optimized_winograd_matrix);
}