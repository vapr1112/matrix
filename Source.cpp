#include "Matrix.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	Matrix<double> matrix_1, matrix_2, matrix_3;

	int user;

	enum menu {FILL_CIN = 1, FILL_RANDOM, PRINT, MIN, MAX, SUMN, SUBTRACTION, MULTIPLICATION, DIVICION};

	do
	{
		cout << "\nвведите \n1 заполнить \n2 заполнить рандомными числами \n3 показать \n4 минимальный элемент \n5 максимальный элемент \n6 сложение \n7 вычитание \n8 умножение \n9 деление\n";
		
		cin >> user;

		switch (user)
		{
		case FILL_CIN:
			cout << "\nвведите матрицу\n";
			cin >> matrix_1;
			cout << "\nвведите матрицу\n";
			cin >> matrix_2;
			break;
		case FILL_RANDOM:
			matrix_1.fill_random();
			matrix_2.fill_random();
			break;
		case PRINT:
			matrix_1.print();
			cout << "\n";
			matrix_2.print();
			break;
		case MIN:
			matrix_1.min();
			break;
		case MAX:
			matrix_1.max();
			break;
		case SUMN:
			matrix_3 = matrix_1 + matrix_2;
			cout << "\nсумма полученной матрицы \n";
			matrix_3.print();
			break;
		case SUBTRACTION:
			matrix_3 = matrix_1 - matrix_2;
			cout << "\nразность полученной матрицы \n";
			matrix_3.print();
			break;
		case MULTIPLICATION:
			matrix_3 = matrix_1 * matrix_2;
			cout << "\nпроизведение полученной матрицы \n";
			matrix_3.print();
			break;
		case DIVICION:
			matrix_3 = matrix_1 / matrix_2;
			cout << "\nчастное полученной матрицы \n";
			matrix_3.print();
			break;
		default:
			break;
		}
	} while (user != 0);

	return 0;
}