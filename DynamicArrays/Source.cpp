#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3

#define delimiter "\n-----------------------------------------------------------\n"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);//��������� �������� � ������ �� ��������� �������
int* pop_back(int arr[], int& n);//������� ��������� ������� �������

int** allocate( const int rows, const int cols);
void clear(int** arr, const int rows);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int index);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
int** insert_col(int** arr, int& rows, int& cols,int index);
void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
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
	int** arr = allocate( rows, cols);
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
			arr = pop_col_front(arr, rows, cols);
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

	void FillRand(int arr[], const int n, int minRand, int maxRand)
	{
		//���������� � ��������� ������� �����
		for (int i = 0; i < n; i++)
		{
			//��������� ���������� ���������� � �������� �������������:
			*(arr + i) = rand() % (maxRand - minRand) + minRand;
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

	void Print(int arr[], const int n)
	{
		for (int i = 0; i < n; i++)
		{
			//��� �� ����� �������� ��������������[]:
			cout << arr[i] << "\t";
		}
	}
	void Print(int** arr, const int rows, const int cols)
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

	int* push_back(int arr[], int& n, int value)
	{
		//1) ������ �������� ������ ������� �������:
		int* buffer = new int[n + 1]{};
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
	int* insert(int arr[], int& n, int value, int index)
	{
		int* buffer = new int[n + 1]{};
		for (int i = 0; i < index; i++)buffer[i] = arr[i];
		for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
		delete[] arr;
		buffer[index] = value;
		n++;
		return buffer;
	}
	int* pop_back(int arr[], int& n)
	{
		n--;
		int* buffer = new int[n] {};
		for (int i = 0; i < n; i++)
		{
			buffer[i] = arr[i];
		}
		delete[] arr;
		arr = buffer;
		return buffer;
	}

	int** allocate( const int rows, const int cols)
	{
		int** arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols] {};
		}
		return arr;
	}
	void clear(int** arr, const int rows)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}

	int** push_row_back(int** arr, int& rows, const int cols)
	{
		//�������������� ������ ����������:
		//1)������� �������� ������ ����������, �������� �� 1 ������� ������:
		int** buffer = new int* [rows + 1]{};
		//2)�������� ����� ����� �� ��������� ������� ����������, � ��������: 
		for (int i = 0; i < rows; i++)
		{
			buffer[i] = arr[i];
		}
		//3)������� �������� ������ ����������:
		delete[] arr;
		//4)������� ����� ������ � ��������� �� ����� � ����� ������� ��������:
		buffer[rows] = new int [cols] {};
		//5)����� ����, ��� � ������ ���������� ������, ���-�� ��� ����� ����������� �� 1:
		rows++;
		//6)���������� ������ ������ ��  ����� ������:
		return buffer;
	}
	int** push_row_front(int** arr, int& rows, const int cols)
	{
		int** buffer = new int* [rows + 1]{};
		for (int i = 0; i < rows; i++)
		{
			buffer[i + 1] = arr[i];
		}
		delete[] arr;
		buffer[0] = new int[cols] {};
		rows++;
		return buffer;
	}
	int** insert_row(int** arr, int& rows, const int cols, int index)
	{
		--index;
		int** buffer = new int* [rows + 1]{};
		for (int i = 0; i < index; i++)
		{
			buffer[i] = arr[i];
		}
		for (int i = index; i < rows; i++)
		{
			buffer[i + 1] = arr[i];
		}
		delete[] arr;
		buffer[index] = new int[cols] {};
		rows++;
		return buffer;
	}
	int** pop_row_back(int** arr, int& rows, const int cols)
	{
		--rows;
		int** buffer = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			buffer[i] = arr[i];
		}
		delete[] arr[rows];//������� �� ������ ������
		delete[] arr;
		return buffer;
	}
	int** pop_row_front(int** arr, int& rows, const int cols)
	{
		--rows;
		int** buffer = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			buffer[i] = arr[i + 1];
		}
		delete[] arr[0];
		delete[] arr;
		return buffer;
	}
	int** erase_row(int** arr, int& rows, const int cols, int index)
	{
		--rows;
		int** buffer = new int* [rows] {};
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

	void push_col_back(int** arr, const int rows, int& cols)
	{
		for (int i = 0; i < rows; i++)
		{
			int* buffer = new int[cols + 1]{};
			for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
			delete[] arr[i];
			arr[i] = buffer;
		}
		cols++;
	}
	void push_col_front(int** arr, const int rows, int& cols)
	{
		for (int i = 0; i < rows; i++)
		{
			int* buffer = new int[cols + 1]{};
			for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
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
				buffer[i][j+1] = arr[i][j];
			}
			delete[] arr[i];
		}
		delete[] arr;
		cols++;
		return buffer;
	}
	void pop_col_back(int** arr, const int rows, int& cols)
	{
		for (int i = 0; i < rows; i++)
		{
			int* buffer = new int[cols - 1];
			for (int j = 0; j < cols-1; j++)buffer[j] = arr[i][j];
			delete[] arr[i];
			arr[i] = buffer;
		}
		cols--;
	}
	void pop_col_front(int** arr, const int rows, int& cols)
	{
		for (int i = 0; i < rows; i++)
		{
			int* buffer = new int[cols - 1];
			for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
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
			for (int j = index-1; j < cols; j++)
			{
				buffer[i][j] = arr[i][j+1];
			}
			delete[] arr[i];
		}
		delete[] arr;
		cols--;
		return buffer;
	}