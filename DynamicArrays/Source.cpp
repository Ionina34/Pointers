#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3

#define delimiter "\n-----------------------------------------------------------\n"

template<typename T>T** allocate(const int rows, const int cols);
template<typename T>void clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* insert(T arr[], int& n, T value, int index);//��������� �������� � ������ �� ��������� �������
template<typename T>T* pop_back(T arr[], int& n);//������� ��������� ������� �������

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);
int** insert_col(int** arr, int& rows, int& cols, int index);
template<typename T>void pop_col_back(T** arr, const int rows, int& cols);
template<typename T>void pop_col_front(T** arr, const int rows, int& cols);
int** erase_col(int** arr, int& rows, int& cols, int index);

void main()
{
	cout << int() << endl;//������� �������� �� ��������� ��� ���� ������ 'int'
	setlocale(LC_ALL, "RUS");

#ifdef DYNAMIC_MEMORY_1
	int n; //������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};


	FillRand(arr, n);
	Print(arr, n);

	//�������� �������� � ����� �������:
	cout << "\n";
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ����������� ��������: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DINAMYC_MEMORY_2
	int rows;//���������� �����
	int cols;//���������� ��������� � ������
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	//���������� ���������� ������������� �������:
	//1)Co����� ������ ����������:
	int** arr = new int* [rows] {};
	//2)������� ������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	//������������� ���������� ������������� �������:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//�������� ���������� ������������� �������:
	//1)������� ������:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2)������� ������ ����������:
	delete[] arr;
#endif // DINAMYC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3
	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 200, 1000);
	Print(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif // DYNAMIC_MEMORY_3

	int rows;
	int cols;
	int s;
	int index;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = allocate<int>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "�������� ���� �����:\n1-rows;\n2-cols." << endl; cin >> s;
	switch (s)
	{
	case 1:
		cout << "�������� ���� �����:\n1-�������� ������� � �����;\n2-�������� ������� � ������;\n3-�������� ������� �� �������;\n4-������� ��������� �������;\n5-������� ������� � ������:\n6-������� ������� �� �������." << endl; cin >> s;
		switch (s)
		{
		case 1:
			cout << delimiter << endl;
			arr = push_row_back(arr, rows, cols);
			FillRand(arr[rows - 1], cols, 200, 1000);
			Print(arr, rows, cols); break;
		case 2:
			cout << delimiter << endl;
			arr = push_row_front(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 3:
			cout << delimiter << endl;
			cout << "������ ����������� ������: "; cin >> index;
			arr = insert_row(arr, rows, cols, index);
			Print(arr, rows, cols); break;
		case 4:
			cout << delimiter << endl;
			arr = pop_row_back(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 5:
			cout << delimiter << endl;
			arr = pop_row_front(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 6:
			cout << delimiter << endl;
			cout << "����� ������� ������ �������:"; cin >> index;
			arr = erase_row(arr, rows, cols, index);
			Print(arr, rows, cols); break;
		}break;
	case 2:
		cout << "�������� ���� �����:\n1-������� ������� � �����;\n2-�������� ������� � ������;\n3-�������� ������� �� �������;\n4-������� ��������� �������;\n5-������� ������ �������;\n6-������� ������� �� �������." << endl; cin >> s;
		switch (s)
		{
		case 1:
			cout << delimiter << endl;
			push_col_back(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 2:
			cout << delimiter << endl;
			push_col_front(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 3:
			cout << delimiter << endl;
			cout << "������ ������������ ������� : "; cin >> index;
			arr = insert_col(arr, rows, cols, index);
			Print(arr, rows, cols); break;
		case 4:
			cout << delimiter << endl;
			pop_col_back(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 5:
			cout << delimiter << endl;
			pop_col_front(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 6:
			cout << delimiter << endl;
			cout << "������ ���������� �������: "; cin >> index;
			arr = erase_col(arr, rows, cols, index);
			Print(arr, rows, cols); break;
		default:cout << "��������" << endl;
		}break;
	default:cout << "��������" << endl;
	}
	clear(arr, rows);
}

template<typename T>T** allocate(const int rows, const int cols)
{
	T** arr = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}
template<typename T>void clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	//���������� � ��������� ������� �����
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	//���������� � ��������� ������� �����
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������:
		*(arr + i) = rand();
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand = 0;
	maxRand = 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] / 100;
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��� �� ����� �������� ��������������[]:
		cout << arr[i] << "\t";
	}
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T>T* push_back(T arr[], int& n, T value)
{
	//1) ������ �������� ������ ������� �������:
	T* buffer = new T[n + 1]{};
	//2) ��������� ��� ��������� �� ��������� ������� � ��������.
	//�������� �������� ������ � �������� �������������: 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������:
	delete[] arr;
	//4)��������� ������ ������ �� �����:
	arr = buffer;
	//5)������ ����� ����� �����, ����� �������� �������� � ����� �������,
	//��������� � ����� ������� �������� �������, �  ������� ����� ��������� ��������: 
	arr[n] = value;
	//6)����� ���������� �������� � ������, ����-�� ��� ��������� ������������� �� 1:
	n++;
	return arr;
}
template<typename T>T* insert(T arr[], int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}
template<typename T>T* pop_back(T[], int& n)
{
	n--;
	T* buffer = new T[n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	//�������������� ������ ����������:
	//1)������� �������� ������ ����������, �������� �� 1 ������� ������:
	T** buffer = new T * [rows + 1]{};
	//2)�������� ����� ����� �� ��������� ������� ����������, � ��������: 
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������ ����������:
	delete[] arr;
	//4)������� ����� ������ � ��������� �� ����� � ����� ������� ��������:
	buffer[rows] = new T[cols]{};
	//5)����� ����, ��� � ������ ���������� ������, ���-�� ��� ����� ����������� �� 1:
	rows++;
	//6)���������� ������ ������ ��  ����� ������:
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new T[cols]{};
	rows++;
	return buffer;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	--index;
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new T[cols]{};
	rows++;
	return buffer;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	--rows;
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows];//������� �� ������ ������
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	--rows;
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
	--rows;
	T** buffer = new T * [rows] {};
	//--index;
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[index];
	delete[] arr;
	return buffer;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
int** insert_col(int** arr, int& rows, int& cols, int index)
{
	--index;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	cols++;
	return buffer;
}
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
int** erase_col(int** arr, int& rows, int& cols, int index)
{
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index - 1; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}
	delete[] arr;
	cols--;
	return buffer;
}