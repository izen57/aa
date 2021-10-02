#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include "getCPUTime.h"

std::vector<std::vector<int>> init_matrix(std::vector<std::vector<int>> &matrix, std::string str1, std::string str2)
{
	int n = str1.length(), m = str2.length();

	for (int i = 0; i < m + 1; i++)
		matrix[i][0] = i;
	for (int j = 0; j < n + 1; j++)
		matrix[0][j] = j;

	return matrix;
}

void output_matrix(std::vector<std::vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << ' ';
			if (j == matrix[i].size() - 1)
				std::cout << std::endl;
		}
}

int sbrt(std::vector<std::vector<int>> &matrix, std::string str1, std::string str2)
{
	int n = str1.length(), m = str2.length();

	if (matrix[m][n] != INT_MAX)
		return matrix[m][n];
	else
	{
		int dist = sbrt(matrix, str1.substr(0, n - 1), str2) + 1;
		dist = std::min(dist, sbrt(matrix, str1, str2.substr(0, m - 1))/* + 1*/);
		dist = std::min(dist, sbrt(matrix, str1[n - 1] == str2[m - 1] ? str1.substr(0, n - 1) : str1, str2.substr(0, m - 1))/* + 1*/);
		matrix[m][n] = dist;
		return dist;
	}
}

int lev_dist_rec_mtrx(std::string str1, std::string str2) // Рекурсивно-матричное расстояние Левенштейна
{
	std::vector<std::vector<int>> matrix(str2.length() + 1, std::vector<int>(str1.length() + 1, INT_MAX));
	matrix = init_matrix(matrix, str1, str2);
	int dist = sbrt(matrix, str1, str2);

	std::cout << "\nRecurcive matrix:" << std::endl;
	output_matrix(matrix);
	return dist;
}

int lev_dist_rec(std::string str1, std::string str2) // Рекурсивное расстояние Левенштейна
{
	int n = str1.length(), m = str2.length();
	if (!n)
		return m;
	else
		if (!m && n > 0)
			return n;
		else
		{
			int cost = 0;
			int dist = lev_dist_rec(str1.substr(0, n - 1), str2) + 1;
			dist = std::min(dist, lev_dist_rec(str1, str2.substr(0, m - 1)) + 1);
			dist = str1[n - 1] == str2[m - 1]? std::min(dist, lev_dist_rec(str1.substr(0, n - 1), str2.substr(0, m - 1)))
																: std::min(dist, lev_dist_rec(str1.substr(0, n - 1), str2.substr(0, m - 1)) + 1);
			return dist;
		}
}

int lev_dist_mtrx(std::string str1, std::string str2)
{
	int n = str1.length(), m = str2.length();
	std::vector<std::vector<int>> matrix(m + 1, std::vector<int>(n + 1, INT_MAX));
	matrix = init_matrix(matrix, str1, str2);

	for (int i = 1; i < m + 1; i++)
		for (int j = 1; j < n + 1; j++)
		{
			matrix[i][j] = std::min(matrix[i][j], matrix[i - 1][j] + 1);
			matrix[i][j] = std::min(matrix[i][j], matrix[i][j - 1] + 1);
			matrix[i][j] = std::min(matrix[i][j], str1[j - 1] == str2[i - 1]? matrix[i - 1][j - 1] : matrix[i - 1][j - 1] + 1);
		}

	std::cout << "\nNon-recurcive matrix:" << std::endl;
	output_matrix(matrix);
	return matrix[m][n];
}

int damlev_dist_mtrx(std::string str1, std::string str2)
{
	int n = str1.length(), m = str2.length();
	std::vector<std::vector<int>> matrix(m + 1, std::vector<int>(n + 1, INT_MAX));
	matrix = init_matrix(matrix, str1, str2);

	for (int i = 1; i < m + 1; i++)
		for (int j = 1; j < n + 1; j++)
		{
			matrix[i][j] = std::min(matrix[i][j], matrix[i - 1][j] + 1);
			matrix[i][j] = std::min(matrix[i][j], matrix[i][j - 1] + 1);
			matrix[i][j] = std::min(matrix[i][j], str1[j - 1] == str2[i - 1] ? matrix[i - 1][j - 1] : matrix[i - 1][j - 1] + 1);

			if (i > 1 && j > 1 && str1[j - 2] == str2[i - 1] && str1[j - 1] == str2[i - 2])
				matrix[i][j] = std::min(matrix[i][j], matrix[i - 2][j - 2] + 1);
		}

	std::cout << "\nDamerau-Levenshtein matrix:" << std::endl;
	output_matrix(matrix);
	return matrix[m][n];
}

void input(std::string &str1, std::string &str2)
{
	std::cout << "Input two strings:" << std::endl;
	try
	{
		std::cin >> str1;
		std::cin >> str2;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void output(std::string str1, std::string str2)
{
	std::cout << "\nThe lenght of first string: " << str1.length() << std::endl;
	std::cout << "The lenght of second string: " << str2.length() << std::endl;
}

int main(void)
{
	std::setbuf(stdout, nullptr);
	std::string str1, str2;
	input(str1, str2);
	output(str1, str2);
	double start_time, end_time;

	start_time = getCPUTime();
	int s = lev_dist_rec(str1, str2);
	end_time = getCPUTime();

	std::cout << "\nThe recursive Levenshtein distance: " << s << std::endl;
	// std::cout << "CPU time used for the recursive Levenshtein distance in nanoseconds: " << (end_time - start_time) * std::pow(10, 9) << std::endl;

	start_time = getCPUTime();
	s = lev_dist_rec_mtrx(str1, str2);
	end_time = getCPUTime();

	std::cout << "The recursive-matrix Levenshtein distance: " << s << std::endl;
	// std::cout << "CPU time used for the recursive-matrix Levenshtein distance in nanoseconds: " << (end_time - start_time) * std::pow(10, 9) << std::endl;

	start_time = getCPUTime();
	s = lev_dist_mtrx(str1, str2);
	end_time = getCPUTime();

	std::cout << "The matrix Levenshtein distance: " << s << std::endl;
	// std::cout << "CPU time used for the matrix Levenshtein distance in nanoseconds: " << (end_time - start_time) * std::pow(10, 9) << std::endl;

	start_time = getCPUTime();
	s = damlev_dist_mtrx(str1, str2);
	end_time = getCPUTime();

	std::cout << "The recursive-matrix Damerau-Levenshtein distance: " << s << std::endl;
	// std::cout << "CPU time used for the matrix Damerau-Levenshtein distance in nanoseconds: " << (end_time - start_time) * std::pow(10, 9) << std::endl;
	return 0;
}