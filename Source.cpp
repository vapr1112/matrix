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
		cout << "������� \n1 ��������� \n2 ��������� ���������� ������� \n3 �������� \n4 ����������� ������� \n5 ������������ ������� \n6 �������� \n7 ��������� \n8 ��������� \n9 �������\n";
		
		cin >> user;

		switch (user)
		{
		case FILL_CIN:
			cout << "\n������� �������\n";
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