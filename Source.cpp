#include "Matrix.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	Matrix<int> matrix_1, matrix_2;

	int user;

	enum menu {FILL_CIN = 1, FILL_RANDOM, PRINT, MIN, MAX, SUMN, SUBTRACTION, MULTIPLICATION, DIVICION};

	do
	{
		cout << "введите \n1 заполнить \n2 заполнить рандомными числами \n3 показать \n4 минимальный элемент \n5 максимальный элемент \n6 сложение \n7 вычитание \n8 умножение \n9 деление\n";
		
		cin >> user;

		switch (user)
		{
		case FILL_CIN:
			cout << "\nвведите матрицу\n";
			cin >> matrix_1;
			break;
		case FILL_RANDOM:
			matrix_1.fill_random();
			break;
		case PRINT:
			matrix_1.print();
			break;
		default:
			break;
		}
	} while (user != 0);

	return 0;
}