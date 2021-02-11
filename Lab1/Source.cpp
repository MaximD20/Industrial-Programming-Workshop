#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void print_m(int n, int m, int** arr)//Метод вывода матрицы на экран
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
int** create_m(int n, int m)//Метод создания матрицы  n*m
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	return arr;
}
int** create_m(int n)//Метод создания матрицы n*n
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	}
	return arr;
}
void appr_matrix(int** matrix1, int** matrix2, int n, int m, int type)//Заполнение значений матрицы  matrix1 значениями согласно выражениям, выбор которого зависит от type
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			switch (type)
			{
			case 1:
				matrix1[i][j] = matrix2[i][j];
				break;
			case 2:
				matrix1[i][j] = matrix2[i][j + m];
				break;
			case 3:
				matrix1[i][j] = matrix2[i + n][j];
				break;
			case 4:
				matrix1[i][j] = matrix2[i + n][j + m];
				break;
			}
	}
}
void appr_matrix(int** matrix1, int** matrix2, int** matrix3, int** matrix4, int n, int type) //Аналогично предыдущему но в выражении используются 3 матрицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix1[i][j] = 0;
			for (int z = 0; z < n; z++)
			{
				switch (type)
				{
				case 1:
					matrix1[i][j] += (matrix2[i][z] + matrix3[i][z]) * matrix4[z][j];
					break;
				case 2:
					matrix1[i][j] += matrix2[i][z] * (matrix3[z][j] - matrix4[z][j]);
					break;
				}
			}
		}
	}
}
void delete_matrix(int** matrix, int m) // Метод освобождения памяти двумерного массива
{
	for (int i = 0; i < m; i++)
		delete[] matrix[i];
	delete[] matrix;
}
void appr_matrix(int** matrix1, int** matrix2, int** matrix3, int** matrix4, int** matrix5, int n, int type) // Перегруженный метод для 4 матриц
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix1[i][j] = 0;
			for (int z = 0; z < n; z++)
			{
				switch (type)
				{
				case 1:
					matrix1[i][j] += (matrix2[i][z] + matrix3[i][z]) * (matrix4[z][j] + matrix5[z][j]);
					break;
				case 2:
					matrix1[i][j] += (matrix2[i][z] - matrix3[i][z]) * (matrix4[z][j] + matrix5[z][j]);
					break;
				}
			}
		}
	}
}
int** init_m(int type, int n, int m, int** arr)//Метод инициализации матрицы
{
	if (type == 1)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
	}
	else
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = rand() % 10;
	}
	return arr;
}
void align_border(int& x, int& s, int** matrix, int n, int type)
{
	switch (type)
	{
	case 1:
		for (int i = 0; i < n; i++)
		{
			x = 0;
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] != 0)
				{
					x++;
					s = 100;
				}
			}
			if (x == 0 && i < s)
				s = i;
		}
		break;
	case 2:
		for (int i = 0; i < n; i++)
		{
			x = 0;
			for (int j = 0; j < n; j++)
			{
				if (matrix[j][i] != 0)
				{
					x++;
					s = 100;
				}
			}
			if (x == 0 && i < s)
				s = i;
		}
		break;
	}
}
int main()
{
	srand(time(NULL));
	int n1, m1, n2, m2, k, l = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";
	//Ввод размера матрицы пользователем
	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> n1 >> m1;
	} while (n1 <= 0 || m1 <= 0);
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> n2 >> m2;
	} while (n2 <= 0 || m2 <= 0);
	int** matrix1 = create_m(n1, m1);
	int** matrix2 = create_m(n2, m2);
	//Выбор способа заполнения и заполнение матриц
	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> k;
	} while (k < 1 || k > 2);
	matrix1 = init_m(k, n1, m1, matrix1);
	matrix2 = init_m(k, n2, m2, matrix2);
	cout << "\nМатрица 1\n\n";
	print_m(n1, m1, matrix1);
	cout << "\nМатрица 2\n\n";
	print_m(n2, m2, matrix2);
	//Приведение матрицы к требуемому размеру
	while (l < n1 || l < n2 || l < m1 || l < m2)
		l *= 2;
	int** reduced_m1 = create_m(l);
	int** reduced_m2 = create_m(l);
	appr_matrix(reduced_m1, matrix1, n1, m1, 1);
	appr_matrix(reduced_m2, matrix2, n2, m2, 1);
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	print_m(l, l, reduced_m1);
	cout << "\nМатрица 2\n\n";
	print_m(l, l, reduced_m2);

	//Разбиение матриц на подматрицы и их заполнение
	int*** submatrices = new int** [8];
	for (int i = 0; i < 8; i++)
	{
		submatrices[i] = create_m(l / 2);
		if (i < 4)
			appr_matrix(submatrices[i], reduced_m1, l / 2, l / 2, (i % 4) + 1);
		else
			appr_matrix(submatrices[i], reduced_m2, l / 2, l / 2, (i % 4) + 1);
	}

	//Создание промежуточных матриц
	int*** inter_matrices = new int** [7];
	for (int i = 0; i < 7; i++)
		inter_matrices[i] = create_m(l / 2);

	//Вычисление значений промежуточных матриц
	appr_matrix(inter_matrices[0], submatrices[0], submatrices[3], submatrices[4], submatrices[7], l / 2, 1);
	appr_matrix(inter_matrices[1], submatrices[2], submatrices[3], submatrices[4], l / 2, 1);
	appr_matrix(inter_matrices[2], submatrices[0], submatrices[5], submatrices[7], l / 2, 2);
	appr_matrix(inter_matrices[3], submatrices[3], submatrices[6], submatrices[4], l / 2, 2);
	appr_matrix(inter_matrices[4], submatrices[0], submatrices[1], submatrices[7], l / 2, 1);
	appr_matrix(inter_matrices[5], submatrices[2], submatrices[0], submatrices[4], submatrices[5], l / 2, 2);
	appr_matrix(inter_matrices[6], submatrices[1], submatrices[3], submatrices[6], submatrices[7], l / 2, 2);

	//Создание вспомогательных матриц
	int*** auxiliary_matrices = new int** [4];
	for (int i = 0; i < 4; i++)
		auxiliary_matrices[i] = create_m(l / 2);

	//Подсчет значений вспомогательных матриц из промежуточных
	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			auxiliary_matrices[0][i][j] = inter_matrices[0][i][j] + inter_matrices[3][i][j] - inter_matrices[4][i][j] + inter_matrices[6][i][j];
			auxiliary_matrices[1][i][j] = inter_matrices[2][i][j] + inter_matrices[4][i][j];
			auxiliary_matrices[2][i][j] = inter_matrices[1][i][j] + inter_matrices[3][i][j];
			auxiliary_matrices[3][i][j] = inter_matrices[0][i][j] - inter_matrices[1][i][j] + inter_matrices[2][i][j] + inter_matrices[5][i][j];
		}
	}

	//Создание результрующей матрицы
	int** preResult_matrix = create_m(l);

	//Занесение информации из вспомогательных матриц в результирующую
	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			preResult_matrix[i][j] = auxiliary_matrices[0][i][j];
			preResult_matrix[i][j + l / 2] = auxiliary_matrices[1][i][j];
			preResult_matrix[i + l / 2][j] = auxiliary_matrices[2][i][j];
			preResult_matrix[i + l / 2][j + l / 2] = auxiliary_matrices[3][i][j];
		}
	}
	//Выравнивание границ результирующей матрицы
	int x = 0, f = 100, s = 100;
	align_border(x, f, preResult_matrix, l, 1);
	align_border(x, s, preResult_matrix, l, 2);

	//Создание и заполнение результирующей матрицы
	int** result_matrix = create_m(f, s);
	appr_matrix(result_matrix, preResult_matrix, f, s, 1);
	//Вывод результирующей матрицы
	cout << "\nРезультирующая матрица\n\n";
	print_m(f, s, result_matrix);
	system("pause");
	//Очистка динамической памяти
	delete_matrix(matrix1, n1);
	delete_matrix(matrix2, n2);
	delete_matrix(reduced_m1, l);
	delete_matrix(reduced_m2, l);
	delete_matrix(preResult_matrix, l);
	delete_matrix(result_matrix, f);
	for (int i = 0; i < 8; i++)
		delete_matrix(submatrices[i], l / 2);
	for (int i = 0; i < 4; i++)
		delete_matrix(auxiliary_matrices[i], l / 2);
	for (int i = 0; i < 7; i++)
		delete_matrix(inter_matrices[i], l / 2);
	return 0;
}
