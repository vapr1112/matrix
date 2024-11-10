#pragma once
#include <iostream>

using namespace std;

template <class T> class Matrix
{
private:
	T** matrix;
	int col;
	int row;
public:

	Matrix() : Matrix(nullptr, 3, 3){}

	//главный конструктор
	Matrix(const T** matrix_p, const int row_p, int col_p) : matrix{ new T * [row_p] }, row{ row_p }, col{ col_p }
	{
		matrix = new T* [row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[col];
		}

		if (matrix_p)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					matrix[i][j] = matrix_p[i][j];
				}
			}
		}
	}

	//конструктор копировани€
	Matrix(const Matrix& matrix_p) : matrix(new T* [matrix_p.row]), row{ matrix_p.row }, col{ matrix_p.col }
	{
		matrix = new T * [row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = matrix_p.matrix[i][j];
			}
		}
	}

	//аксессоры и модификаторы
	void set_matrix(const T** matrix_p, const int row_p, const int col_p)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;

		col = col_p;

		row = row_p;

		matrix = new T* [row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = matrix_p[i][j];
			}
		}
	}

	const T** get_matrix()const
	{
		return matrix;
	}

	int get_col()const
	{
		return col;
	}

	int get_row() const
	{
		return row;
	}

	//ввывод матрицы
	void print()
	{
		cout << "\n ћатрица\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}

	//заполн€ет матрицу раномными числами
	void fill_random()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = rand() % 10 + 1;
			}
		}
	}

	//ищет максимальный элемент
	void max()
	{
		T max_number = matrix[0][0];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] > max_number)
				{
					max_number = matrix[i][j];
				}
			}
		}
		cout << "\nмаксимальное число " << max_number;
	}

	//ищет минимальный элемент
	void min()
	{
		T min_number = matrix[0][0];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] < min_number)
				{
					min_number = matrix[i][j];
				}
			}
		}
		cout << "\nминимальное число " << min_number;
	}

	//перегрузка оператора >>
	friend istream& operator>>(istream& cin_p, Matrix<T>& matrix_p)
	{
		for (int i = 0; i < matrix_p.row; i++)
		{
			for (int j = 0; j < matrix_p.col; j++)
			{
				cin >> matrix_p.matrix[i][j];
			}
		}
		return cin_p;
	}

	//перегрузки математических операторов
	const Matrix& operator=(const Matrix& matrix_p)
	{
		if (&matrix_p != this)
		{
			for (int i = 0; i < row; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;

			matrix = new T * [row];

			for (int i = 0; i < row; i++)
			{
				matrix[i] = new T[col];
			}

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					matrix[i][j] = matrix_p.matrix[i][j];
				}
			}
		}

		return *this;
	}


	friend const Matrix operator+(const Matrix<T>& matrix_1, const Matrix<T>& matrix_2)
	{
		Matrix matrx_buf;

		for (int i = 0; i < matrix_1.row; i++)
		{
			for (int j = 0; j < matrix_1.col; j++)
			{
				matrx_buf.matrix[i][j] = matrix_1.matrix[i][j] + matrix_2.matrix[i][j];
			}
		}

		return matrx_buf;
	}

	friend const Matrix operator-(const Matrix<T>& matrix_1, const Matrix<T>& matrix_2)
	{
		Matrix matrx_buf;

		for (int i = 0; i < matrix_1.row; i++)
		{
			for (int j = 0; j < matrix_1.col; j++)
			{
				matrx_buf.matrix[i][j] = matrix_1.matrix[i][j] - matrix_2.matrix[i][j];
			}
		}

		return matrx_buf;
	}

	friend const Matrix operator*(const Matrix<T>& matrix_1, const Matrix<T>& matrix_2)
	{
		Matrix matrx_buf;

		for (int i = 0; i < matrix_1.row; i++)
		{
			for (int j = 0; j < matrix_1.col; j++)
			{
				for (int k = j; k < matrix_1.col; k++)
				{
					if (k == j)
					{
						matrx_buf.matrix[i][j] = matrix_1.matrix[i][k] * matrix_2.matrix[k][i];
					}
					else
					{
						matrx_buf.matrix[i][j] += matrix_1.matrix[i][k] * matrix_2.matrix[k][i];
					}
				}
			}
		}
		return matrx_buf;
	}

	friend const Matrix operator/(const Matrix<T>& matrix_1, const Matrix<T>& matrix_2)
	{
		Matrix matrx_buf;

		for (int i = 0; i < matrix_1.row; i++)
		{
			for (int j = 0; j < matrix_1.col; j++)
			{
				matrx_buf.matrix[i][j] = matrix_1.matrix[i][j] * (matrix_2.matrix[i][j] / (matrix_2.matrix[i][j] * matrix_2.matrix[i][j]));
			}
		}

		return matrx_buf;
	}

	~Matrix()
	{
		for (int i = 0; i < row; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;
	}
};

