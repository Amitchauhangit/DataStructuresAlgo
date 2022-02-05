#include <iostream>

#include <math.h>


int getMid(int s, int e) { return s + (e - s) / 2; }

using namespace std;
void print(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;

}

int STconstructUtil(int arr[], int ss, int se, int* st, int index)
{
	if (ss == se)
	{
		st[index] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);


	 st[index] = STconstructUtil(arr, ss, mid, st, 2 * index + 1) + STconstructUtil(arr, mid + 1, se, st, 2*index + 2);

	 return st[index];

}
int* STconstruct(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	
	int size = 2 * (int)pow(2, x) - 1;

	int* st = new int[size];

	int a = STconstructUtil(arr, 0, n - 1, st, 0);
	
	cout << "Segment tree -> ";
	print(st, size);

	return st;
	//0 , n-1 -> range for sum , st-> empty segment tree & 0 is the root index -> all ele sum.
}


int getSumUtil(int* st, int ss, int se, int qs, int qe, int index)
{
	if (qs <= ss && qe >= se)
	{
		return st[index];
	}

	if (qs > se || qe < ss)
	{
		return 0;
	}

	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2 * index + 1) + getSumUtil(st, mid + 1, se, qs, qe, 2 * index + 2);

}

int getsum(int* arr, int n, int qs, int qe)
{
	if (qs<0 || qe>n - 1 || qs > qe)
	{
		return -1;
	}

	return getSumUtil(arr, 0, n - 1, qs, qe, 0);

}

void updateValueUtil(int *st, int ss, int se, int i,int diff){

	if (i > se || i < ss)
	{
		return;
	}

	st[i] += diff;
	
	if (ss < se)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, 2 * i + 1, diff);
		updateValueUtil(st, mid + 1, se, 2 * i + 2, diff);
	}
}

void updateValue(int arr[], int* st, int n, int i, int value)
{
	if (i<0 || i>n)
	{
		return;
	}

	int diff = value - arr[i];
	arr[i] = value;

	updateValueUtil(st, 0, n - 1, 0, diff);
	
}

int main()
{
//Construct.
	int arr[] = { 1, 3, 5, 7, 9, 11 };
	int n = sizeof(arr) / sizeof(int);
	
	cout << "Input -> ";
	print(arr, n);
	

	int x = (int)(ceil(log2(n)));

	int size = 2 * (int)pow(2, x) - 1;

	
	int * st = STconstruct(arr, n);


	cout << getsum(st, n, 2, 4);

	updateValue(arr, st, n, 4, 100);

	cout << sizeof(st) << endl;

	cout << "Segment tree -> ";
	print(st, size);


	delete [] st;


}
