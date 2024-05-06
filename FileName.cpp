#include <iostream>
#include <cstdlib>

using namespace std;
const int ROW = 2, COL = 10, Z=5 ;
//функции первого задания
int rec_func(int arr[], int sum[], int &size);

void fill_rec(int arr[], int SIZE);

void Min(int sum[], int size, int arr[]);

//функции второго задания
int Max(int arr[], int size);

int Max( int (&arr)[ROW][COL], int size_i, int size_j);

int Max(int(&arr)[ROW][COL][Z], int size_x, int size_y, int size_z);

int Max(int num_1, int num_2);

int Max(int num_1, int num_2, int num_3);

int main() {
	setlocale(LC_ALL, "ru");
	const int SIZE = 100;
	int arr[SIZE];
	int mass_i[ROW][COL];
	int mass_xyz[ROW][COL][Z];
	fill_rec(arr, SIZE);//1 задание
	cout << endl;
	cout << "Max: ";
	cout<<Max(7,5,0);


	return 0;
}
//функции первого задания
int rec_func(int arr[], int sum[], int &size)
{
	
	if (size == 82) {//конец
		
		Min(sum, size, arr);

		return 0;
	}


	for (int i = size; i < size+10; i++)
	{
		sum[i] = arr[i] + arr[i+1] + arr[i + 2] + arr[i + 3] + arr[i + 4] +
			arr[i + 5] + arr[i + 6] + arr[i + 7] + arr[i + 8] + arr[i + 9];
		
	}
	

	size++;



	rec_func(arr, sum, size);
	

	
}//1 задание//1 задание

void fill_rec(int arr[], int SIZE)//1 задание
{
	srand(time(NULL));
	int sum[100];
	int size = 0;
	for (int i = 0; i < SIZE; i++)
	{

		arr[i] = rand() % 201 - 100;
		//cout << arr[i] << " ";

	}
	cout << endl;
	rec_func(arr, sum, size);
}//1 задание

void Min(int sum[], int size, int arr[])
{	
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		//cout << " " << sum[i];
	}
	int min = sum[0];
	int index = 0;
	int mass_min[10];
	for (int i = 0; i < size; i++)
	{
		if (sum[i] < min)
		{
			min = sum[i];
		}
	}

	//cout <<endl<< "Минимальное число: " << min << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (sum[i] == min){
			index = i;
		}
	}
	//cout << "Индекс числа: " << index<<endl;
	cout << "Последовательность самой маленькой суммы всех чисел массива: ";
	for (int i = index; i < index+10; i++)
	{
		mass_min[i] = arr[i];
		cout << mass_min[i] << " ";
	}
	cout << endl;
}
int Max(int arr[], int size)
{
	int max = arr[0];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{

		arr[i] = rand() % 201 - 100;
		//cout << arr[i] << " ";

	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;


	return 0;
}

//я не нашел как передавать двумерный массив в функцию с нужными мне размерами без глобальных переменных
int Max(int (& arr)[ROW][COL], int size_i, int size_j)
{
	int max = -25551215;
	srand(time(NULL));
	cout << endl;
	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			arr[i][j] = rand() % 201 - 100;

		}
	

	}
	for (int i = 0; i < size_i; i++)//столбцы
	{
		for (int j = 0; j < size_j; j++)//строки
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}


	return max;

}

int Max(int(&arr)[ROW][COL][Z], int size_x, int size_y, int size_z)
{
	int max = -25551215;
	cout << endl;
	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			for (int z = 0; z < size_z; z++)
			{
				arr[x][y][z] = rand() % 201 - 100;

			}
		}
	}
	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			for (int z = 0; z < size_z; z++)
			{
				cout << arr[x][y][z] << " ";

			}
			cout << endl;
		}
		cout << endl;
	}

	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			for (int z = 0; z < size_z; z++)
			{
				if (arr[x][y][z] > max) {
					max = arr[x][y][z];
				}

			}
		}
	}


	return max;
}

int Max(int num_1, int num_2)
{
	int max = num_1;

	if (max<num_1)
	{
		max = num_1;
	}
	else {
		max = num_2;
	}


	return max;
}
int Max(int num_1, int num_2, int num_3)
{
	int max = num_1;//7

	if (max <= num_1 && max > num_2 && max> num_3)
	{
		max = num_1;
	}
	else if (max<num_2 && max>=num_1 && max > num_3) {
		max = num_2;
	}
	else {
		max = num_3;
	}

	return max;
}
