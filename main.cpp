#include <iostream>

using namespace std;

void get(int arr[], int);
void MergeSorting(int arr[], int);
void split(int arr[], int, int);
void merge(int arr[], int, int, int);
void print(int arr[], int);

int main()
{
	int arr[100], size;

	cout << "Size = ";
	cin >> size;

	cout << "\nEnter the numbers of the array : \n\n";
	get(arr, size);

	MergeSorting(arr, size);

	cout << "\nThe sorted array :\n\n";

	print(arr, size);
}

void get(int arr[], int count)
{
	for (int x = 0; x < count; x++)
	{
		cout << x + 1 << " - ";
		cin >> arr[x];
	}
}

void print(int arr[], int size)
{
	for (int x = 0; x < size; x++)
		cout << x + 1 << " : " << arr[x] << "\n";
}

void MergeSorting(int arr[], int size)
{
	split(arr, 0, size - 1);
}

void split(int arr[], int from, int to)
{
	if (from < to)
	{
		int middle = (to + from) / 2;
		split(arr, from, middle);
		split(arr, middle + 1, to);
		merge(arr, from, middle, to);
	}
}

void merge(int arr[], int from, int middle, int to)
{
	int temp[100];
	int index = from;
	int rightpointer = from;
	int leftpointer = middle + 1;

	for (; rightpointer <= middle  && leftpointer <= to; )
	{
		if (arr[rightpointer] < arr[leftpointer])
		{
			temp[index] = arr[rightpointer];
			index++;
			rightpointer++;
		}
		else
		{
			temp[index] = arr[leftpointer];
			index++;
			leftpointer++;
		}
	}
	for (; rightpointer <= middle;)
	{
		temp[index] = arr[rightpointer];
		index++;
		rightpointer++;
	}
	for (; leftpointer <= to;)
	{
		temp[index] = arr[leftpointer];
		index++;
		leftpointer++;
	}
	for (int x = from; x <= to; x++)
		arr[x] = temp[x];
}