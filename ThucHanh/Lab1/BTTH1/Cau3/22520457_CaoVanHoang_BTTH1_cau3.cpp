#include <iostream>
#include <ctime>
using namespace std;
void HeapSort(int  arr[], int n);
void BuildHeap(int arr[], int n);
void Heapify(int arr[], int i, int heap_size);
void merge(int a[], int l, int m, int r);
void MergeSort(int a[], int l, int r);


void InterchangeSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
}

void HeapSort(int arr[], int n) {
	BuildHeap(arr, n);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		Heapify(arr, 0, i);
	}
}

void BuildHeap(int arr[], int n) {

	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, i, n);
	}
}
void Heapify(int  arr[], int i, int heap_size) {
	int root = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	if (left<heap_size && arr[left]>arr[root])
	{
		root = left;
	}
	if (right<heap_size && arr[right] >arr[root])
	{
		root = right;
	}
	if (root != i) {

		swap(arr[root], arr[i]);
		Heapify(arr, root, heap_size);
	}
}

void QuickSort(int arr[], int left, int right) {
	int p = arr[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (arr[i] < p)
		{
			i++;
		}
		while (arr[j] > p)
		{
			j--;
		}
		if (i <= j) {
			swap(arr[i++], arr[j--]);
		}
	}
	if (i < right) {
		QuickSort(arr, i, right);
	}
	if (j > left) {
		QuickSort(arr, left, j);
	}
}


void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
void merge(int  arr[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + 1 + j];
	}
	i = j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		arr[k++] = L[i] <= R[j] ? L[i++] : R[j++];
	}
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		arr[k++] = R[j++];
	}
	delete[]R;
	delete[]L;
}

void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min] > arr[j])
				min = j;
		}
		if (min != i)
			swap(arr[min], arr[i]);
	}
}

void InsertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int vt = i - 1;
		int x = arr[i];
		for (; vt >= 0 && arr[vt] > x; vt--)
			arr[vt + 1] = arr[vt];
		arr[vt + 1] = x;
	}
}


void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
int main() {
	int n;
	cin >> n;
	int* a1 = new int[n], * a2 = new int[n], * a3 = new int[n], * a4 = new int[n], * a5 = new int[n], * a6 = new int[n], * a7 = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 201 - 100;
		a1[i] = a2[i] = a3[i] = a4[i] = a5[i] = a6[i] = x;
	}
	clock_t st, ed;
	float time_use;
	st = clock();
	InterchangeSort(a1, n);
	ed = clock();
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "InterchangeSort :" << time_use << endl;

	st = clock();
	InsertionSort(a2, n);
	ed = clock();

	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "InsertionSort :" << time_use << endl;

	st = clock();
	BubbleSort(a3, n);
	ed = clock();

	cout << endl;
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "BubbleSort :" << time_use << endl;

	st = clock();
	SelectionSort(a7, n);
	ed = clock();
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "Selection: " << time_use << endl;

	st = clock();
	QuickSort(a4, 0, n - 1);
	ed = clock();
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "QuickSort :" << time_use << endl;

	st = clock();
	MergeSort(a5, 0, n - 1);
	ed = clock();
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "MergeSort :" << time_use << endl;

	st = clock();
	HeapSort(a6, n);
	ed = clock();
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "HeapSort :" << time_use << endl;

	delete[]a1;
	delete[]a2;
	delete[]a3;
	delete[]a4;
	delete[]a5;
	delete[]a6;
	delete[]a7;
	return 0;
}