#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3

#define delimiter "\n-----------------------------------------------------------\n"

int** allocate(const int rows, const int cols);
void clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);//Вставляет значение в строку по заданному индексу
int* pop_back(int arr[], int& n);//Удаляет последний элемент массива

void push_row_back(int**& arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int index);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
int** insert_col(int** arr, int& rows, int& cols, int index);
void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
int** erase_col(int** arr, int& rows, int& cols, int index);

void main()
{
	cout << int() << endl;//Выводим значение по умолчанию для типа данных 'int'
	setlocale(LC_ALL, "RUS");

#ifdef DYNAMIC_MEMORY_1
	int n; //Размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};


	FillRand(arr, n);
	Print(arr, n);

	//Добавить значение в конец массива:
	cout << "\n";
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите добавляемое значение: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DINAMYC_MEMORY_2
	int rows;//Количество строк
	int cols;//Количество элементов в строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	//Объявление двумерного динамического массива:
	//1)Coздаем массив указателей:
	int** arr = new int* [rows] {};
	//2)Создаем строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	//Использование двумерного динамического массива:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//Удаление двумерного динамического массива:
	//1)Удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2)Удаляем массив указателей:
	delete[] arr;
#endif // DINAMYC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
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
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Сделайте свой выбор:\n1-rows;\n2-cols." << endl; cin >> s;
	switch (s)
	{
	case 1:
		cout << "Сделайте свой выбор:\n1-Добавить строчку в конец;\n2-Добавить строчку в начало;\n3-Добавить строчку по индексу;\n4-Удалить последнюю строчку;\n5-Удалить строчку в начале:\n6-Удалить строчку по индексу." << endl; cin >> s;
		switch (s)
		{
		case 1:
			cout << delimiter << endl;
			push_row_back(arr, rows, cols);
			FillRand(arr[rows - 1], cols, 200, 1000);
			Print(arr, rows, cols); break;
		case 2:
			cout << delimiter << endl;
			arr = push_row_front(arr, rows, cols);
			Print(arr, rows, cols); break;
		case 3:
			cout << delimiter << endl;
			cout << "Индекс добавляемой строки: "; cin >> index;
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
			cout << "Какую строчку хотите удалить:"; cin >> index;
			arr = erase_row(arr, rows, cols, index);
			Print(arr, rows, cols); break;
		}break;
	case 2:
		cout << "Сделайте свой выбор:\n1-Добавть столбец в конец;\n2-Добавить столбец в начало;\n3-Добавить столбец по индексу;\n4-Удалить последний столбец;\n5-Удалить первый столбец;\n6-Удалить столбец по индексу." << endl; cin >> s;
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
			cout << "Индекс добавляемого столбца : "; cin >> index;
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
			cout << "Индекс удаляемого столбца: "; cin >> index;
			arr = erase_col(arr, rows, cols, index);
			Print(arr, rows, cols); break;
		default:cout << "ОШИБОЧКА" << endl;
		}break;
	default:cout << "ОШИБОЧКА" << endl;
	}
	clear(arr, rows);
}

int** allocate(const int rows, const int cols)
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

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	//Обращаться к элементам массива можно
	for (int i = 0; i < n; i++)
	{
		//Используя арифметику указателей и оператор разыменования:
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
		//или же через оперетор индексирования[]:
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
	//1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1]{};
	//2) Переносим все значенияя из исходного массива в буферный.
	//Копируем исходный массив в буферный СООТВЕСТВЕННО: 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив:
	delete[] arr;
	//4)Подменяем старый массив на новый:
	arr = buffer;
	//5)Только после всего этого, можно добавить значение в конце массива,
	//посколько в конце массива появился элемент, в  который можно сохранить значение: 
	arr[n] = value;
	//6)После добавления элемента в массив, коль-во его элементов увеличивается на 1:
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


void push_row_back(int**& arr, int& rows, const int cols)
{
	//Переопределяем массив указателей:
	//1)Создаем буфкрный массив указателей, размером на 1 элемент больше:
	int** buffer = new int* [rows + 1]{};
	//2)Копируем адрес строк из исходного массива указателей, в буферный: 
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив указалетей:
	delete[] arr;
	//4)Создаем новую строку и добавляем ее адрем в конец массива указатей:
	buffer[rows] = new int [cols] {};
	//5)После того, как в массив добавилась строка, кол-во его строк увеличилось на 1:
	rows++;
	//6)Возвращаем ногвый массив на  место вызова:
	arr = buffer;
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
	delete[] arr[rows];//Удаляем из памяти строку
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
void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
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